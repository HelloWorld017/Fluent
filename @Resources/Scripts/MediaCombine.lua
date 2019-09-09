function Initialize()
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
	
	targetMeasure = Measures[order]
	
	SKIN:Bang('!SetVariable', 'VariableState', targetMeasure.State:GetValue())
	SKIN:Bang('!SetVariable', 'VariableTrack', targetMeasure.Track:GetStringValue());
	SKIN:Bang('!SetVariable', 'VariableArtist', targetMeasure.Artist:GetStringValue());
	SKIN:Bang('!SetVariable', 'VariableCover', targetMeasure.Cover:GetStringValue());
	SKIN:Bang('!SetVariable', 'VariablePosition', targetMeasure.Position:GetStringValue());
	SKIN:Bang('!SetVariable', 'VariableDuration', targetMeasure.Duration:GetStringValue());
	SKIN:Bang('!SetVariable', 'VariableProgress', targetMeasure.Progress:GetValue());
	
	if StringType ~= 0 then
		return Measures[order].Target:GetStringValue()
	end
	
	return Measures[order].Target:GetValue()
end

function Execute(commandName)
	order, measureName = getEnabledPlayer()
	if measureName == nil then return end
	
	SKIN:Bang('!CommandMeasure', measureName .. 'MeasureState', commandName)
end

function getMeasureTable(measureName)
	return {
		Name		= measureName,
		State		= SKIN:GetMeasure(measureName .. "MeasureState"),
		Track		= SKIN:GetMeasure(measureName .. "MeasureTrack"),
		Artist		= SKIN:GetMeasure(measureName .. "MeasureArtist"),
		Cover		= SKIN:GetMeasure(measureName .. "MeasureCover"),
		Position	= SKIN:GetMeasure(measureName .. "MeasurePosition"),
		Duration	= SKIN:GetMeasure(measureName .. "MeasureDuration"),
		Progress	= SKIN:GetMeasure(measureName .. "MeasureProgress")
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
