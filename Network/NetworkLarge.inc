[Variables]
@IncludeNetwork=Network.inc

; ===================== STYLES =====================
[StyleNetworkLabel]
FontFace=#TextFont#
FontSize=10
FontColor=#TextColor#c0
FontWeight=400
StringAlign=RightTop
AntiAlias=1



; ==================================================
; |                    MEASURES                    |
; ==================================================

; ============== PING & COLOR MEASURES ==============
[MeasurePing]
Measure=Plugin
Plugin=PingPlugin
DestAddress=#PingServer#
UpdateRate=5

[MeasurePingAlpha]
Measure=Calc
Formula=([MeasurePing] < #PingLow#) ? 255 : (1 - ([MeasurePing] - #PingLow#) / (#PingHigh# - #PingLow#)) * 255
DynamicVariables=1
UpdateDivider=5

; From bother of changing LabelColor from Hex to Dec
[MeasureRemainderAlpha]
Measure=Calc
Formula=([MeasurePingAlpha:0] % 16)
Substitute="10":"a","11":"b","12":"c","13":"d","14":"e","15":"f"
DynamicVariables=1
UpdateDivider=5

[MeasureQuotientAlpha]
Measure=Calc
Formula=([MeasurePingAlpha:0] - [MeasureRemainderAlpha:]) / 16
Substitute="10":"a","11":"b","12":"c","13":"d","14":"e","15":"f"
DynamicVariables=1
UpdateDivider=5

; ================= IP ADDR MEASURES ================
[MeasureLocalIP]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=Best
Substitute="":"N/A"
UpdateDivider=-1

[MeasureExternalIP]
Measure=WebParser
UpdateRate=21600
Url=http://checkip.dyndns.org:8245
RegExp="(?siU)Address: (.*)</body>"
StringIndex=1
Substitute="":"N/A"
UpdateDivider=-1

; =============== ACCUMULATOR MEASURES ==============
[MeasureUploadTotal]
Measure=Script
ScriptFile=#@#/Scripts/Accumulator.lua
MeasureName=MeasureNetUpload

[MeasureDownloadTotal]
Measure=Script
ScriptFile=#@#/Scripts/Accumulator.lua
MeasureName=MeasureNetDownload



; ==================================================
; |                     METERS                     |
; ==================================================

; ================== PING METERS ===================
[MeterPingBackground]
Meter=Shape
Shape=Rectangle 0,0,60,30 | Fill Color #LabelColor#[MeasureQuotientAlpha][MeasureRemainderAlpha] | StrokeWidth 0
X=0
Y=(#Height# - 50)
DynamicVariables=1

[MeterPing]
Meter=String
MeasureName=MeasurePing
FontFace=#TextFont#
FontColor=#IconColor#
FontWeight=500
StringAlign=CenterCenter
AntiAlias=1
Text=%1 ms
X=30
Y=(#Height# - 35)

; ================ UPLOAD METERS ===================
[MeterIconUpload]
Meter=String
FontFace=#IconFont#
FontColor=#TextColor#
FontSize=16
StringAlign=LeftTop
Text=[\xf552]
AntiAlias=1
X=(#LabelHeight# * 1.25)
Y=(#LabelY#)

[MeterUpload]
Meter=String
MeasureName=MeasureNetUpload
MeterStyle=StyleNetworkLabel
Text=%1B/s
AutoScale=1
X=(#Width# - #LabelHeight# * 0.25)
Y=(#LabelY#)

[MeterUploadTotal]
Meter=String
MeasureName=MeasureUploadTotal
MeterStyle=StyleNetworkLabel
Text=%1B
AutoScale=1
X=0r
Y=20r

; ================ DOWNLOAD METERS =================
[MeterIconDownload]
Meter=String
FontFace=#IconFont#
FontColor=#TextColor#
FontSize=16
StringAlign=LeftTop
Text=[\xf1da]
AntiAlias=1
X=(#LabelHeight# * 1.25)
Y=40r

[MeterDownload]
Meter=String
MeasureName=MeasureNetDownload
MeterStyle=StyleNetworkLabel
Text=%1B/s
AutoScale=1
X=(#Width# - #LabelHeight# * 0.25)
Y=0r

[MeterDownloadTotal]
Meter=String
MeasureName=MeasureDownloadTotal
MeterStyle=StyleNetworkLabel
Text=%1B
AutoScale=1
X=0r
Y=20r

; ================== IP METERS =====================
[MeterIP]
Meter=String
FontFace=#TextFont#
FontColor=#TextColor#
FontSize=16
StringAlign=LeftTop
Text=IP
AntiAlias=1
X=(#LabelHeight# * 1.25)
Y=40r

[MeterIPLocal]
Meter=String
MeterStyle=StyleNetworkLabel
MeasureName=MeasureLocalIP
Text=%1
X=(#Width# - (#LabelHeight# * 0.25))
Y=0r

[MeterIPExternal]
Meter=String
MeterStyle=StyleNetworkLabel
MeasureName=MeasureExternalIP
Text=%1
X=(#Width# - (#LabelHeight# * 0.25))
Y=20r
