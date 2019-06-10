[Variables]
@IncludeMedia=#@#Media/#MediaMode#.inc

[StyleMediaText]
FontColor=#TextColor#
FontFace=#TextFont#
StringAlign=TopLeft
ClipString=1
AntiAlias=1

[MeasureTrackBreak]
Measure=Script
ScriptFile=#@#Scripts/WordBreak.lua
MeasureName=MeasureTrack

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
