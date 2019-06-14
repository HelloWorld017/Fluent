[Variables]
; ==================================================
; |                FLUENT VARIABLES                |
; ==================================================


; ===================== THEME ======================
Theme=Magenta
ThemeBackground=Dark

TextFont=Noto Sans CJK KR Regular
IconFont=Material Design Icons

; ================= USAGE MONITOR ==================
; This processes are not shown on the process list like CoreLarge.
UsageBlacklist=_Total|Idle|dwm|wmpnetwk|csrss|svchost|lsass|System|system|Memory Compression|wininit|RemindersServer|spoolsv|IpOverUsbSvc|WmiPrvSE

; =================== MEDIA SKIN ===================
; GooglePlayMusic, NowPlaying, Spotify, WebNowPlaying
MediaMode=WebNowPlaying

; Uncomment when MediaMode=NowPlaying
; PlayerName=CAD

HideCoverIcon=0

; Complete Hide Cover : 0 ~ 255 : No Tint
CoverTint=150

; =================== DRIVE SKIN ===================
Drive1=C:
Drive2=G:

; MB/s, For drawing plot
MaxDriveSpeed=20

; ================== NETWORK SKIN ==================
PingServer=www.google.com
PingLow=30
PingHigh=100

; Mbps, For drawing plot
MaxNetworkSpeed=100

; ================ TEMPERATURE SKIN ================
OHMPort=8085
ThermoMin=30
ThermoMax=55

ThermoUnit=[\x2103]

; For Fahrenheit users, you should
; 1. Comment ThermoUnit up there and uncomment this:
; ThermoUnit=[\x2109]

; 2. Go to Icons.inc, comment IconTemperature and uncomment another alternatives.
; 3. Change units in Open Hardware Monitor
; 4. Calculate and convert ThermoMin, ThermoMax to Fahrenheit

; ================== UPTIME SKIN ===================
; Uptime Sysinfo:
; You can use this regardless of hybrid reboot status
; This checks User LoginTime

UptimeMode=Sysinfo


; Uptime Hybrid:
; When you're using hybrid reboot (Windows Default)
; It checks Uptime from when the skin loades.
; If you restart / refresh Rainmeter or the Skin, the counter will be reset.

; UptimeMode=Hybrid


; Uptime Default:
; When you don't use hybrid reboot
; If you use default with hybrid reboot, the uptime will be abnormally long.
; But the counter won't reset on refreshing skin

; UptimeMode=Default

; ================== WEATHER SKIN ==================
LocationCode=KSXX0027
WeatherUnit=m
