 
 
//float dr,t;
int r1, r2, r3,r4;

void setup(){
  Serial.begin(9600);
  
  
  pinMode(2, OUTPUT);  // left wheel
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);  //right wheel
  pinMode(5, OUTPUT);

  pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
  pinMode(A3,INPUT);
//  pinMode(A4,OUTPUT);
//  pinMode(A5,INPUT);
   

  digitalWrite(A1, HIGH);
 // digitalWrite(A2, HIGH);
  digitalWrite(A3,HIGH);
   
  
}

void loop(){
//  checkRun();
 //forward();
//  left();
//  right()
  sensorCheck();
 followLine();
//  sensorCheck();
//  back();

}


void followLine(){
  r1 = digitalRead(A1);
  //r2 = digitalRead(A2);
  r3 = digitalRead(A2);
  //r4 = digitalRead(A4);

  if(r1==1 && r3==0){
    right();
    //backleft();
  }
  else if(r1==0 && r3==1){
    left();
    //backright();
  }
  
  else{
    forward();
  }

  
}

void sensorCheck(){
  r1 = digitalRead(A1);
  //r2 = digitalRead(A2);
  r3 = digitalRead(A3);
  //r4 = digitalRead(A4);

  Serial.print("r1=");
  Serial.println(r1);
  delay(1000);

//  Serial.print("r2=");
//  Serial.println(r2);
//  delay(1000);

  Serial.print("r3=");
  Serial.println(r3);
  delay(1000);

//  Serial.print("r4=");
//  Serial.println(r4);
}


/*void checkRun(){
  forward();
  delay(4000);
  stop_car();
  delay(1000);
  left();
  delay(3000);
  stop_car();
  delay(1000);
  forward();
  delay(4000);
  stop_car();
  delay(1000);
  right();
  delay(3000);
  stop_car();
  delay(1000);
  back();
  delay(2000);
  stop_car();
  delay(1000);
}*/

void forward(){

  //  digitalWrite(2, HIGH);
  analogWrite(2, 66);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4, 75);
  digitalWrite(5,LOW);
//  
//  digitalWrite(A4,HIGH);
//  delay(10);
//  digitalWrite(A4,LOW);
//  t = pulseIn (A5,HIGH);
//
//  dr = 0.0343*(t/2);
//  Serial.println(dr);
//
//  if(dr<12){
//    right();
//    delay(800);
//
//    forward();
//    delay(1200);
//  
//    left();
//    delay(1200);
//
//    forward();
//    delay(800);
//
//    left();
//    delay(200);
//
//    forward();
//    delay(200);
//  }
//  else{
//    //  digitalWrite(2, HIGH);
//  analogWrite(2, 67);
//  digitalWrite(3,LOW);
////  digitalWrite(4,HIGH);
//  analogWrite(4, 80);
//  digitalWrite(5,LOW);
//  }

}

void left(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
//  digitalWrite(4,HIGH);
  analogWrite(4,60);
  digitalWrite(5,LOW);
}


void right(){
//  digitalWrite(2,LOW);
  analogWrite(2, 50);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}

void stop_car(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
 
}

void back(){
  digitalWrite(2,LOW);
//  digitalWrite(3,HIGH);
  analogWrite(3, 100);
  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
  analogWrite(5, 100);
}
/*void backleft() {
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
  

  
}
void backright(){
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
}*/
