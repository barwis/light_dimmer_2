// display.cpp
#include "display.h"

#if !defined(_ADAFRUIT_GFX_H)
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#endif


Display::Display(int SDA_PIN, int SCL_PIN) {
    int _SDA_PIN = SDA_PIN;
    int _SCL_PIN = SCL_PIN;
    Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire, -1);
    Wire.begin(/*SDA*/ SDA_PIN, /*SCL*/ SCL_PIN);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    if (Serial) {
      Serial.println(F("SSD1306 allocation failed"));
    }
    for (;;)
      ;  // Don't proceed, loop forever
  }
}

void Display::clear() {
  display.clearDisplay();
}

void Display::print() {
  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(56, 14);
  display.println('test');
  display.display();
}

int Display::getSum()
{
  return 42;
}
