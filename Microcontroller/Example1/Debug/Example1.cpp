#include "Energia.h"

#line 1 "C:/Users/cdgja/Documents/University of Pittsburgh/COE 1188 Cyber Physical Systems/BopIt/Microcontroller/Example1/Example1.ino"














void setup();
void loop();

#line 15
void setup() {
  
  Serial.begin(9600); 
}


void loop() {
  
  int sensorValue = analogRead(A12);
  
  Serial.println(sensorValue);
  delay(1); 
}



