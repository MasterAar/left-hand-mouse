#include <HID-Project.h>

const int HALL_EFFECT = 2;
int ticks = 0;

void setup() {
  Serial.begin(9600);
  Consumer.begin();
  
  pinMode(HALL_EFFECT, INPUT);
  attachInterrupt(digitalPinToInterrupt(HALL_EFFECT), tick, FALLING);
}

void loop() {
  Serial.println("Waiting for input | " + String(ticks) + " | " + digitalRead(HALL_EFFECT));
  delay(100);
}

void tick() {
  Serial.println("Tick, tock, I'm a clock | " + String(++ticks));
  if(ticks % 2 == 0) Consumer.write(MEDIA_VOL_UP);
  else Consumer.write(MEDIA_VOL_DOWN);
}

