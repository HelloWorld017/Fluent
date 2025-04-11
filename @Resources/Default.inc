[Variables]
Version=1.11

@IncludeVariables=Variables.inc
@IncludeTheme=Themes/#Theme#.inc
@IncludeThemeBackground=Themes/Background/#ThemeBackground#.inc
@IncludeBackground=Layouts/Background.inc
@IncludeIcons=Icons.inc

[MeasureOrganizer]
Measure=Script
ScriptFile=#@#Scripts/Organizer.lua
Disabled=(#OrganizerEnabled# = 1 ? 0 : 1)