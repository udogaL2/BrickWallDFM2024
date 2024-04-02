#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>
 
SoftwareSerial mySerial(12, 11);
DFPlayerMini_Fast myMP3;

int irsensor= 7;
int sensorvalue; 

void setup()
{
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.volume(20);
  pinMode(irsensor,INPUT);
}
void loop()
{
  sensorvalue=digitalRead(irsensor);
  if (sensorvalue > 0)
  {
    myMP3.play(1);

    delay(3000);

    sensorvalue=digitalRead(irsensor);

    while (sensorvalue)
    {
      sensorvalue=digitalRead(irsensor);
      delay(100);
    }

    myMP3.stop();
  }
} 