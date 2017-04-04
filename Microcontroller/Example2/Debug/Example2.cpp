#include "Energia.h"

#line 1 "C:/Users/cdgja/Documents/University of Pittsburgh/COE 1188 Cyber Physical Systems/BopIt/Microcontroller/Example2/Example2.ino"









#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h> 
void callback(char* inTopic, byte* payload, unsigned int length);
void setup();
void loop();
void printWifiStatus();

#line 13
WiFiClient wclient;


byte ip[]     = { 172, 16, 0, 100 };

char sensorRead[4];

#define       TOPIC             "coe1188_example2"
#define       WIFI_SSID         "rambo"
#define       WIFI_PWD          "ferrari1"


PubSubClient client("iot.eclipse.org", 1883, callback, wclient);

void callback(char* inTopic, byte* payload, unsigned int length){

}

void setup()
{
  
  Serial.begin(115200);

  Serial.println("Start WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while(WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    delay(300);
  }
  Serial.println("");

  printWifiStatus();

}

void loop()
{
  
  int sensorValue = analogRead(A12);
  Serial.println(sensorValue);

  
  String str = (String)sensorValue;
  int str_len = str.length() + 1;  
  char char_array[str_len];  
  str.toCharArray(char_array, str_len);  
  
  
  if (client.connect("LaunchPadClient")) {
    client.publish(TOPIC, char_array);
    
    Serial.println("Publishing successful!");
    client.disconnect();
  }

}

void printWifiStatus() {
  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}





