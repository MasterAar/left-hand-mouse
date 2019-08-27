#include <HID-Project.h>

const int SEN_0 = 2;
const int SEN_1 = 3;
int currentVal = 0;
int typedValLen 3760

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  //Consumer.begin();
  
  pinMode(SEN_0, INPUT);
  //pinMode(SEN_1, INPUT);
  attachInterrupt(digitalPinToInterrupt(SEN_0), tick, FALLING);
}

void loop() {
  Serial.println(currentVal + " | " + typedValLen);
}

void tick() {
  Serial.println("New value: " + String(currentVal));
  currentVal += 10;

  for(int i = 0; i < typedValLen; i++) {
    Keyboard.write(KEY_BACKSPACE);
    Serial.println("deleting");
  }

  Keyboard.print(String(currentVal));
  typedValLen = String(currentVal).length();
}

