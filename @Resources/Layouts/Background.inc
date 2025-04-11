[Variables]
Padding=20
LabelSize=80
LabelPadding=0
LabelGap=#Padding#
LabelIconOffsetY=2
LabelRadius=8
LabelRadiusLeft=(#LabelPadding# = 0 ? 0 : #LabelRadius#)
HeaderHeight=(#Height# < 120 ? #Height# : 120)
HeaderTop=#Padding#
HeaderLeft=(#LabelSize# + 2 * #LabelPadding# + #LabelGap#)
HeaderBottom=#Padding#
HeaderRight=#Padding#
BodyHeight=(#Height# - #HeaderHeight#)
BodyOffsetY=#HeaderHeight#
BodyTop=10
BodyLeft=(#Padding# + 5)
BodyBottom=#Padding#
BodyRight=#Padding#

_Width=(#Width# * #Multiplier#)
_Height=(#Height# * #Multiplier#)
_Padding=(#Padding# * #Multiplier#)
_LabelSize=(#LabelSize# * #Multiplier#)
_LabelPadding=(#LabelPadding# * #Multiplier#)
_LabelGap=(#LabelGap# * #Multiplier#)
_LabelIconOffsetY=(#LabelIconOffsetY# * #Multiplier#)
_LabelRadius=(#LabelRadius# * #Multiplier#)
_LabelRadiusLeft=(#LabelRadiusLeft# * #Multiplier#)
_HeaderHeight=(#HeaderHeight# * #Multiplier#)
_HeaderLeft=(#HeaderLeft# * #Multiplier#)
_HeaderTop=(#HeaderTop# * #Multiplier#)
_HeaderBottom=(#HeaderBottom# * #Multiplier#)
_HeaderRight=(#HeaderRight# * #Multiplier#)
_BodyHeight=(#BodyHeight# * #Multiplier#)
_BodyOffsetY=(#BodyOffsetY# * #Multiplier#)
_BodyLeft=(#BodyLeft# * #Multiplier#)
_BodyTop=(#BodyTop# * #Multiplier#)
_BodyBottom=(#BodyBottom# * #Multiplier#)
_BodyRight=(#BodyRight# * #Multiplier#)

[MeterBackground]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0,0,#_Width#,#_Height# | Fill Color #BackgroundColor# | StrokeWidth 0

[MeterLabel]
Meter=Shape
X=#_LabelPadding#
Y=((#_HeaderHeight# - #_LabelSize#) / 2)
Shape=Rectangle #_LabelRadiusLeft#,0,(#_LabelSize# - #_LabelRadiusLeft#),#_LabelSize#,#_LabelRadius#,#_LabelRadius# | Fill Color #LabelColor# | StrokeWidth 0
Shape2=Rectangle 0,0,(#_LabelSize# - #_LabelRadius#),#_LabelSize#,#_LabelRadiusLeft#,#_LabelRadiusLeft# | Fill Color #LabelColor# | StrokeWidth 0
Shape3=Combine Shape | Union Shape2

[MeterIcon]
Meter=String
FontFace=#IconFont#
FontColor=#IconColor#
FontSize=(30 * #Multiplier#)
StringAlign=CenterCenter
AntiAlias=1
X=(#_LabelSize# / 2 + #_LabelPadding#)
Y=(#_HeaderHeight# / 2 + #_LabelIconOffsetY#)
