ORGANIZER_SKIN_NAME = 'Settings'
ORGANIZER_MARKER_SKIN_NAME = 'OrganizerMarker'

isOrganizerSkin = false
hasInitialized = false
hasUpdated = false
boundingRects = {}
options = nil

function Initialize()
	-- Run only on organizer skin
	isOrganizerSkin = SKIN:GetVariable('CURRENTCONFIG', '') == SKIN:GetVariable('ROOTCONFIG', '') .. '\\' .. ORGANIZER_SKIN_NAME
	if not isOrganizerSkin then
		return
	end
	
	-- Read options
	local organizer = SKIN:GetVariable('Organizer', 'None');
	local organizerOpts = {organizer:match('(%d+),([UD]),([LR])')};
	if organizerOpts[1] == nil then
		return
	end
	
	-- Parse options
	options = {
		gap = tonumber(organizerOpts[1]) * tonumber(SKIN:GetVariable('Multiplier', '1')),
		isUpwards = organizerOpts[2] == 'U',
		isLeftwards = organizerOpts[3] == 'L'
	}
end

function Update()
	if options == nil then
		return
	end
	
	if not hasInitialized then
		hasInitialized = true
		return
	end
	
	-- Run only on second update
	if not isOrganizerSkin or hasUpdated then
		return
	end
	
	hasUpdated = true
	
	-- Get bounding rect
	GetBoundingRectOfAll()
	
	-- Get bounding rect of marker
	local markerKey = SKIN:GetVariable('ROOTCONFIG', '') .. '\\' .. ORGANIZER_MARKER_SKIN_NAME
	local markerRect = boundingRects[markerKey]
	boundingRects[markerKey] = nil
	
	-- Group by columns
	local columns = groupByColumns(boundingRects)
	
	-- Sort each columns
	local columnsSorted = table.map(columns, function(column)
		local columnSorted = table.copy(column)
		table.sort(columnSorted, function(i, j) return boundingRects[i].y < boundingRects[j].y end)
		return columnSorted
	end)
	
	-- Reverse if needed
	if options.isLeftwards then
		columnsSorted = table.reverse(columnsSorted)
	end
	
	if options.isUpwards then
		columnsSorted = table.map(columnsSorted, function(column) return table.reverse(column) end)
	end
	
	-- Organize
	organizeSkins(columnsSorted, markerRect.x, markerRect.y)
	
	-- Cleanup
	SKIN:Bang('!WriteKeyValue', 'Variables', 'OrganizerEnabled', 0, SKIN:GetVariable('@') .. 'Variables.inc')
end

-- Utilities
function groupByColumns(elements)
	if next(elements) == nil then
		return {}
	end
	
	-- Find leftmost value
	local firstKey, firstBoundingBox = next(elements)
	local leftmostItem = elements[table.reduce(
		elements,
		function(prev, value, key)
			if prev.x > value.x then
				return { key = key, x = value.x }
			end
			
			return prev
		end,
		{ key = firstKey, x = firstBoundingBox.x }
	).key]
	
	-- Find column items
	local column = table.keys(table.filter(
		elements,
		function(value)
			return value.x >= leftmostItem.x and value.x < (leftmostItem.x + leftmostItem.w)
		end
	))
	
	local remainder = table.copy(elements)
	table.foreach(column, function(key) remainder[key] = nil end)
	
	-- Recursively build columns
	local columns = groupByColumns(remainder)
	return { column, unpack(columns) }
end

function organizeSkins(columns, x, y)
	local columnX = x
	for _, column in ipairs(columns) do
		local rowY = y
		local maxW = 0
		
		for _, key in ipairs(column) do
			placeSkin(key, columnX, rowY)
			
			rowY = rowY + (options.isUpwards and -1 or 1) * (boundingRects[key].h + options.gap)
			maxW = math.max(maxW, boundingRects[key].w)
		end
		
		columnX = columnX + (options.isLeftwards and -1 or 1) * (maxW + options.gap)
	end
end

function placeSkin(key, x, y)
	local skinX = x + (options.isLeftwards and -1 or 0) * boundingRects[key].w
	local skinY = y + (options.isUpwards and -1 or 0) * boundingRects[key].h
	SKIN:Bang('!Move', skinX, skinY, key)
end

-- Callbacks
function GetBoundingRectOfAll()
	local root = SKIN:GetVariable('ROOTCONFIG', '')
	SKIN:Bang('!CommandMeasure', 'MeasureOrganizer', 'OnGetBoundingRect()', '*')
end

function OnGetBoundingRect()
	local root = SKIN:GetVariable('ROOTCONFIG', '')
	local self = SKIN:GetVariable('CURRENTCONFIG', '')
	local args = { SKIN:GetX(), SKIN:GetY(), SKIN:GetW(), SKIN:GetH() }
	
	local escapedName = '\'' .. self:gsub('\\', '\\\\') .. '\''
	
	SKIN:Bang(
		'!CommandMeasure',
		'MeasureOrganizer',
		'OnGetBoundingRectCallback(' .. escapedName .. ', ' .. table.concat(args, ', ') .. ')',
		root .. '\\' .. ORGANIZER_SKIN_NAME
	)
end

function OnGetBoundingRectCallback(target, x, y, w, h)
	boundingRects[target] = { x = x, y = y, w = w, h = h }
end

-- Helpers
function table.copy(t)
  local u = { }
  for k, v in pairs(t) do u[k] = v end
  return u
end

function table.keys(t)
	local u = { }
	local n = 0
	for k, v in pairs(t) do
		n = n + 1
		u[n] = k
	end
	
	return u
end

function table.map(t, f)
	local u = { }
	for k, v in pairs(t) do u[k] = f(v, k) end
	return u
end

function table.reduce(t, f, i)
	local prev = i
	for k, v in pairs(t) do prev = f(prev, v, k) end
	return prev
end

function table.foreach(t, f)
	for k, v in pairs(t) do f(v, k) end
end

function table.filter(t, f)
	local u = { }
	for k, v in pairs(t) do if f(v, k) then u[k] = v end end
	return u
end

function table.reverse(t)
	local u = { }
	for k, v in ipairs(t) do u[1 - k + #t] = v end
	return u
end