[Variables]
@IncludeNetwork=Network.inc
ItemsOffsetY = 10
ItemGap = 40
RowGap = 20
IconOffsetY = 8
_ItemsOffsetY = (#ItemsOffsetY# * #Multiplier#)
_ItemGap = (#ItemGap# * #Multiplier#)
_RowGap = (#RowGap# * #Multiplier#)
_IconOffsetY = (#IconOffsetY# * #Multiplier#)

; ===================== STYLES =====================
[StyleNetworkLabel]
FontFace=#TextFont#
FontSize=(10 * #Multiplier#)
FontColor=#TextColorSecondary#
FontWeight=500
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
Shape=Rectangle 0,0,(60 * #Multiplier#),(30 * #Multiplier#) | Fill Color #LabelColor#[MeasureQuotientAlpha][MeasureRemainderAlpha] | StrokeWidth 0
X=0
Y=(#_Height# - 60 * #Multiplier#)
DynamicVariables=1

[MeterPing]
Meter=String
MeasureName=MeasurePing
FontFace=#TextFont#
FontColor=#IconColor#
FontWeight=500
FontSize=(8 * #Multiplier#)
StringAlign=CenterCenter
AntiAlias=1
Text=%1 ms
X=(30 * #Multiplier#)
Y=(#_Height# - 45 * #Multiplier#)

; ================ UPLOAD METERS ===================
[MeterIconUpload]
Meter=String
FontFace=#IconFont#
FontColor=#TextColor#
FontSize=(16 * #Multiplier#)
StringAlign=LeftTop
Text=[\xf552]
AntiAlias=1
X=(#_HeaderLeft#)
Y=(#_HeaderTop# + #_ItemsOffsetY# + #_IconOffsetY#)

[MeterUpload]
Meter=String
MeasureName=MeasureNetUpload
MeterStyle=StyleNetworkLabel
Text=%1B/s
AutoScale=1
X=(#_Width# - #_HeaderRight#)
Y=(-#IconOffsetY#)r

[MeterUploadTotal]
Meter=String
MeasureName=MeasureUploadTotal
MeterStyle=StyleNetworkLabel
Text=%1B
AutoScale=1
X=0r
Y=(#_RowGap#)r

; ================ DOWNLOAD METERS =================
[MeterIconDownload]
Meter=String
FontFace=#IconFont#
FontColor=#TextColor#
FontSize=(16 * #Multiplier#)
StringAlign=LeftTop
Text=[\xf1da]
AntiAlias=1
X=(#_HeaderLeft#)
Y=(#_ItemGap# + #_IconOffsetY#)r

[MeterDownload]
Meter=String
MeasureName=MeasureNetDownload
MeterStyle=StyleNetworkLabel
Text=%1B/s
AutoScale=1
X=(#_Width# - #_HeaderRight#)
Y=(-#_IconOffsetY#)r

[MeterDownloadTotal]
Meter=String
MeasureName=MeasureDownloadTotal
MeterStyle=StyleNetworkLabel
Text=%1B
AutoScale=1
X=0r
Y=(#_RowGap#)r

; ================== IP METERS =====================
[MeterIP]
Meter=String
FontFace=#TextFont#
FontColor=#TextColor#
FontSize=(16 * #Multiplier#)
StringAlign=LeftTop
Text=IP
AntiAlias=1
X=(#_HeaderLeft#)
Y=(#_ItemGap# + #_IconOffsetY#)r

[MeterIPLocal]
Meter=String
MeterStyle=StyleNetworkLabel
MeasureName=MeasureLocalIP
Text=%1
X=(#_Width# - #_HeaderRight#)
Y=(-#_IconOffsetY#)r

[MeterIPExternal]
Meter=String
MeterStyle=StyleNetworkLabel
MeasureName=MeasureExternalIP
Text=%1
X=0r
Y=(#_RowGap#)r
