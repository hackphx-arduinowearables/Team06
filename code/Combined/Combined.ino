#include <Wire.h>
#include "xadow.h"
#include <TinyGPS++.h>
#include <LEDMatrix.h>
#include <Adafruit_NeoPixel.h>

// GPS
#define SerialBaud   9600
#define Serial1Baud  9600

// LED Strip
#define PIN A5
#define ADDRESS 0x04


// GPS
double pointLat = 33.415348;
double pointLon = -111.834968;
TinyGPSPlus gps;


// LED
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



// GPS delay for all LEDS
void GPSDelay(int GPSdel){
	long t = millis();
	while(t + GPSdel > millis()){
		if(Serial1.available() > 0){
			gps.encode(Serial1.read());
		}
	}
}



// LED Strip
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      GPSDelay(wait);
  }
}


void setup()
{
	Serial.println("START");
	// GPS
  Serial.begin(SerialBaud);
  Serial1.begin(Serial1Baud);

    // LED MATRIX
    fiveBySeven.setDir(DIR_NORMAL);
    // LED Strip
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    colorWipe(strip.Color(0, 0, 255), 50); // Blue
}


void loop(){
	// GPS
    while (Serial1.available() > 0){

    	gps.encode(Serial1.read());
      
    }
    displayInfo();
    Serial.println("LOOP EFFECT");

	}	  
  





void iconCheck(){
    //Good Checkmark

	fiveBySeven.setPoint(0, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(1, 4, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(3, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(4, 3, 1);
	GPSDelay(5);
}

void iconSmile(){
// Safe Smiley-face
    
    fiveBySeven.setPoint(4, 2, 1);
    GPSDelay(5);
    fiveBySeven.setPoint(3, 1, 1);
    GPSDelay(5);
    fiveBySeven.setPoint(2, 1, 1);
    GPSDelay(5);
    fiveBySeven.setPoint(1, 1, 1);
    GPSDelay(5);
    fiveBySeven.setPoint(0, 2, 1);
    GPSDelay(5);
    fiveBySeven.setPoint(3, 4, 1);
    GPSDelay(5);
    fiveBySeven.setPoint(1, 4, 1);
    GPSDelay(5);	
}

void iconArrow(){
	fiveBySeven.setPoint(2, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(3, 4, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(1, 4, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(4, 3, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(4, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(3, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(2, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(1, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 3, 1);	
}

void iconSkull(){
fiveBySeven.setPoint(1, 0, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(2, 0, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(3, 0, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 1, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(2, 1, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(4, 1, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(2, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(4, 2, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(2, 3, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(1, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(2, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(3, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(4, 5, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 6, 1);
	GPSDelay(5);
	fiveBySeven.setPoint(0, 4, 1);
	GPSDelay(5);	
}
// GPS
void displayInfo(){
  if (gps.location.isValid()){


    Serial.println("calculated Distance");
    double locDist = gps.distanceBetween(gps.location.lat(), gps.location.lng(), pointLat, pointLon);
    Serial.println(locDist);
    
    if(locDist > 75){
   	
   	iconSmile();
	colorWipe(strip.Color(0, 255, 0), 50); // Green
	//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
 
    }
    else if(locDist < 75 && locDist > 50){
    	iconArrow();
		colorWipe(strip.Color(255, 255, 0), 50); // Probably Yellow.     
    }
    else if(locDist < 50){
      colorWipe(strip.Color(255, 0, 0), 50); // Red
      iconSkull();
    }
    else {
    	colorWipe(strip.Color(0, 0, 255), 50); // Blue
    }

  }
  else{
    Serial.print(F("INVALID"));
    colorWipe(strip.Color(0, 0, 255), 50); // Blue
  }


  Serial.println();
}

