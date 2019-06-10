[MeasureState]
Measure=Plugin
Plugin=NowPlaying
Playername=Spotify
PlayerType=State

[MeasureStateButton]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Playing
Substitute="0":"Play","1":"Pause","2":"Play"

[MeasureTrack]
Measure=Plugin
Plugin=SpotifyPlugin
Type=TrackName
Substitute="":"#NoTrackNameText#"

[MeasureArtist]
Measure=Plugin
Plugin=SpotifyPlugin
Type=ArtistName
Substitute="":"#NoArtistNameText#"

[MeasureAlbum]
Measure=Plugin
Plugin=SpotifyPlugin
Type=AlbumName
Substitute="":"#NoArtistNameText#"

[MeasureCover]
Measure=Plugin
Plugin=SpotifyPlugin
Type=AlbumArt
Res=120
CoverPath=#@#Covers\Spotify.png

[MeasurePosition]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Position

[MeasureDuration]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Length

[MeasureProgressPrecent]
Measure=Plugin
Plugin=SpotifyPlugin
Type=Progress

[MeasureProgress]
Measure=Calc
Formula=MeasureProgressPrecent*100
