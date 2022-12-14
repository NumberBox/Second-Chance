; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "OC_Kursa_Second_chance"
#define MyAppVersion "1.0"
#define MyAppPublisher "SPBGTI(TY), Inc."
#define MyAppURL "http://technolog.edu.ru/"
#define MyAppExeName "OC_Kursa1.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{3131CA70-973B-44BA-A1F1-EDF28303EA88}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
; The [Icons] "quicklaunchicon" entry uses {userappdata} but its [Tasks] entry has a proper IsAdminInstallMode Check.
UsedUserAreasWarning=no
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
OutputDir=A:\Decktop\Admin\OC_Kursa_Setup
OutputBaseFilename=OC_Kursa_Second_chance_setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 6.1; Check: not IsAdminInstallMode

[Files]
Source: "A:\Decktop\Admin\OC_kursa\OC_Kursa1.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\Dll1_Oc_test.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\msvcp140d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\test_file.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\test_file_2.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\ucrtbased.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\vcruntime140d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "A:\Decktop\Admin\OC_kursa\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

