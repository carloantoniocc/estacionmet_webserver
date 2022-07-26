#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include "DHT.h"
#include <Arduino.h>

const char* ssid = "ard01";
const char* password = "zero1234";

ESP8266WebServer server(80);

void handleRoot(){
  digitalWrite(2,HIGH);
  server.send(200,"text/plain" ,"Hello Word" );
  digitalWrite(2,LOW);
  }

void setup() {
  // put your setup code here, to run once:

  pinMode(2,OUTPUT);

  Serial.begin(9600);
  Serial.println("Wifi station setting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.println("Conectando ");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
    }

  Serial.println("Wifi Ready");
  Serial.print("Mi direccion IP : ");
  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);
  server.begin();
  Serial.println("Server Http is started");

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
