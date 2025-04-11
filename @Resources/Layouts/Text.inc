[StyleTextLayout]
FontFace=#TextFont#
FontColor=#TextColor#
FontSize=(20 * #Multiplier#)
FontWeight=100
StringAlign=CenterCenter
AntiAlias=1

[MeterText]
Meter=String
MeterStyle=StyleTextLayout
X=(#_HeaderLeft# + (#_Width# - #_HeaderLeft# - #_HeaderRight#) / 2)
Y=(#_Height# / 2)
