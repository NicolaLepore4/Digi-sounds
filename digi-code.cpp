#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0); // Inizializza
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -NoProfile -ExecutionPolicy Bypass -Command \"$u='https://raw.githubusercontent.com/tuo-utente/tuo-repo/main/suoni/Avvio.wav';$d=$env:APPDATA+'\\SuoniPersonalizzati\\Avvio.wav';if(!(Test-Path -Path ($env:APPDATA+'\\SuoniPersonalizzati'))){New-Item -ItemType Directory -Path ($env:APPDATA+'\\SuoniPersonalizzati')};Invoke-WebRequest -Uri $u -OutFile $d;Set-ItemProperty -Path 'HKCU:\\AppEvents\\Schemes\\Apps\\.Default\\SystemStart\\.Current' -Name '(Default)' -Value $d\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  // Nessuna azione nel loop
}
