#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"

uint8_t buf[8] = { 0 }; //Keyboard report buffer
Talkie voice;

#define k11 2

#define k12 3

#define k21 4 

#define k22 5

#define k31 6

#define k32 7

#define enter 8 

#define speak 9 // speaker

void setup() {

Serial.begin(9600); // Setup Serial communication

//Set pinmode of Input pins

pinMode(k11, INPUT);

pinMode(k12, INPUT);

pinMode(k21, INPUT);

pinMode(k22, INPUT);

pinMode(k31, INPUT);

pinMode(k32, INPUT);

pinMode(enter, INPUT);

pinMode(speak, OUTPUT);

}

void loop() {

//When button press

if (digitalRead(enter) == HIGH) {

  if (digitalRead(k11) == HIGH && digitalRead(k12) == LOW && digitalRead(k21) == LOW && digitalRead(k22) == LOW && digitalRead(k31) == LOW && digitalRead(k32) == LOW) {
      buf[2] = 65; // a keycode
      voice.say(sp2_DANGER);
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    
    }
    if (digitalRead(k11) == HIGH && digitalRead(k12) == LOW && digitalRead(k21) == HIGH && digitalRead(k22) == LOW && digitalRead(k31) == LOW && digitalRead(k32) == LOW) {
      buf[2] = 5; // b keycode
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    
    }
    if (digitalRead(k11) == HIGH && digitalRead(k12) == HIGH && digitalRead(k21) == LOW && digitalRead(k22) == LOW && digitalRead(k31) == LOW && digitalRead(k32) == LOW) {
      buf[2] = 6; // c keycode
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    
    }
    if (digitalRead(k11) == HIGH && digitalRead(k12) == HIGH && digitalRead(k21) == LOW && digitalRead(k22) == HIGH && digitalRead(k31) == LOW && digitalRead(k32) == LOW) {
      buf[2] = 7; // d keycode
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    
    }
    if (digitalRead(k11) == HIGH && digitalRead(k12) == LOW && digitalRead(k21) == LOW && digitalRead(k22) == HIGH && digitalRead(k31) == LOW && digitalRead(k32) == LOW) {
      buf[2] = 8; // e keycode
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    
    }
  
}


}

// Function for Key Release

void releaseKey() {

buf[0] = 0;

buf[2] = 0;

Serial.write(buf, 8); // Send Release key

}
