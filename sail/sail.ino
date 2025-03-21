#include <Keyboard.h>
#include <Bounce2.h>

#define left_mic 0
#define rght_mic 1
#define fwd_mic  2

// Create Bounce objects for buttons
Bounce left = Bounce();
Bounce rght = Bounce();
Bounce fwd = Bounce();

void setup() {

  Serial.begin(19200);
 // delay(3000);
pinMode(0, INPUT_PULLUP);
pinMode(1, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP);

 int bounceTime = 1;
  // Attach buttons to Bounce objects and set debounce interval
  left.attach(left_mic, INPUT_PULLUP);
  left.interval(bounceTime);

  rght.attach(rght_mic, INPUT_PULLUP);
  rght.interval(bounceTime);

  fwd.attach(fwd_mic, INPUT_PULLUP);
  fwd.interval(bounceTime);
Keyboard.begin();
}

void loop() {
  left.update();
  rght.update();
  fwd.update();

  // Handle button presses with debouncing
  if (left.fell()) {
    Serial.println("LEFT");
    Keyboard.press(KEY_LEFT);
    Keyboard.release(KEY_LEFT);
  }
  if (rght.fell()) {
    Serial.println("Riiight");
    Keyboard.press(KEY_RIGHT);
    Keyboard.release(KEY_RIGHT);
  }
  if (fwd.fell()) {
    Serial.println("Forward!");
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_UP_ARROW);
 
  }  

}
/*
  
  
  RFWD.update();
  LFWD.update();
  rota.update();
  rset.update();
  zmin.update();
  zout.update();
  zmax.update();
  lrota.update();


  if (RFWD.fell()) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_R);
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_R);
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  if (LFWD.fell()) {
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.press(KEY_R);
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_R);
  }
  if (rota.fell()) {
    Keyboard.press(KEY_R);
    Keyboard.release(KEY_R);
  }
  if (rset.fell()) {
    Keyboard.press(KEY_X);
    Keyboard.release(KEY_X);
  }
  if (zmin.fell()) {
    Keyboard.press(KEYPAD_MINUS);
    Keyboard.release(KEYPAD_MINUS);
  }
  if (zmax.fell()) {
    Keyboard.press(KEYPAD_PLUS);
    Keyboard.release(KEYPAD_PLUS);
  }
  if (lrota.fell()) {
    Keyboard.press(KEY_R);
    Keyboard.release(KEY_R);
  }
*/



  /*
  const int debounceInterval = 5;

  // Attach buttons to Bounce objects and set debounce interval
  left.attach(aleft, INPUT_PULLUP);
  left.interval(debounceInterval);
  
  rght.attach(arght, INPUT_PULLUP);
  rght.interval(debounceInterval);

  fwd.attach(afwd, INPUT_PULLUP);
  fwd.interval(debounceInterval);

  RFWD.attach(aRFWD, INPUT_PULLUP);
  RFWD.interval(debounceInterval);

  LFWD.attach(aLFWD, INPUT_PULLUP);
  LFWD.interval(debounceInterval);

  rota.attach(arota, INPUT_PULLUP);
  rota.interval(debounceInterval);

  rset.attach(arset, INPUT_PULLUP);
  rset.interval(debounceInterval);

  zmin.attach(azmin, INPUT_PULLUP);
  zmin.interval(debounceInterval);

  zout.attach(azout, INPUT_PULLUP);
  zout.interval(debounceInterval);

  zmax.attach(azmax, INPUT_PULLUP);
  zmax.interval(debounceInterval);

  lrota.attach(alrota, INPUT_PULLUP);
  lrota.interval(debounceInterval);
*/
