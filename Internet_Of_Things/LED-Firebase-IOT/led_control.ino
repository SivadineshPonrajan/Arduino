#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "----------------.firebaseio.com"   //FIREBASE PROJECT ID
#define FIREBASE_AUTH "---------------------------------------"    //FIREBASE KEY
#define WIFI_SSID "123" //WIFI SSID
#define WIFI_PASSWORD "avisking"  //WIFI PASSWORD

const int lightPin = D0;
const int ledpin = D2;

void setup() {
  Serial.begin(115200);

  pinMode(lightPin, OUTPUT);
  pinMode(ledpin, OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("Relay", 0);
  Firebase.set("Atom", 0);
}

void loop() 
{

//GET IN STRING, CONVERT TO ARRAY, CONVERT ARRAY TO INTEGER
  String x= Firebase.getString("Relay");
  int l=x.length()+1;
  char y[l];
  x.toCharArray(y, l);
  int z= atoi(y);
  
  digitalWrite(lightPin,z);     //DIGITAL CONTROL


//GET IN STRING, CONVERT TO ARRAY, CONVERT ARRAY TO INTEGER
  String a= Firebase.getString("Atom");
  int l1=a.length()+1;
  char b[l1];
  a.toCharArray(b, l1);
  int c= atoi(b);
  
  analogWrite(ledpin, c);   //ANALOG CONTROL
}
