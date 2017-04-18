#include "Energia.h"

#line 1 "C:/Users/cdgja/Documents/University of Pittsburgh/COE 1188 Cyber Physical Systems/BopIt/Microcontroller/SpeakerTest/SpeakerTest.ino"

#include "sound_data.h"
#include "msp432p401r.h"

void setup();
void loop();

#line 5
void setup() {
  
  
    P2SEL0=0x80;
    P2SEL1=0x80;





    pinMode(40, OUTPUT);
}




































void loop() {
  for( int x = 0; x < sizeof(bopit_sound[x]) / sizeof(*bopit_sound); x++){
      analogWrite( 40, bopit_sound[x] );
      delayMicroseconds(8);
  }
  digitalWrite( A13, 0);
  
}



