[Variables]
LabelY=(#Height# - #LabelYMax# * 2 < #LabelHeight# ? (#Height# - #LabelHeight#) / 2 : #LabelYMax#)

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
UpdateDivider=-1
BlurEnabled=1

[MeterBackground]
Meter=Shape
X=0
Y=0
Shape=Path Path | Fill Color #BackgroundColor# | StrokeWidth 0
Path=0,0 | LineTo #Width#,0 | LineTo #Width#,#Height# | LineTo 0,#Height# | ClosePath 1

[MeterLabel]
Meter=Shape
X=0
Y=#LabelY#
Shape=Path Path | Fill Color #LabelColor# | StrokeWidth 0
Path = 0,0 | LineTo #LabelHeight#,0 | LineTo #LabelHeight#,#LabelHeight# | LineTo 0,#LabelHeight# | ClosePath 1

[MeterIcon]
Meter=String
FontFace=#IconFont#
FontColor=#IconColor#
FontSize=30
StringAlign=CenterCenter
AntiAlias=1
X=(#LabelHeight# / 2)
Y=(#LabelY# + #LabelHeight# / 2 + #LabelOffset#)
