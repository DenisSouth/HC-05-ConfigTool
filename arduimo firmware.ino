#include <SoftwareSerial.h>

/*
--------hc-05------
pin   
1  txd 
2  rxd 
12 +3.3v
13 0v
34 for config - connect to +3.3v
31 state led

-----board--------
brd pin  - ard pin
1        >   9
2        >   10
3        >   +3v
4        >   +0v
*/

SoftwareSerial BTSerial(9, 10);
 
void setup() {
  BTSerial.begin(38400);
  Serial.begin(38400);
  delay(500);
}
 
void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
