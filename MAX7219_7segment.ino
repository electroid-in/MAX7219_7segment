#include "LedControl.h"

// Pins: DIN, CLK, LOAD
const int DIN_PIN = 11;
const int CLK_PIN = 13;
const int LOAD_PIN = 10;

// 1 device (one MAX7219 module)
LedControl lc = LedControl(DIN_PIN, CLK_PIN, LOAD_PIN, 1);

void setup() {
  lc.shutdown(0, false);   // Wake up MAX7219
  lc.setIntensity(0, 8);   // Brightness (0-15)
  lc.clearDisplay(0);      // Clear display
}

void loop() {
  // Start counting from 0000 to 9999
  for (int number = 0; number <= 9999; number++) {
    int units     = number % 10;
    int tens      = (number / 10) % 10;
    int hundreds  = (number / 100) % 10;
    int thousands = (number / 1000) % 10;

    // Display digits: 0 = leftmost, 3 = rightmost
    lc.setDigit(0, 3, units, false);     // Rightmost
    lc.setDigit(0, 2, tens, false);
    lc.setDigit(0, 1, hundreds, false);
    lc.setDigit(0, 0, thousands, false); // Leftmost

    delay(100); // Adjust speed
  }
}

