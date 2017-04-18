
#include "sound_data.h"
#include "msp432p401r.h"

void setup() {
  //P1DIR = 0b01000000;
  //analogFrequency(62500);
    P2SEL0=0x80;
    P2SEL1=0x80;

//  for( int x = 0; x < sizeof bopit_sound[x] / sizeof *bopit_sound; x++){
//      analogWrite( A12, bopit_sound[x] );
//      delayMicroseconds(8);
//  }
    pinMode(40, OUTPUT);
}

//void delay_ms(unsigned int ms )
//{
//    unsigned int i;
//    for (i = 0; i<= ms; i++)
//       __delay_cycles(3000); //Built-in function that suspends the execution for 3000 cycles
//}
//
//void delay_us(unsigned int us )
//{
//    unsigned int i;
//    for (i = 0; i<= us/2; i++)
//       __delay_cycles(3);
//}
//
//play_sound(unsigned int pitch, unsigned int duration){
//    int i;
//    long delay = (long)(32000/pitch);  //This is the semiperiod of each note.
//    long time = (long)((duration*100)/(delay*2));  //This is how much time we need to spend on the note.
//    for (i=0;i<time;i++)
//    {
//        P4OUT |= BIT1;     //Set P4.1...
//        //delay_us(delay);   //...for a semiperiod...
//        __delay_cycles();
//        P4OUT &= ~BIT1;    //...then reset it...
//        //delay_us(delay);   //...for the other semiperiod.
//        __delay_cycles();
//    }
//}
//
//play_soundfile(){
//    for( int x = 0; x < sizeof(bopit_sound[x]) / sizeof(*bopit_sound); x++){
//          play_sound(bopit_sound[x],375)
//      }
//}

void loop() {
  for( int x = 0; x < sizeof(bopit_sound[x]) / sizeof(*bopit_sound); x++){
      analogWrite( 40, bopit_sound[x] );
      delayMicroseconds(8);
  }
  digitalWrite( A13, 0);
  //delay( 1000000 );
}
