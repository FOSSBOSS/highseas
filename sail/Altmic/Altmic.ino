#include <Keyboard.h>
#include <Bounce2.h>
// built on a teensy 4.0
#define left_mic 0
#define rght_mic 1
#define fwd_mic  2
/*
Ambient Noise appears to be 370-390 analog read 3VDC
direct air on sensor appears to be 700-800

ok might as well do a tug-o-war thing here.

*/
void setup() {
//micropfine chip max9814
Serial.begin(19200);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
Keyboard.begin();
}

void loop() {
  Serial.println(analogRead(0));
  Serial.println(analogRead(1));
  Serial.println(analogRead(2));
  
}
