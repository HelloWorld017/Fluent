[Variable]
@Include=Bar1.inc

[MeasureBar2]
Measure=Calc
Formula=0

[MeterBar2]
Meter=Shape
Shape=Rectangle 0,0,#_BarWidth#,#_BarHeight#,#_BarRadius# | Fill Color #BarBackgroundColor# | StrokeWidth 0
Shape2=Rectangle 0,0,(#_BarWidth# * ([MeasureBar1:%]/100)),#_BarHeight#,#_BarRadius# | Fill LinearGradient Grad | StrokeWidth 0
Grad=180 | #BarFirstColor# ; 0 | #BarSecondColor# ; 1
X=(#_BarDeltaX# + #_HeaderLeft#)
Y=((#_HeaderTop# + (#_BarContainerHeight# + #_BarGap#) * 1) + (#_BarContainerHeight# - #_BarHeight#) / 2 + #_BarDeltaY#)
DynamicVariables=1

[MeterBarText2]
Meter=String
FontFace=#TextFont#
FontColor=#BarTextColor#
FontSize=(15 * #Multiplier#)
FontWeight=300
StringAlign=LeftCenter
AntiAlias=1
X=#_HeaderLeft#
Y=((#_HeaderTop# + (#_BarContainerHeight# + #_BarGap#) * 1) + #_BarContainerHeight# / 2 + #_BarTextDeltaY#)

[MeterBarCaptionText2]
Meter=String
FontFace=#TextFont#
FontColor=#BarCaptionTextColor#
FontSize=(9 * #Multiplier#)
FontWeight=700
StringAlign=RightCenter
AntiAlias=1
X=(#_Width# - #_HeaderRight#)
Y=((#_HeaderTop# + (#_BarContainerHeight# + #_BarGap#) * 1) + #_BarContainerHeight# / 2 - #_BarCaptionDeltaY#)
