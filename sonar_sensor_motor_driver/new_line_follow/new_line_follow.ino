
int r1, r2, r3, r4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
    

}

void loop() {
  // put your main code here, to run repeatedly:
  IR();


}

void IR(){
  r1 = digitalRead(A1);
  r2 = digitalRead(A2);
  r3 = digitalRead(A3);
  r4 = digitalRead(A4);

  Serial.print("r1=");
  Serial.println(r1);

  Serial.print("r2=");
  Serial.println(r2);

//  Serial.print("r3=");
//  Serial.println(r3);
//
//  Serial.print("r4=");
//  Serial.println(r4);

if(r1==0 && r2==1){
  left();
}
else if(r1==1 && r2==0){
  right();
}
else{
  forward();
}
  
}

void stop_car(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
  
}

void forward(){
////digitalWrite(2, HIGH);
//digitalWrite(2,LOW);
//analogWrite(3, 85);
////digitalWrite(4, HIGH);
//analogWrite(4, 85);
//digitalWrite(5, LOW);

  analogWrite(2,80);
  digitalWrite(3,LOW);
  analogWrite(4,80); // to slow down the speed in half 255/2 = 127
  digitalWrite(5,LOW);

  
}

void forward_left(){
//digitalWrite(2, HIGH);
analogWrite(2, 209);
digitalWrite(3, LOW);
//digitalWrite(4, HIGH);
analogWrite(4, 220);
digitalWrite(5, LOW);
  
}

void forward_right(){
//digitalWrite(2, HIGH);
analogWrite(2, 195);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
//analogWrite(4, 190);
digitalWrite(5, LOW);
  
}


void left(){
//digitalWrite(2, LOW);
//digitalWrite(3, LOW);
////digitalWrite(4, HIGH);
//analogWrite(4, 80);
//digitalWrite(5, LOW);

analogWrite(2,80);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    analogWrite(5,80);
  
}

void right(){
//digitalWrite(2, HIGH);
//digitalWrite(2,LOW);
//analogWrite(3,85);
//digitalWrite(4, LOW); 
//digitalWrite(5, LOW);

digitalWrite(2,LOW);
    analogWrite(3,80);
    analogWrite(4,80);
    digitalWrite(5,LOW);

}

void backward(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 80);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 200);

}

void backward_left(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 162);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 180);
}

void backward_right(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 140);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 200);

}
