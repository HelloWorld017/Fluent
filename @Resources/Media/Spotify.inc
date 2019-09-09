[SpotifyMeasureState]
Measure=NowPlaying
Playername=Spotify
PlayerType=State

[SpotifyMeasureTrack]
Measure=Plugin
Plugin=SpotifyPlugin
Type=TrackName
Substitute="":"#NoTrackNameText#"

[SpotifyMeasureArtist]
Measure=Plugin
Plugin=SpotifyPlugin
Type=ArtistName
Substitute="":"#NoArtistNameText#"

[SpotifyMeasureCover]
Measure=Plugin
Plugin=SpotifyPlugin
Type=AlbumArt
Res=120
CoverPath=#@#Covers\Spotify.png

[SpotifyMeasurePosition]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Position

[SpotifyMeasureDuration]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Length

[SpotifyMeasureProgressPrecent]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Progress

[SpotifyMeasureProgress]
Measure=Calc
Formula=MeasureProgressPrecent*100
