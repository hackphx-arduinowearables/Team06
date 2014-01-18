#include <Wire.h>
#include "xadow.h"

#include <TinyGPS++.h>
#define SerialBaud   9600
#define Serial1Baud  9600




double pointLat = 33.415618;
double pointLon = -111.838117;

  
// The TinyGPS++ object
TinyGPSPlus gps;

void setup(){
  Serial.begin(SerialBaud);
  Serial1.begin(Serial1Baud);
}

void loop(){
    while (Serial1.available() > 0)
    if (gps.encode(Serial1.read())){
      displayInfo();
    }
  
}

void displayInfo(){
  Serial.print(F("Location: ")); 
  if (gps.location.isValid()){


    Serial.println("calculated Distance");
    double locDist = gps.distanceBetween(gps.location.lat(), gps.location.lng(), pointLat, pointLon);
    Serial.println(locDist);

  }
  else{
    Serial.print(F("INVALID"));
  }


  Serial.println();
}
