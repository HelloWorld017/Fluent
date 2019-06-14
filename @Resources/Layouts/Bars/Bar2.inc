[Variable]
@Include=Bar1.inc

[MeasureBar2]
Measure=Calc
Formula=0

[MeterBar2]
Meter=Shape
Shape=Rectangle 0,0,#BarWidth#,#BarHeight#,#BarRadius# | Fill Color #BarBackgroundColor# | StrokeWidth 0
Shape2=Rectangle 0,0,(#BarWidth# * ([MeasureBar2:%]/100)),#BarHeight#,#BarRadius# | Fill LinearGradient Grad | StrokeWidth 0
Grad=180 | #BarFirstColor# ; 0 | #BarSecondColor# ; 1
X=(#BarDeltaX# + #LabelHeight# * 1.25)
Y=((#Height# * 0.1 + (#BarContainerHeight# + #BarGap#) * 1) + (#BarContainerHeight# - #BarHeight#) / 2 + #BarDeltaY#)
DynamicVariables=1

[MeterBarText2]
Meter=String
FontFace=#TextFont#
FontColor=#BarTextColor#
FontSize=15
FontWeight=100
StringAlign=LeftCenter
AntiAlias=1
X=(#LabelHeight# * 1.25)
Y=((#Height# * 0.1 + (#BarContainerHeight# + #BarGap#) * 1) + #BarContainerHeight# / 2 + #BarTextDeltaY#)

[MeterBarCaptionText2]
Meter=String
FontFace=#TextFont#
FontColor=#BarCaptionTextColor#
FontSize=9
FontWeight=400
StringAlign=RightCenter
AntiAlias=1
X=(#Width# - #LabelHeight# * 0.25)
Y=((#Height# * 0.1 + (#BarContainerHeight# + #BarGap#) * 1) + #BarContainerHeight# / 2 - #BarCaptionDeltaY#)
