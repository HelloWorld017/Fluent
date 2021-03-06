function Initialize()
	local source = SELF:GetOption('Source')
	sourceMeasure = SKIN:GetMeasure(source)
	json = dofile(SKIN:GetVariable('@') .. 'Scripts\\JSON.lua')
end

function Update()
	local currentString = sourceMeasure:GetStringValue()
	successful, hwMonitor = pcall(json.decode, currentString)

	if not successful then
		return "0,0,0"
	end

	sensors = hwMonitor['Children']

	if sensors == nil or sensors[1] == nil or sensors[1]['Children'] == nil then
		return "0,0,0"
	end

	info = {0, 0, 0}

	computer = sensors[1]['Children']

	for i, component in ipairs(computer) do
		componentImg = component['ImageURL']
		componentType = nil

		if componentImg:match('cpu') then
			componentType = 1
		elseif componentImg:match('nvidia') or componentImg:match('ati') then
			componentType = 2
		elseif componentImg:match('hdd') then
			componentType = 3
		end

		if componentType ~= nil then
			temperatures = {}
			temperatureMax = info[componentType] ~= nil and info[componentType] or 0

			for j, child in ipairs(component['Children']) do
				if child['Text'] == 'Temperatures' then
					temperatures = child['Children']
					break
				end
			end

			for k, temp in ipairs(temperatures) do

				parsedTemp = tonumber(temp['Value']:match("^[0-9.]+"))
				if parsedTemp ~= nil and temperatureMax < parsedTemp then
					temperatureMax = parsedTemp
				end
			end

			info[componentType] = temperatureMax
		end
	end

	return table.concat(info, ',')
end
