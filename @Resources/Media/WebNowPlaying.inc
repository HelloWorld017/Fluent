[WebNowPlayingMeasureState]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State

[WebNowPlayingMeasureTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
;Substitute="":"#NoTrackNameText#"

[WebNowPlayingMeasureArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
;Substitute="":"#NoArtistNameText#"

[WebNowPlayingMeasureCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\nocover.png
CoverPath=#@#Covers\WebNowPlaying.png
Substitute="":"#@#Images\nocover.png"

[WebNowPlayingMeasurePosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position

[WebNowPlayingMeasureDuration]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration

[WebNowPlayingMeasureProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
