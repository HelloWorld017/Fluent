[MeasureGraph]
OnUpdateAction=[!CommandMeasure ScriptGraph "Graph()"]

[ScriptGraph]
Measure=Script
ScriptFile=#@#Scripts\GraphShape.lua
ShapeWidth=(#Width# - #LabelHeight# * 1.5)
ShapeHeight=(#Height# * 0.75)
InputMeasure=MeasureGraph
OutputGraph=MeterGraph

[MeterGraph]
Meter=Shape
X=(#LabelHeight# * 1.25)
Y=(#Height# * 0.75)
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
FontSize=15
FontWeight=100
StringAlign=RightTop
AntiAlias=1
X=(#Width# - #LabelHeight# * 0.25)
Y=(#Height# * 0.1)
