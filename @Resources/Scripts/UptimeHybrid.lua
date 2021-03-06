function Initialize()
	-- Use Skin Uptime instead of reboot
	time = os.time()
end

function pad2(num)
	local str = tostring(num)
	return #str > 1 and str or '0' .. str
end

function Update()

	local diff = os.difftime(os.time(), time)
	local hours = math.floor(diff / 3600)
	local mins = math.floor((diff - hours * 3600) / 60)
	local secs = math.floor(diff - hours * 3600 - mins * 60)

	return(hours .. "h " .. pad2(mins) .. "m " .. pad2(secs) .. "s")
end
