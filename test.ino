#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <pins_arduino.h>
// #include "display.h"

#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 32     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define OLED_SDA D6
#define OLED_SCL D7

Adafruit_SSD1306 display;

void setup() {
  // put your setup code here, to run once:
  display = Adafruit_SSD1306(128, 32, &Wire, OLED_RESET);;
  Serial.begin(9600);
  // Display myDisplay(D6, D7);
  // init display
  Wire.begin(/*SDA*/ OLED_SDA, /*SCL*/ OLED_SCL);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // myDisplay.clear();
  // myDisplay.print();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("OK!");
  display.clearDisplay();
  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(56, 14);
  display.println("test");
  display.println(millis());
  display.display();
  delay(1000);
}
