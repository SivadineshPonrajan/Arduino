#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

String apiKey = "---------------";   //THINGSPEAK KEY

#define FIREBASE_HOST "------------.firebaseio.com"   //FIREBASE PROJECT ID
#define FIREBASE_AUTH "--------------------------------------"    //FIREBASE KEY
const char *ssid =  "Aaron_Stone";     ///WIFI SSID
const char *pass =  "avisking";   //WIFI PASSWORD

const char* server = "api.thingspeak.com";

const int lightSensorPin = A0;


WiFiClient client;


void setup() 
{
       Serial.begin(115200);
       delay(10);
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println(WiFi.localIP());

        Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
        Firebase.set("value", 0);
        Firebase.set("A", 1);

}
 
void loop() 
{

digitalWrite(led,Firebase.getInt("A"));

float current =(analogRead(lightSensorPin));

if (abs(current) > 0)
{
    Firebase.setFloat("value", current);
}
delay(1000);
      
    
if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
{
String postStr = apiKey;
postStr +="&field1=";
postStr += String(current);   //FIELD NAME
postStr += "\r\n\r\n"; 
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
Serial.print("Sensor: ");
Serial.print(current);
Serial.println("%. Send to Thingspeak.");
}
client.stop(); 
delay(20000);   //UPDATE EVERY 20 SECS TO THINGSPEAK
}
