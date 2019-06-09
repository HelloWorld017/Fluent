[Variables]
@Include=Graph.inc

[ScriptGraph]
ShapeHeight=(#Height# * 0.35)

[MeterGraph]
Y=(#Height# * 0.45)

; ================== LIST MEASURE ==================-
[MeasureTop1]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=1
Substitute="":"---"

[MeasureTop2]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=2
Substitute="":"---"

[MeasureTop3]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=3
Substitute="":"---"

[MeasureTop4]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=4
Substitute="":"---"

[MeasureTop5]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=5
Substitute="":"---"

; ================= DEFAULT STYLES ==================
[StyleList]
X=(#Width# * 0.1)
Y=10R
FontSize=11
FontFace=#TextFont#
FontWeight=100
FontColor=255,255,255,255
StringAlign=LeftCenter
DynamicVariables=1
AntiAlias=1

[StyleListValue]
FontWeight=800
StringAlign=RightCenter
X=(#Width# * 0.9)
Y=0r

; ================= PROCESS METERS ==================
[MeterTop1Name]
Meter=String
MeasureName=MeasureTop1
MeterStyle=StyleList
Y=(#Height# * 0.6)

[MeterTop1Value]
Meter=String
MeterStyle=StyleList | StyleListValue
Text=[MeasureTop1:1]%

[MeterTop2Name]
Meter=String
MeasureName=MeasureTop2
MeterStyle=StyleList

[MeterTop2Value]
Meter=String
MeterStyle=StyleList | StyleListValue
Text=[MeasureTop2:1]%

[MeterTop3Name]
Meter=String
MeasureName=MeasureTop3
MeterStyle=StyleList

[MeterTop3Value]
Meter=String
MeterStyle=StyleList | StyleListValue
Text=[MeasureTop3:1]%
