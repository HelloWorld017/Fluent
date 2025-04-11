[Variables]
@Include=Graph.inc
GraphSize=(#HeaderHeight# - #HeaderTop# - #HeaderBottom#)
_GraphSize=(#GraphSize# * #Multiplier#)

[ScriptGraph]
ShapeHeight=#_GraphSize#

[MeterGraph]
Y=(#_GraphSize# + #_Padding#)

[MeterGraphText]
Y=#_HeaderTop#

; ================== LIST MEASURE ==================-
[MeasureTop1]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=1
Substitute="":"No Entries"

[MeasureTop2]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=2
Substitute="":"No Entries"

[MeasureTop3]
Measure=Plugin
Plugin=UsageMonitor
Blacklist=#UsageBlacklist#
Alias=#GraphAlias#
Index=3
Substitute="":"No Entries"

; ================= DEFAULT STYLES ==================
[StyleList]
X=#_BodyLeft#
Y=(15 * #Multiplier#)R
FontSize=(11 * #Multiplier#)
FontFace=#TextFont#
FontWeight=400
FontColor=#TextColor#f0
StringAlign=LeftCenter
DynamicVariables=1
AntiAlias=1

[StyleListValue]
FontWeight=800
StringAlign=RightCenter
X=(#_Width# - #_BodyRight#)
Y=0r

; ================= PROCESS METERS ==================
[MeterTop1Name]
Meter=String
MeasureName=MeasureTop1
MeterStyle=StyleList
Y=(#_BodyOffsetY# + #_BodyTop# + 15 * #Multiplier#)
;FontColor=#TextColor#ff

[MeterTop1Value]
Meter=String
MeterStyle=StyleList | StyleListValue
Text=[MeasureTop1:1]
;FontColor=#TextColor#ff

[MeterTop2Name]
Meter=String
MeasureName=MeasureTop2
MeterStyle=StyleList
;FontColor=#TextColor#a0

[MeterTop2Value]
Meter=String
MeterStyle=StyleList | StyleListValue
Text=[MeasureTop2:1]
;FontColor=#TextColor#a0

[MeterTop3Name]
Meter=String
MeasureName=MeasureTop3
MeterStyle=StyleList
;FontColor=#TextColor#80

[MeterTop3Value]
Meter=String
MeterStyle=StyleList | StyleListValue
Text=[MeasureTop3:1]
;FontColor=#TextColor#80
