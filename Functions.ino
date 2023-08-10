#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include <string>
#include "Web.h"

//Defining the pins
#define ServoPort1 D1
#define ServoPort2 D2
#define ServoPort3 D3
#define ServoPort4 D4



Servo servoRotacao, servoGarra, servoCimaBaixo, servoFrenteTras;
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", MAIN_page);
}

//handle the position of the servos
void handleServo(){
  String POS1 = server.arg("POS1");
  int pos1 = std::atoi(POS1.c_str());
  servoRotacao.write(pos1);
  
  String POS2 = server.arg("POS2");
  int pos2 = std::atoi(POS2.c_str());
  servoGarra.write(pos2);

  String POS3 = server.arg("POS3");
  int pos3 = std::atoi(POS3.c_str());
  servoCimaBaixo.write(pos3);

  String POS4 = server.arg("POS4");
  int pos4 = std::atoi(POS4.c_str());
  servoFrenteTras.write(pos4);
  
  delay(20);
  server.send(200, "text/plane","");
}

//Setting up the WiFi network 
void setup() {
  const char* ssid = "TCC2";
  const char* password = "lucascardozo";
  Serial.begin(115200);
  delay(250);

  servoRotacao.attach(ServoPort1);
  servoGarra.attach(ServoPort2);
  servoCimaBaixo.attach(ServoPort3);
  servoFrenteTras.attach(ServoPort4);
  
  WiFi.softAP(ssid, password);

  IPAddress apip = WiFi.softAPIP();
  Serial.print("Connect your wifi laptop/mobile phone to this NodeMCU Access Point : ");
  Serial.println(ssid);
  Serial.print("Visit this IP : ");
  Serial.print(apip);
  Serial.println(" in your browser.");
  
  server.on("/",handleRoot);
  server.on("/setPOS",handleServo);
  server.begin();  
  Serial.println("HTTP server started");
}

//Loop to run the program
void loop() {
 server.handleClient();
}
