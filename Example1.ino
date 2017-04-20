/*
  AnalogReadSerial
  Reads an analog input on pin A3, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A3, and the outside pins to ~3V and ground.
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * 10-kilohm Potentiometer
  * hook-up wire

  This example code is in the public domain.
*/

#include <SPI.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <stdio.h>
#include <stdlib.h>

//A0 5.5
//A1 5.4
//A2 5.3
//A3 5.2
//A4 5.1
//A5 5.0
//A6 4.7
//A7 4.6
//A8 4.5
//A9 4.4
//A10 4.3
//A11 4.2
//A12 4.1
//A13 4.0
//A14 6.1
//A15 6.0
//A16 9.1
//A17 9.0
//A18 8.7
const int redButtonLED = A9; //6.1
const int redButtonPress = A15; //4.0
const int joystickLED = A8; //4.5
const int joystickWhack = A14; //4.7
const int switchLED = A6; //5.4
const int switchSwitched = A13; //5.5
int previousSwitchValue = digitalRead(switchSwitched);

// your network name also called SSID
char ssid[] = "rambo";
// your network password
char password[] = "ferrari1";
// MQTTServer to use
//char server[] = "usroex.messaging.internetofthings.ibmcloud.com";
char server[] = "broker.hivemq.com";

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Received message for topic ");
  Serial.print(topic);
  Serial.print("with length ");
  Serial.println(length);
  Serial.println("Message:");
  Serial.write(payload, length);
  Serial.println();
}

WiFiClient wifiClient;
PubSubClient client(server, 1883, callback, wifiClient);
// the setup routine runs once when you press reset:
void setup()
{
  //Serial.begin(115200);
	Serial.begin(9600);

  // Start Ethernet with the build in MAC Address
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid);
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");

  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
  // We are connected and have an IP address.
  // Print the WiFi status.
  printWifiStatus();


}

// the loop routine runs over and over again forever:
void loop() {
	// Reconnect if the connection was lost




  // read the input on analog pin A3:
  //int sensorValue = analogRead(A12);
  // print out the value you read:
  //Serial.println(sensorValue);
  delay(1); // delay in between reads for stability
  char str[80];
  char temp[80];
  int i = 0;
  int points;
  int wrong = 0;
  int totalPoints = 0;
  int randOption = 0;
  char name[4] = {' ', ' ', ' ', '\0'};
  char letters[27] = {'a', 'b', 'c', 'd', 'e',
		  'f', 'g', 'h', 'i', 'j', 'k', 'l',
		  'm', 'n', 'o', 'p', 'q', 'r',
		  's', 't', 'u', 'v', 'w', 'x',
		  'y', 'z','\0'};
  //make a user name!!!!!!!!!!!!!!!

  int charNum = 0;
  int letterValue = 0;

  name[charNum] = letters[letterValue];

  while(charNum < 3){
	  name[charNum] = letters[letterValue];
	  Serial.println(name);
	  //button press to move to next letter
	  if(digitalRead(joystickWhack) == HIGH){
		  letterValue++;
		  if(letterValue > 26){
			  letterValue = 0;
		  }

	  }
	  else if(digitalRead(redButtonPress) == HIGH){ //pick that letter
		  charNum++;
		  letterValue = 0;
	  }
	  else{

	  }
	  delay(300);
  }

  for(i = 0; i < 10; i++){
	  //int randOption = rand() % (high - low + 1) + low;

	  randOption = rand() % (3); //gives us 0, 1, 2, 3

	  if(randOption == 0){//LED1
		  digitalWrite(redButtonLED, HIGH);
		  points = 1000000;
		  while(digitalRead(redButtonPress) != HIGH){
			   points--;
			   if(digitalRead(joystickWhack) == HIGH){
				   wrong++;
				   break;
			   }
			   if(digitalRead(switchSwitched) != previousSwitchValue){
				  wrong++;
				  previousSwitchValue = digitalRead(switchSwitched);
				  break;
			  }
		  }
		  if(wrong > 0){
			  break;
		  }
		  digitalWrite(redButtonLED, LOW);
		  if(points < 0){
			  points = 0;
		  }
		  totalPoints += points;
	  }


	  else if(randOption == 1){//JoyStick
		  digitalWrite(joystickLED, HIGH);
		  points = 1000000;
		  while(digitalRead(joystickWhack) != HIGH){
			  points--;
			  if(digitalRead(redButtonPress) == HIGH){
				   wrong++;
				   break;
			   }
			   if(digitalRead(switchSwitched) != previousSwitchValue){
				  wrong++;
				  previousSwitchValue = digitalRead(switchSwitched);
				  break;
			  }
		  }
		  if(wrong > 0){
			  break;
		  }
		  digitalWrite(joystickLED, LOW);
		  if(points < 0){
			  points = 0;
		  }
		  totalPoints += points;
	  }

	  else{//switch
		  digitalWrite(switchLED, HIGH);
		  points = 1000000;
		  while(digitalRead(switchSwitched) == previousSwitchValue){
			  points--;
			  if(digitalRead(redButtonPress) == HIGH){
				   wrong++;
				   break;
			   }
			   if(digitalRead(joystickWhack) == HIGH){
				   wrong++;
				   break;
			   }
		  }
		  if(wrong > 0){
			  break;
		  }
		  digitalWrite(switchLED, LOW);
		  if(points < 0){
			  points = 0;
		  }
		  totalPoints += points;
		  previousSwitchValue = digitalRead(switchSwitched);
	  }


	  delay(1000);




  }
  	  strcpy(str, name);
  	  strcat(str, ",");
  	  sprintf(temp, "%d", totalPoints/100000);
  	  strcat(str, temp);
  	  Serial.println(str);


		if (!client.connected()) {
			Serial.println("Disconnected. Reconnecting....");

			if(!client.connect("bopit")) {
			  Serial.println("Connection failed");
			} else {
			  Serial.println("Connection success");
			  if(client.subscribe("inTopic")) {
				Serial.println("Subscription successfull");
			  }
			}
		  }

	  if(client.publish("bopit", str)) {
	      Serial.println("Publish success");
	    } else {
	      Serial.println("Publish failed");
	    }

	  digitalWrite(redButtonLED, LOW);
	  digitalWrite(joystickLED, LOW);
	  digitalWrite(switchLED, LOW);
	    delay(1000);


	  /*
	  else{//DIAL
		  digitalWrite(switchLED, HIGH);
		  points = 1000000;
		  while(digitalRead(switchSwitched) == previousSwitchValue){
			  points--;
			  if(digitalRead(redButtonPress) == HIGH){
				   wrong++;
				   break;
			   }
			   if(digitalRead(joystickWhack) == HIGH){
				   wrong++;
				   break;
			   }
			   if(digitalRead(blueButtonPress) == HIGH){
				   wrong++;
				   break;
			   }
		  }
		  if(wrong > 0){
			  break;
		  }
		  digitalWrite(switchLED, LOW);
		  if(points < 0){
			  points = 0;
		  }
		  totalPoints += points;
		  previousSwitchValue = analogRead(switchSwitched);
	  }

      delay(300);
  }
   * */
  //Serial.println(totalPoints);
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
