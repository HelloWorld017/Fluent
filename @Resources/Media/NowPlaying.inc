[MeasureState]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=State

[MeasureStateButton]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=STATE
Substitute="0":"Play","1":"Pause","2":"Play"

[MeasureTrack]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=TITLE
Substitute="":"#NoTrackNameText#"

[MeasureArtist]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=ARTIST
Substitute="":"#NoArtistNameText#"

[MeasureCover]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=COVER

[MeasurePosition]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=Position

[MeasureDuration]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=DURATION

[MeasureProgress]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=Progress
