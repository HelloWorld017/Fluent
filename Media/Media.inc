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
FontSize=25
W=25
H=25
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
FontSize=14
X=(#LabelHeight# * 1.25)
Y=(#LabelY# + #LabelHeight# * 0.1)
W=(#Width# - (#LabelHeight# * 1.5))
H=(#LabelHeight# * 0.35)

[MeterArtist]
Meter=String
MeterStyle=StyleMediaText
Text=#VariableArtist#
FontSize=10
X=(#LabelHeight# * 1.25)
Y=(#LabelY# + #LabelHeight# * 0.5)
W=(#Width# - #LabelHeight# * 1.5)
H=(#LabelHeight# * 0.25)
DynamicVariables=1

[MeterBar1]
Y=20R

[MeterBarCaptionText1]
Text=#VariablePosition# / #VariableDuration#
Y=-15R
DynamicVariables=1

[MeterControlsPrev]
Meter=String
MeterStyle=StyleMediaButton
X=(#LabelHeight# + (#Width# - #LabelHeight#) / 4)
Y=35R
Text=[\xf4ae]
LeftMouseUpAction=[!CommandMeasure MeasureCombine "Execute('Previous')"]

[MeterControlsPlayPause]
Meter=String
MeterStyle=StyleMediaButton
X=(#LabelHeight# + (#Width# - #LabelHeight#) / 4 * 2)
Y=0r
Text=[\xf40e]
LeftMouseUpAction=[!CommandMeasure MeasureCombine "Execute('PlayPause')"]

[MeterControlsNext]
Meter=String
MeterStyle=StyleMediaButton
X=(#LabelHeight# + (#Width# - #LabelHeight#) / 4 * 3)
Y=0r
Text=[\xf4ad]
LeftMouseUpAction=[!CommandMeasure MeasureCombine "Execute('Next')"]
