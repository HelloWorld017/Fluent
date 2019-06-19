[Variables]
LabelY=(#Height# - #LabelYMax# * 2 < #LabelHeight# ? (#Height# - #LabelHeight#) / 2 : #LabelYMax#)

[MeterBackground]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0,0,#Width#,#Height# | Fill Color #BackgroundColor# | StrokeWidth 0

[MeterLabel]
Meter=Shape
X=0
Y=#LabelY#
Shape=Rectangle 0,0,#LabelHeight#,#LabelHeight# | Fill Color #LabelColor# | StrokeWidth 0

[MeterIcon]
Meter=String
FontFace=#IconFont#
FontColor=#IconColor#
FontSize=30
StringAlign=CenterCenter
AntiAlias=1
X=(#LabelHeight# / 2)
Y=(#LabelY# + #LabelHeight# / 2 + #LabelOffset#)
