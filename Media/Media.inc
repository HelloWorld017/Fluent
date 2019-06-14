[Variables]
BarDeltaX=0
BarDeltaY=0
BarTextDeltaY=2
BarCaptionDeltaY=0
BarCount=1
BarHeight=5
BarGap=0
@IncludeBar=#@#/Layouts/Bars/Bar1.inc
@IncludeMedia=#@#Media/#MediaMode#.inc

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

[MeasureTrackBreak]
Measure=Script
ScriptFile=#@#Scripts/WordBreak.lua
MeasureName=MeasureTrack

[MeasureBar1]
Measure=Calc
Formula=([MeasurePosition:] / ([MeasureDuration:] > 0 ? [MeasureDuration:] : 0.001))
DynamicVariables=1

[MeterTrack]
Meter=String
MeterStyle=StyleMediaText
MeasureName=MeasureTrackBreak
FontSize=14
X=(#LabelHeight# * 1.25)
Y=(#LabelY# + #LabelHeight# * 0.1)
W=(#Width# - (#LabelHeight# * 1.5))
H=(#LabelHeight# * 0.35)

[MeterArtist]
Meter=String
MeterStyle=StyleMediaText
MeasureName=MeasureArtist
FontSize=10
X=(#LabelHeight# * 1.25)
Y=(#LabelY# + #LabelHeight# * 0.5)
W=(#Width# - #LabelHeight# * 1.5)
H=(#LabelHeight# * 0.25)

[MeterBar1]
Y=20R

[MeterBarCaptionText1]
MeasureName=MeasurePosition
MeasureName2=MeasureDuration
Text=%1 / %2
Y=-15R

[MeterControlsPrev]
Meter=String
MeterStyle=StyleMediaButton
X=(#LabelHeight# + (#Width# - #LabelHeight#) / 4)
Y=35R
Text=[\xf4ae]
LeftMouseUpAction=[!CommandMeasure MeasureState "Previous"]

[MeterControlsPlayPause]
Meter=String
MeterStyle=StyleMediaButton
X=(#LabelHeight# + (#Width# - #LabelHeight#) / 4 * 2)
Y=0r
Text=[\xf40e]
LeftMouseUpAction=[!CommandMeasure MeasureState "PlayPause"]

[MeterControlsNext]
Meter=String
MeterStyle=StyleMediaButton
X=(#LabelHeight# + (#Width# - #LabelHeight#) / 4 * 3)
Y=0r
Text=[\xf4ad]
LeftMouseUpAction=[!CommandMeasure MeasureState "Next"]
