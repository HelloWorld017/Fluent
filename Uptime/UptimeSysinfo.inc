[MeasureCurrentTime]
Measure=Time

[MeasureUserLoginTime]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_LOGONTIME
UpdateDivider=-1

[MeasureUptime]
Measure=UpTime
SecondsValue=([MeasureCurrentTime:] - [MeasureUserLoginTime:])
Format="%3!i!h %2!02i!m %1!02i!s"
DynamicVariables=1
