function Initialize()
	local measureName = SELF:GetOption('MeasureName')
	stringMeasure = SKIN:GetMeasure(measureName)
end

function Update()
	local currentString = stringMeasure:GetStringValue()

	-- Watch out for Zero-width space!!
	return currentString:gsub("(.)", "%1​")
end
