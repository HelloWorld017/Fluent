function Initialize()
	TargetMeasure = SELF:GetOption("TargetMeasure")
	StringType = SELF:GetOption("StringType")
	
	OrderCount = SELF:GetNumberOption("OrderCount")
	Measures = {}
	
	for i = 1, OrderCount do
		table.insert(Measures, getMeasureTable(SELF:GetOption("Order" .. i)))
	end
end

function Update()
	order, measureName = getEnabledPlayer()
	
	if order == nil then
		order = #Measures
	end
	
	if StringType ~= 0 then
		return Measures[order].Target:GetStringValue()
	end
	
	return Measures[order].Target:GetValue()
end

function Execute(commandName)
	order, measureName = getEnabledPlayer()
	if measureName == nil then return end
	
	SKIN:Bang('[!CommandMeasure ' .. measureName .. 'MeasureState ' .. commandName .. ']')
end

function getMeasureTable(measureName)
	return {
		Name	= measureName,
		State	= SKIN:GetMeasure(measureName .. "MeasureState"),
		Target	= SKIN:GetMeasure(measureName .. "Measure" .. TargetMeasure)
	}
end

function getEnabledPlayer()
	for order, measure in ipairs(Measures) do
		if measure.State:GetValue() == 1 then
			return order, measure.Name
		end
	end
	
	return nil, nil
end
