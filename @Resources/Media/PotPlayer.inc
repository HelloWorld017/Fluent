[PotPlayerMeasureState]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=State

[PotPlayerMeasureStateButton]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=State
Substitute="0":"Play","1":"Pause","2":"Play"

[PotPlayerMeasureTrack]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Title
;Substitute="":"#NoTrackNameText#"

[PotPlayerMeasureArtist]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Artist
;Substitute="":"#NoArtistNameText#"

[PotPlayerMeasureCover]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Cover
DefaultPath=#@#Images\nocover.png
CoverPath=#@#Covers\WebNowPlaying.png
Substitute="":"#@#Images\nocover.png"

[PotPlayerMeasurePosition]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Position

[PotPlayerMeasureDuration]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Duration

[PotPlayerMeasureProgress]
Measure=Plugin
Plugin=RainmeterPot
PlayerType=Progress
