[MeasureState]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=State

[MeasureStateButton]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=State
Substitute="0":"Play","1":"Pause","2":"Play"

[MeasureTrack]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Title
;Substitute="":"#NoTrackNameText#"

[MeasureArtist]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Artist
;Substitute="":"#NoArtistNameText#"

[MeasureCover]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Cover
DefaultPath=#@#Images\nocover.png
CoverPath=#@#Covers\WebNowPlaying.png
Substitute="":"#@#Images\nocover.png"

[MeasurePosition]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Position

[MeasureDuration]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Duration

[MeasureProgress]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Progress

;[MeasureAutoHideRainmeterPot]
;Measure=Plugin
;Plugin=RainmeterPot
;PlayerType=Status
;IfBelowValue=1
;IfBelowAction=[!HideFadeGroup "Spectrum"][!HideFadeGroup "SongInfo"][!Log "AutoHide: WebNowPlaying was closed, hiding skin"]
;IfAboveValue=0
;IfAboveAction=[!ShowFadeGroup "Spectrum"][!ShowFadeGroup "SongInfo"][!Log "AutoHide: WebNowPlaying was opened, showing skin"]
;Disabled=(#EnableAutoHide# > 0 ? 0 : 1)
;UpdateDivider=100