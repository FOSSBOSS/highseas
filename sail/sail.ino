#include <Keyboard.h>
#include <Bounce2.h>

// Define IO Pins
#define aleft  0  // left key
#define arght  2  // right key
#define afwd   1  // forward key
#define aRFWD  3  // forward-right key
#define aLFWD  4  // forward-left key
#define arota  5  // right rotate key
#define arset  6  // reset position
#define azmin  7  // zoom in
#define azout  8  // zoom out
#define alrota 9  // left rotate
#define azmax  10 // zoom out

// Create Bounce objects for buttons
Bounce left = Bounce();
Bounce rght = Bounce();
Bounce fwd = Bounce();
Bounce RFWD = Bounce();
Bounce LFWD = Bounce();
Bounce rota = Bounce();
Bounce rset = Bounce();
Bounce zmin = Bounce();
Bounce zout = Bounce();
Bounce lrota = Bounce();
Bounce zmax = Bounce();

void setup() {
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

  Serial.begin(19200);
  delay(3000);

  Keyboard.begin();
}

void loop() {
  left.update();
  rght.update();
  fwd.update();
  RFWD.update();
  LFWD.update();
  rota.update();
  rset.update();
  zmin.update();
  zout.update();
  zmax.update();
  lrota.update();

  // Handle button presses with debouncing
  if (left.fell()) {
    Keyboard.press(KEY_LEFT);
    Keyboard.release(KEY_LEFT);
  }
  if (rght.fell()) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_RIGHT);
    Keyboard.release(KEY_RIGHT);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
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
}
