int r1, r2, r3, r4;
void setup() {
  Serial.begin(9600);

  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);

   digitalWrite(A1,HIGH);
   digitalWrite(A2,HIGH);
   digitalWrite(A3,HIGH);
   digitalWrite(A4,HIGH);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  IR();

  if(r1==1 && r2==0){
    right();
  }
  else if(r1==0 && r2==1){
    left();
  }
  else{
    forward();
  }
}


  void IR(){

    r1 = digitalRead(A1);
    r2 = digitalRead(A2);
//    r1 = digitalRead(A3);
//    r2 = digitalRead(A4);

    Serial.print("r1= ");
    Serial.println(r1);    
    Serial.print("r2= ");
    Serial.println(r2);   
    delay(1000); 
//    Serial.print("r3= ");
//    Serial.println(r3);    
//    Serial.print("r4= ");
//    Serial.println(r4);    
}

void forward(){
    analogWrite(2,85);
    digitalWrite(3,LOW);
    analogWrite(4,85); // to slow down the speed in half 255/2 = 127
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
    analogWrite(3,85);
    analogWrite(4,85);
    digitalWrite(5,LOW);
}

void stops(){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
}
