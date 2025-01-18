bool r1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A5, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  r1 = analogRead(A5);
  Serial.println(r1);
  delay(2000);
}
