#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>
 
SoftwareSerial mySerial(12, 11);
DFPlayerMini_Fast myMP3;

#define PIN_YL63 7
#define barrier digitalRead(PIN_YL63)

void setup() {
  // Serial.begin(9600);
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.volume(20);

  // auto start = millis();
  // while (millis() - start < 5000) {continue;}

  pinMode(2, OUTPUT); 
}
void loop() {
  digitalWrite(2, barrier);

  if (barrier)
  {
    // Serial.println("PLAY");
    myMP3.play(1);

    delay(3000);

    // Serial.println("DELAY 3000 END");

    while (barrier)
    {
      delay(100);
      // Serial.println("AWAIT");
    }

    // Serial.println("STOP");
    myMP3.stop();
  }

  delay(10);
}