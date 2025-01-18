  char b;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial1.available()){
    b = Serial1.read();
    Serial.println(b);
    if(b=='F'){
      forward();
    }
    else if(b=='B'){
      backword();
    }
    else if(b=='L'){
      right();
    }
    else if(b=='R'){
      left();
    }
    else {
      stops();
    }
  }
 
  
}

  void forward(){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH); // to slow down the speed in half 255/2 = 127
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
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
}

void stops(){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
}
