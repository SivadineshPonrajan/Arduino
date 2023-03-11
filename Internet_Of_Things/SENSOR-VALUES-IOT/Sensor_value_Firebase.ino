#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "-----------.firebaseio.com"    //FIREBASE PROJECT ID
#define FIREBASE_AUTH "-------------------------------------"   //FIREBASE KEY
#define WIFI_SSID "123"   //WIFI SSID
#define WIFI_PASSWORD "abcdefgh"    //WIFI PASSWORD

const int ldr = A0;     //SENSOR PIN

void setup() {
  Serial.begin(115200);
  pinMode(ldr, INPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  Firebase.set("power", 0);
}


void loop() {
  float sensor = analogRead(ldr);
  if (abs(sensor) > 0)  //abs==ABSOLUTE
  {
    Firebase.setFloat("power", sensor);
  }
  delay(2000);    //SENSOR VALUE WILL BE UPDATED EVERY 2 SECONDS
}
