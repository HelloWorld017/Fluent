function Initialize()
	local measureName = SELF:GetOption('MeasureName')
	measure = SKIN:GetMeasure(measureName)
	total = 0
end

function Update()
	total = total + measure:GetValue()

	return total
end
