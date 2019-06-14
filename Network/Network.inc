[Variables]
@Include=#@#Default.inc

[MeasureNetDownload]
Measure=NetIn

[MeasureNetUpload]
Measure=NetOut

[MeasureNetTotal]
Measure=NetTotal
MaxValue=(#MaxNetworkSpeed# * 1024 * 1024)

[MeterIcon]
Text=#IconNetwork#
