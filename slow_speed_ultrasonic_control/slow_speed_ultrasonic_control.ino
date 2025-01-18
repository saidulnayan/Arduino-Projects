  float d, t;

void setup() {
  
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,INPUT);


}


void loop() {
  // put your main code here, to run repeatedly:
 
  distance();
  
}

void distance() {
  digitalWrite(A1,HIGH);
  delay(10);
  digitalWrite(A1,LOW);
  t = pulseIn (A2,HIGH);

  d = 0.0343*(t/2);
  Serial.println(d);

  if(d<30){
    right();
  }
  else{
    forward();
  }
   
  }

  void forward(){
    analogWrite(2,127);
    digitalWrite(3,LOW);
    analogWrite(4,127); // to slow down the speed in half 255/2 = 127
    digitalWrite(5,LOW);
}
'
'
'

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
