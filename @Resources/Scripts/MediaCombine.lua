function Initialize()
	StringType = SELF:GetOption("StringType")
	OrderCount = SELF:GetNumberOption("OrderCount")
	TitleMaxLength = SELF:GetNumberOption("MaxLength")
	zwsp = string.char(226, 128, 139)
	
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
	SKIN:Bang('!SetVariable', 'VariableArtist', targetMeasure.Artist:GetStringValue())
	SKIN:Bang('!SetVariable', 'VariableCover', targetMeasure.Cover:GetStringValue())
	SKIN:Bang('!SetVariable', 'VariablePosition', targetMeasure.Position:GetStringValue())
	SKIN:Bang('!SetVariable', 'VariableDuration', targetMeasure.Duration:GetStringValue())
	SKIN:Bang('!SetVariable', 'VariableProgress', targetMeasure.Progress:GetValue())
	
	local trackString = targetMeasure.Track:GetStringValue()
	return trackString:gsub("([%z\1-\127\194-\244][\128-\191]*)", "%1" .. zwsp)
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
	candidateOrder = nil
	for order, measure in ipairs(Measures) do
	
		state = measure.State:GetValue()
		if state ~= 0 then
			if candidateOrder ~= nil then
				candidateOrder = order
			end
			
			if state == 1 then
				return order, measure.Name
			end
		end
	end
	
	if candidateOrder ~= nil then
		return candidateOrder, Measures[candidateOrder].Name
	end
	
	return nil, nil
end
