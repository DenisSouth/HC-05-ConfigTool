#include "DHT.h"
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(9, 10);

DHT dht(6, DHT22);


void setup(){
  BTSerial.begin(38400);
  Serial.begin(57600);
  dht.begin();
}

String feed = "";
void loop(){
  


  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, h, false);
  float gas = analogRead(A0);
  

  feed = ">" + String(gas) + ";" + String(h) + ";" + String(t) + ";" + String(hic)+  "<";
  Serial.print(feed);
  BTSerial.print(feed);
  delay(1000);
}
