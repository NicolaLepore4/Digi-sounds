# DigiSounds - Custom System Sounds Changer

⚠️ **Disclaimer**: Use this script only on systems you own and with proper authorization. Modifying system settings can cause instability. The author is not responsible for any misuse or damage.

## Features
- 🔁 Toggle mode: Switches between custom sound and original Windows sounds
- 🔊 Modifies multiple system events:
  - Windows Startup (`SystemStart`)
  - USB Device Connection (`DeviceConnect`)
  - Power Events (`Power`)
- 📥 Automatic download from GitHub repository
- 🗑️ Clean uninstall when restoring original sounds

## Requirements
- Digispark Attiny85 board
- Arduino IDE with DigiKeyboard library
- Windows system (tested on 10/11)
- `fart.wav` file in [GitHub repo](https://github.com/NicolaLepore4/Digi-sounds)

## Installation & Usage

1. **Clone Repository**:
   ```bash
   git clone https://github.com/NicolaLepore4/Digi-sounds.git
   ```

2. **Configure Script**:
   Open `DigiSound.ino` and verify:
   ```arduino
   $customUrl = 'https://raw.githubusercontent.com/NicolaLepore4/Digi-sounds/main/sounds/fart.wav';
   ```

3. **Upload to Digispark**:
   - Connect Digispark
   - Compile and upload script using Arduino IDE

4. **Execution**:
   - Insert device: sets custom sound
   - Reinsert device: restores original sounds

## Configuration
Customize these variables in the script:
```arduino
// Events to modify (add/remove as needed)
$events = @(
    @{ Name='SystemStart';    Original='Windows Startup.wav' },
    @{ Name='DeviceConnect'; Original='Device Connect.wav' },
    @{ Name='Power';         Original='Windows Battery Low.wav' }
);

// Custom sound path (GitHub raw URL)
$customUrl = 'https://raw.githubusercontent.com/NicolaLepore4/Digi-sounds/main/sounds/fart.wav';
```

## Safety & Precautions
- 🔒 Test in virtual machine first
- ⚠️ Disable antivirus temporarily (may flag PS commands)
- ✔️ Verify file hash of `fart.wav` before use
- 💻 Compatible with most Windows versions (PS 5.1+ required)

## FAQ

**Q: How does the toggle mechanism work?**  
A: The script checks registry entries - if custom sound is detected, it restores originals.

**Q: Can I use different sounds for different events?**  
A: Modify the script to use multiple sound files and adjust the event handling logic.

**Q: How to completely uninstall?**  
A: Run the script twice (second run removes all traces).

**Q: The script doesn't work on my PC**  
- Check PowerShell execution policy: `Set-ExecutionPolicy RemoteSigned`
- Verify internet connection for file download
- Test Digispark with basic keyboard example first

## Contributing
PRs are welcome for:
- Additional system events
- Improved error handling
- Cross-platform support
- GUI configuration tools

## License
MIT License - See [LICENSE](LICENSE) file

This README includes:
1. Clear usage instructions
2. Safety warnings
3. Configuration options
4. Troubleshooting section
5. Contribution guidelines
6. License information

Adjust the repository links and paths according to your actual GitHub structure. Consider adding:
- Screenshots of the process
- Video demonstration link
- SHA256 hash of the sound file
- Legal disclaimer specific to your country
