 #define Q1 A0   // Attach DTMF Module Q1  Pin to Arduino Pin A0
 #define Q2 A1   // Attach DTMF Module Q2  Pin to Arduino Pin A1
 #define Q3 A2   // Attach DTMF Module Q3  Pin to Arduino Pin A2
 #define Q4 A3   // Attach DTMF Module Q4  Pin to Arduino Pin A3
 #define STD A4  // Attach DTMF Module STD Pin to Arduino Pin A4

 #define Relay_1  8  // Attach Relay_1 Control Pin to Arduino Pin 8
 

 int DTMFdata; // The DTMFdata variable will be used to interpret the output of the DTMF module.


void setup() 
{
  Serial.begin(9600); 
  
  //Setup the INPUT pins on the Arduino for "MT8870 DTMF Module" 
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(STD, INPUT);

  //Setup the OUTPUT pins on the Arduino for Relay 
  pinMode(Relay_1, OUTPUT);
}


void loop() 
{
  if(digitalRead(STD)==HIGH) //STD pin goes to high, if a new data is available in "MT8870 DTMF Module".
  {
    DTMFdata=0;
    
    if(digitalRead(Q1)==HIGH)//If Q1 reads HIGH, then add 1 to the DTMFdata variable
    {      
      DTMFdata=DTMFdata+1;
    }
    
    if(digitalRead(Q2)==HIGH)//If Q2 reads HIGH, then add 2 to the DTMFdata variable
    {      
      DTMFdata=DTMFdata+2;
    }
    
    if(digitalRead(Q3)==HIGH) //If Q3 reads HIGH, then add 4 to the DTMFdata variable
    {     
      DTMFdata=DTMFdata+4;
    }
    
    if(digitalRead(Q4)==HIGH)//If Q4 reads HIGH, then add 8 to the DTMFdata variable 
    {      
      DTMFdata=DTMFdata+8;
    }

    Serial.println(DTMFdata); //Print the DTMF data in serial monitor.
    delay(500);
    
    if(DTMFdata == 8) {digitalWrite(Relay_1, HIGH); Serial.println("Light ON");} //Light ON 
    if(DTMFdata == 0) {digitalWrite(Relay_1, LOW); Serial.println("Light OFF");}//Light OFF 
  } 
}
