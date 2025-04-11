[Variables]
@Include=#@#Default.inc
@IncludeText=#@#Layouts/Text.inc

[MeasureTime]
Measure=Time
Format=%T

[MeasureDate]
Measure=Time
Format=%m/%d %a

[MeterBackground]
[MeterLabel]
[MeterIcon]
Text=#IconClock#

[MeterText]
FontWeight=300
MeasureName=MeasureTime
MeasureName2=MeasureDate
Text=%1#CRLF#%2
StringAlign=LeftCenter
X=#_HeaderLeft#
InlinePattern=^(.*)\n
InlinePattern2=^(.*)\n
InlineSetting2=Weight | 600
