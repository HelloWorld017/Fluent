[Variables]
BarDeltaX=35
BarDeltaY=5
BarTextDeltaY=2
BarCaptionDeltaY=10
BarCount=2
BarHeight=5
BarGap=0
@IncludeBar=#@#Layouts/Bars/Bar2.inc

; ================= DRIVE 1 MEASURE =================
[MeasureDrive1Used]
Measure=FreeDiskSpace
Drive=#Drive1#
InvertMeasure=1
UpdateDivider=5

[MeasureDrive1Total]
Measure=FreeDiskSpace
Drive=#Drive1#
Total=1
UpdateDivider=-1

[MeasureDrive1UsedSI]
Measure=Calc
Formula=MeasureDrive1Used / 1073741824

[MeasureDrive1TotalSI]
Measure=Calc
Formula=MeasureDrive1Total / 1073741824

[MeasureBar1]
Measure=Calc
Formula=[MeasureDrive1Used:%]
MinValue=0
MaxValue=100
DynamicVariables=1

; ================= DRIVE 2 MEASURE =================
[MeasureDrive2Used]
Measure=FreeDiskSpace
Drive=#Drive2#
InvertMeasure=1
UpdateDivider=5

[MeasureDrive2Total]
Measure=FreeDiskSpace
Drive=#Drive2#
Total=1
UpdateDivider=-1

[MeasureDrive2UsedSI]
Measure=Calc
Formula=MeasureDrive2Used / 1073741824

[MeasureDrive2TotalSI]
Measure=Calc
Formula=MeasureDrive2Total / 1073741824

[MeasureBar2]
Measure=Calc
Formula=[MeasureDrive2Used:%]
MinValue=0
MaxValue=100
DynamicVariables=1

; ====================== METERS =====================
[MeterBar1]
[MeterBarText1]
Text=#Drive1#

[MeterBarCaptionText1]
MeasureName=MeasureDrive1UsedSI
MeasureName2=MeasureDrive1TotalSI
Text=%1 GB / %2 GB

[MeterBar2]
[MeterBarText2]
Text=#Drive2#

[MeterBarCaptionText2]
MeasureName=MeasureDrive2UsedSI
MeasureName2=MeasureDrive2TotalSI
Text=%1 GB / %2 GB
