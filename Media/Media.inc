[Variables]
BarDeltaX=0
BarDeltaY=0
BarTextDeltaY=2
BarCaptionDeltaY=0
BarCount=1
BarHeight=5
BarGap=0
@IncludeBar=#@#/Layouts/Bars/Bar1.inc
@IncludeMedia=#@#Media/Combined.inc
@IncludeMediaOrder1=#@#Media/#MediaOrder1#.inc
@IncludeMediaOrder2=#@#Media/#MediaOrder2#.inc
@IncludeMediaOrder3=#@#Media/#MediaOrder3#.inc
@IncludeMediaOrder4=#@#Media/#MediaOrder4#.inc
@IncludeMediaOrder5=#@#Media/#MediaOrder5#.inc

[StyleMediaText]
FontColor=#TextColor#
FontFace=#TextFont#
StringAlign=TopLeft
ClipString=1
AntiAlias=1

[StyleMediaButton]
FontFace=#IconFont#
FontColor=#TextColor#
FontSize=(25 * #Multiplier#)
W=(25 * #Multiplier#)
H=(25 * #Multiplier#)
StringAlign=CenterCenter
AntiAlias=1

[MeasureBar1]
Measure=Calc
Formula=#VariableProgress# / 100
DynamicVariables=1

[MeterTrack]
Meter=String
MeterStyle=StyleMediaText
MeasureName=MeasureCombine
FontSize=(14 * #Multiplier#)
FontWeight=600
X=(#_HeaderLeft#)
Y=(#_HeaderTop# + #_HeaderHeight# * 0.1)
W=(#_Width# - #_HeaderLeft# - #_HeaderRight#)
H=(#_HeaderHeight# * 0.25)

[MeterArtist]
Meter=String
MeterStyle=StyleMediaText
Text=#VariableArtist#
FontSize=(10 * #Multiplier#)
FontColor=#TextColorSecondary#
X=(#_HeaderLeft#)
Y=(#_HeaderTop# + #_HeaderHeight# * 0.35)
W=(#_Width# - #_HeaderLeft# - #_HeaderRight#)
H=(#_HeaderHeight# * 0.15)
DynamicVariables=1

[MeterBar1]
Y=(30 * #Multiplier#)R

[MeterBarCaptionText1]
Text=#VariablePosition# / #VariableDuration#
Y=(-20 * #Multiplier#)R
DynamicVariables=1

[MeterControlsPrev]
Meter=String
MeterStyle=StyleMediaButton
X=(#_HeaderLeft# + (#_Width# - #_HeaderLeft# - #_HeaderRight#) / 6)
Y=(45 * #Multiplier#)R
Text=[\xf4ae]
LeftMouseUpAction=[!CommandMeasure MeasureCombine "Execute('Previous')"]

[MeterControlsPlayPause]
Meter=String
MeterStyle=StyleMediaButton
X=(#_HeaderLeft# + (#_Width# - #_HeaderLeft# - #_HeaderRight#) / 6 * 3)
Y=0r
Text=[\xf40e]
LeftMouseUpAction=[!CommandMeasure MeasureCombine "Execute('PlayPause')"]

[MeterControlsNext]
Meter=String
MeterStyle=StyleMediaButton
X=(#_HeaderLeft# + (#_Width# - #_HeaderLeft# - #_HeaderRight#) / 6 * 5)
Y=0r
Text=[\xf4ad]
LeftMouseUpAction=[!CommandMeasure MeasureCombine "Execute('Next')"]
