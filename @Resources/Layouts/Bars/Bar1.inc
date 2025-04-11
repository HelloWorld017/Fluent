[Variables]
BarWidth=(#Width# - #HeaderLeft# - #HeaderRight# - #BarDeltaX#)
BarListHeight=(#Height# - #HeaderTop# - #HeaderBottom#)
BarContainerHeight=((#BarListHeight# - #BarGap# * (#BarCount# - 1)) / #BarCount#)
BarRadius=(#BarHeight# / 2)

_BarGap=(#BarGap# * #Multiplier#)
_BarWidth=(#BarWidth# * #Multiplier#)
_BarHeight=(#BarHeight# * #Multiplier#)
_BarContainerHeight=(#BarContainerHeight# * #Multiplier#)
_BarRadius=(#BarRadius# * #Multiplier#)
_BarDeltaX=(#BarDeltaX# * #Multiplier#)
_BarDeltaY=(#BarDeltaY# * #Multiplier#)
_BarCaptionDeltaY=(#BarCaptionDeltaY# * #Multiplier#)
_BarTextDeltaY=(#BarTextDeltaY# * #Multiplier#)

[MeasureBar1]
Measure=Calc
Formula=0

[MeterBar1]
Meter=Shape
Shape=Rectangle 0,0,#_BarWidth#,#_BarHeight#,#_BarRadius# | Fill Color #BarBackgroundColor# | StrokeWidth 0
Shape2=Rectangle 0,0,(#_BarWidth# * ([MeasureBar1:%]/100)),#_BarHeight#,#_BarRadius# | Fill LinearGradient Grad | StrokeWidth 0
Grad=180 | #BarFirstColor# ; 0 | #BarSecondColor# ; 1
X=(#_BarDeltaX# + #_HeaderLeft#)
Y=(#_HeaderTop# + (#_BarContainerHeight# - #_BarHeight#) / 2 + #_BarDeltaY#)
DynamicVariables=1

[MeterBarText1]
Meter=String
FontFace=#TextFont#
FontColor=#BarTextColor#
FontSize=(15 * #Multiplier#)
FontWeight=300
StringAlign=LeftCenter
AntiAlias=1
X=#_HeaderLeft#
Y=(#_HeaderTop# + #_BarContainerHeight# / 2 + #_BarTextDeltaY#)

[MeterBarCaptionText1]
Meter=String
FontFace=#TextFont#
FontColor=#BarCaptionTextColor#
FontSize=(9 * #Multiplier#)
FontWeight=700
StringAlign=RightCenter
AntiAlias=1
X=(#_Width# - #_HeaderRight#)
Y=(#_HeaderTop# + #_BarContainerHeight# / 2 - #_BarCaptionDeltaY#)
