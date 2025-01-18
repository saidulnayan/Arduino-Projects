#include<Servo.h>
Servo servo1;
String voice;



void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  servo1.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(voice=="UP")
  {
    servo1.write(90);
    delay(500);
  }
  else if (voice == "DOWN")
  {
      servo1.write(0);
      delay (500);
  }
 }
