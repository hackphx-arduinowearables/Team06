#include <Wire.h>
#include "xadow.h"

#include <TinyGPS++.h>
#define SerialBaud   9600
#define Serial1Baud  9600




double pointLat = 33.415618;
double pointLon = -111.838117;

  
// The TinyGPS++ object
TinyGPSPlus gps;

void setup()
{
  Serial.begin(SerialBaud);
  Serial1.begin(Serial1Baud);
}

void loop()
{
    while (Serial1.available() > 0)
    if (gps.encode(Serial1.read())){
      displayInfo();
    }
  
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    /*
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
    */


            Serial.println("calculated Distance");
           // Serial.println( (abs(gps.location.lat()) - abs(pointLat)), 6 );
            Serial.println(distanceBetween(gps.location.lat(), gps.location.lng(), pointLat, pointLon));
            //Serial.println("calculated lon");
            //Serial.println( (abs(gps.location.lng()) - abs(pointLon)), 6 );





  }
  else
  {
    Serial.print(F("INVALID"));
  }


  Serial.println();
}
