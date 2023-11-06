#include <LedControl.h>

// the pins used to connect to the MAX7219 LED controller
constexpr auto DIN = 11, CLK = 13, CS = 10;
LedControl lc = LedControl(DIN, CLK, CS, 0);
void setup()
{
  // turn off power saving mode for the MAX7219
  lc.shutdown(0, false);
  // set the brightness of the LEDs
  lc.setIntensity(0, 0);
  // clear the display, in case it still has junk on it
  lc.clearDisplay(0);

  // start serial communication for game control
  Serial.begin(9600);
}

void loop()
{
  // storage for current field
  static int row = 0, col = 0;
  // read input from serial
  if (Serial.available())
  {
    char input = Serial.read();
    lc.setLed(0, row, col, false);
    // move player based on input
    switch (input)
    {
    case 'w': // up
      (row == 7) ? row = 0 : row++;
      break;
    case 's': // down
      (row == 0) ? row = 7 : row--;
      break;
    case 'a': // left
      (col == 0) ? col = 7 : col--;
      break;
    case 'd': // right
      (col == 7) ? col = 0 : col++;
      break;
    default:
      break;
    }
    lc.setLed(0, row, col, true);
  }
}