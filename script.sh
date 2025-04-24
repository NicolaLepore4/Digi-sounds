$backupDir = "$env:APPDATA\DigiSounds"
$backupFile = "$backupDir\backup.reg"
$soundUrl = "https://github.com/NicolaLepore4/Digi-sounds/raw/main/sounds/sound.wav"
$soundFile = "$backupDir\sound.wav"

if (-not (Test-Path $backupFile)) {
    New-Item -ItemType Directory -Force -Path $backupDir | Out-Null
    reg export "HKEY_CURRENT_USER\AppEvents\Schemes\Apps\.Default" $backupFile
    Invoke-WebRequest -Uri $soundUrl -OutFile $soundFile
    $events = Get-ChildItem -Path "HKCU:\AppEvents\Schemes\Apps\.Default" -Recurse | Where-Object { $_.PSChildName -eq ".Current" }
    foreach ($event in $events) {
        Set-ItemProperty -Path $event.PSPath -Name "(Default)" -Value $soundFile
    }
} else {
    reg import $backupFile
    Remove-Item $backupFile -ErrorAction SilentlyContinue
    Remove-Item $soundFile -ErrorAction SilentlyContinue
    Remove-Item $backupDir -Recurse -ErrorAction SilentlyContinue
}
