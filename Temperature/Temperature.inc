[Variables]
@Include=#@#Default.inc

[MeasureGetTemp]
Measure=WebParser
URL=http://localhost:#OHMPort#/data.json
RegExp=(.*)
UpdateRate=8

[MeasureTempInfo]
Measure=Script
ScriptFile=#@#Scripts/OpenHardwareInfo.lua
Source=MeasureGetTemp
UpdateDivider=8

[MeasureCPUTemp]
Measure=String
String=[MeasureTempInfo]
Substitute="^([\d.]+),[\d.]+,[\d.]+$":"\1"
RegExpSubstitute=1
DynamicVariables=1
UpdateDivider=4
MaxValue=100

[MeasureGPUTemp]
Measure=String
String=[MeasureTempInfo]
Substitute="^[\d.]+,([\d.]+),[\d.]+$":"\1"
RegExpSubstitute=1
DynamicVariables=1
UpdateDivider=4
MaxValue=100

[MeasureHDDTemp]
Measure=String
String=[MeasureTempInfo]
Substitute="^[\d.]+,[\d.]+,([\d.]+)$":"\1"
RegExpSubstitute=1
DynamicVariables=1
UpdateDivider=4
MaxValue=100
