#include <Servo.h>

Servo h;
int pos = 0;
char c;
String voice = "";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  h.attach(7);

}

void loop() {
  servo_move();

}


void servo_move(){
  while(Serial1.available()){
    c = Serial1.read();
    voice = voice + c;
    Serial.println(c);
  }

  if(voice.length()>0){
    if(voice == "up"){
      for (pos = 0; pos <= 90; pos += 1) { 
      h.write(pos);              
      delay(80);                      
      }
    }
    else if(voice == "down"){
      for (pos = 90; pos >= 0; pos -= 1) { 
      h.write(pos);              
      delay(80);                       
      }
    }
    else{
      
    }
  voice = "";
  }
 delay(100);
}
