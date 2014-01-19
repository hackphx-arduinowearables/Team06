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

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

