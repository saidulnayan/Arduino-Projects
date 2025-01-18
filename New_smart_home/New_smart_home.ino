//#include <dummy.h>


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.

char auth[] = "G0X08BUnAjATOczcWYOMwTeVkdWYDp7R";

// Your WiFi credentials.

char ssid[] = "Nayan";
char pass[] = "01915112560";

void setup()
{
  // Debug console
  //Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
