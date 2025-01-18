  char b;
  String voice = "";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
}


void loop() {
  // put your main code here, to run repeatedly:

  while(Serial1.available()){
    b = Serial1.read();
    voice = voice + b;
    Serial.println(b);
  }

    if(voice.length()>0){
      if(voice == "go"){
        forward();
      }
      else if(voice == "back"){
        backword();
      }
      else if(voice == "left"){
        left();
      }
      else if(voice == "right"){
        right();
      }
      else if(voice == "stop"){
        stops();
      }
        
  voice = "";
    }
    
    
  delay(100);
}

  void forward(){
    analogWrite(2,127);
    digitalWrite(3,LOW);
    analogWrite(4,127); // to slow down the speed in half 255/2 = 127
    digitalWrite(5,LOW);
}

void backword(){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
}

void left(){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
}

void right(){
    digitalWrite(2,LOW);
    analogWrite(3,127);
    analogWrite(4,127);
    digitalWrite(5,LOW);
}

void stops(){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
}
