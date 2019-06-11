-- This should be encoded in UCS-2 LE in order to handle unicode

function Initialize()
	local measureName = SELF:GetOption('MeasureName')
	stringMeasure = SKIN:GetMeasure(measureName)
	zwsp = string.char(226, 128, 139)
end

function Update()
	local currentString = stringMeasure:GetStringValue()

	-- Match unicode character and add ZWSP
	return currentString:gsub("([%z\1-\127\194-\244][\128-\191]*)", "%1" .. zwsp)
end
