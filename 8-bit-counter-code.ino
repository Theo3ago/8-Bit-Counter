// --- Pin Definitions --
// these constants define which arduino digital input/output pins are connected to the shift register input pins.
int clearPin = 5; //connected to the shift registers master reset pin -which clears all inputs
int SerialData = 6;//connected to the serial data pin-sends in the bits one by one
int shiftClock = 7;//connected to the Shift Register Clock pin- each rising edge shifts in one bit
int latchClock = 8;//connected to the register clock/Latch pin-updates the led pins when pulsed.


//set up function
//runs once when the arduino starts up
void setup(){


  //sets all shift register control pins as outputs to the shift register
 //sending signals to the shift register not reading from it.
 pinMode(clearPin,OUTPUT);
 pinMode(shiftClock,OUTPUT);
 pinMode(latchClock,OUTPUT);
 pinMode(SerialData,OUTPUT);
 //clears the shift register before starting.
 // the master reset input(clearPin) is active low-which resets all outputs to 0
 digitalWrite(clearPin,LOW);
 digitalWrite(clearPin,HIGH);//returns to high to resume normal operation
 }
// --loop function---
// runs continuously after setup() completes assuming no fatal errors, and arduino is powered.
void loop(){
 for (int shiftCount = 0; shiftCount < 256;shiftCount++){
   // count from 0 to 255 and display the number on the leds
   // representing every possible 8-bit binary value (00000000 to 11111111)
   // each value corresponds to which LED is on or off
 digitalWrite(latchClock,LOW);
     // take the latchClock low so
     // the LEDS don't change while you're sending in bits(freezes the inputs)


 shiftOut(SerialData,shiftClock,MSBFIRST, shiftCount);
 //sends 1 byte(8 bits) of data to the shift register
 //starting with the most important bit(MSBFIRST)
 //each bit corresponds to a LED On(1) or Off(0)
 //shiftclock is pulsed automatically during this


 digitalWrite(latchClock,HIGH);
 //once all 8 bits are sent, it pulses the latch on high
 //tells the shift register to 'copy' the 8 bits from its own storage and output its output pins lighting up the LED's
 delay(500);
 //delay of 500 milliseconds to allow significant time to view the number before it changes and as well so you can see it counting.
 }
}
