[MeasureGraph]
OnUpdateAction=[!CommandMeasure ScriptGraph "Graph()"]

[ScriptGraph]
Measure=Script
ScriptFile=#@#Scripts\GraphShape.lua
ShapeWidth=(#_Width# - #_HeaderLeft# - #_HeaderRight#)
ShapeHeight=(#_Height# - #_HeaderTop# - #_HeaderBottom#)
InputMeasure=MeasureGraph
OutputGraph=MeterGraph

[MeterGraph]
Meter=Shape
X=#_HeaderLeft#
Y=(#_Height# - #_HeaderBottom#)
Shape=Path Graph1 | StrokeWidth 3 | Stroke Color #GraphColor# | StrokeLineJoin Round
Shape2=Path Graph2 | StrokeWidth 0 | Fill LinearGradient Grad | StrokeLineJoin Round
Graph1=0,0|Lineto 0,0
Graph2=0,0|Lineto 0,0
Grad = 270 | #GraphColor#ff ; 0 | #GraphColor#00 ; 1
Padding=0,0,0,(10)

[MeterGraphText]
Meter=String
FontFace=#TextFont#
FontColor=#GraphTextColor#
FontSize=(15 * #Multiplier#)
FontWeight=500
StringAlign=RightTop
AntiAlias=1
X=(#_Width# - #_HeaderRight#)
Y=#_HeaderTop# - (8 * #Multiplier#)
