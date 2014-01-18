/*
 * Test sketch for Xadow LED 5x7 Matrix. 
 * http://www.seeedstudio.com/depot/xadow-led-p-1518.html
 * Part of the Xadow line of miature and wearable electronics.
 * http://www.seeedstudio.com/wiki/Xadow
 *
 * This sketch presents a menu when you open the Serial Console
 * for you to select and view the various modes of the 5x7 Matrix
 *
 * Check out the wiki page for more info
 * http://www.seeedstudio.com/wiki/Xadow_LED_5X7
 * 
 * Seeed Studios is an Open Hardware company. Support our contributions by buying
 * our products! http://www.seeedstudio.com/
 */

#include <Wire.h>
#include <LEDMatrix.h>

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

void setup()
{
    Serial.begin(115200);
    while(!Serial);
    Serial.println("hello world");
    
    fiveBySeven.setDir(DIR_NORMAL);
}

void loop()
{
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
