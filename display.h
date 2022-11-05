// display.h
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <pins_arduino.h>

class Display {
    int _SDA_PIN;
    int _SCL_PIN;
    Adafruit_SSD1306 display;

public:
    Display(int SDA_PIN, int SCL_PIN);
    void clear();
    void print();
    int getSum();
};

#endif