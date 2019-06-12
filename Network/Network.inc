[MeasureNetDownload]
Measure=NetIn

[MeasureNetUpload]
Measure=NetOut

[MeasureNetTotal]
Measure=NetTotal
MaxValue=(#MaxNetworkSpeed# * 1024 * 1024)

[MeasureGraph]
Measure=Calc
Formula=[MeasureNetTotal:%]
DynamicVariables=1

[MeterGraphText]
MeasureName=MeasureNetTotal
Text=%1B/s
AutoScale=1
