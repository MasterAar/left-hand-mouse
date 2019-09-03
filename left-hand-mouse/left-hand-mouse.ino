/* Consumer.begin();
   Consumer.write(MEDIA_VOL_UP);
   Consumer.write(MEDIA_VOL_DOWN);
   Consumer.write(MEDIA_VOL_MUTE);
*/

#include <HID-Project.h>

const int SEN_0 = 2;
const int SEN_1 = 3;
const int MOTOR = 9;

int typedChars = 0;
double counter = 0;
double bad_increment[] = {0.05, 0.5, 5}; // millimeters
double good_increment[] = {0.01, 0.05, 0.5}; // inches
unsigned long lastWrite = 0;

void setup() {
  Serial.begin(9600);
  //Keyboard.begin();

  pinMode(MOTOR, OUTPUT);
  pinMode(SEN_0, INPUT);
  pinMode(SEN_1, INPUT);
  attachInterrupt(digitalPinToInterrupt(SEN_0), checkDir, FALLING);
}

void loop() {
  Serial.println(String(digitalRead(SEN_0)) + " | " + String(digitalRead(SEN_1)));
  Serial.println(String(counter));
  delay(50);
}

void deleteChars(int num) {
  for (int i = 0; i < num; i++) {
    Keyboard.write(KEY_BACKSPACE);
    Serial.println("deleting");
  }
}

void checkDir() {
  if (millis() - lastWrite > 150) {
    lastWrite = millis();
    deleteChars(typedChars);

    if (digitalRead(SEN_1)) {
      counter -= good_increment[1];
      Serial.println("CCW");
    } else {
      counter += good_increment[1];
      Serial.println("CW");
    }

    Keyboard.print(String(counter));
    typedChars = String(counter).length();
  }
}

