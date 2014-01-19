#include <Wire.h>
#include <LEDMatrix.h>

#include <Adafruit_NeoPixel.h>

#define PIN A5

#define ADDRESS 0x04

unsigned char data[5] = {
  0b1010101,
  0b0101010,
  0b1010101,
  0b0101010,
  0b1010101,
};

unsigned char data2[5] = {
  0b0101010,
  0b1010101,
  0b0101010,
  0b1010101,
  0b0101010,
};

LEDMatrix fiveBySeven = LEDMatrix(ADDRESS);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    Serial.begin(115200);
    while(!Serial);
    Serial.println("hello world");
    
    fiveBySeven.setDir(DIR_NORMAL);
    
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  colorWipe(strip.Color(255, 255, 0), 50); // Probably Yellow.
  
  fiveBySeven.setPoint(2, 5, 1);
    delay(100);
    fiveBySeven.setPoint(3, 4, 1);
    delay(100);
    fiveBySeven.setPoint(1, 4, 1);
    delay(100);
    fiveBySeven.setPoint(4, 3, 1);
    delay(100);
    fiveBySeven.setPoint(4, 2, 1);
    delay(100);
    fiveBySeven.setPoint(3, 2, 1);
    delay(100);
    fiveBySeven.setPoint(2, 2, 1);
    delay(100);
    fiveBySeven.setPoint(1, 2, 1);
    delay(100);
    fiveBySeven.setPoint(0, 2, 1);
    delay(100);
    fiveBySeven.setPoint(0, 3, 1);
    delay(1000);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
