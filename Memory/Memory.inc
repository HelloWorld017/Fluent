[Variables]
@Include=#@#Default.inc

[MeasureMemory]
Measure=PhysicalMemory

[MeasureTotal]
Measure=Calc
Formula=[MeasureMemory:MaxValue] / (1024 * 1024 * 1024)
DynamicVariables=1

[MeasureCurrent]
Measure=Calc
Formula=MeasureMemory / (1024 * 1024 * 1024)

[MeasureGraph]
Measure=Calc
Formula=[MeasureMemory:%]
DynamicVariables=1

[MeterBackground]
[MeterLabel]
[MeterIcon]
Text=#IconMemory#

[MeterGraph]
[MeterGraphText]
MeasureName=MeasureGraph
Text=[MeasureCurrent:1]GB / [MeasureTotal:1]GB (%1%)
DynamicVariables=1
