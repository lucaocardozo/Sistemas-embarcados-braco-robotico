#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include <string>
#include "Web.h"

//defines the pins that the servos are connected to.
#define ServoPort1 D1
#define ServoPort2 D2
#define ServoPort3 D3
#define ServoPort4 D4


//create objects for the servos.
Servo servoRotacao, servoGarra, servoCimaBaixo, servoFrenteTras;
//create an object for the web server.
ESP8266WebServer server(80);

// This function handles requests to the root path.
void handleRoot() {
  // Send the HTML page to the client.
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

  // Wait for 20 milliseconds.
  delay(20);
  // Send a blank response to the client.
  server.send(200, "text/plane","");
}

//Setting up the WiFi network 
void setup() {
  // Set the SSID and password for the WiFi network.
  const char* ssid = "TCC2";
  const char* password = "lucascardozo";
  // Initialize the serial port.
  Serial.begin(115200);
  delay(250);

  // Attach the servos to the pins.
  servoRotacao.attach(ServoPort1);
  servoGarra.attach(ServoPort2);
  servoCimaBaixo.attach(ServoPort3);
  servoFrenteTras.attach(ServoPort4);

  // Start the WiFi access point.
  WiFi.softAP(ssid, password);
  // Get the IP address of the access point.
  IPAddress apip = WiFi.softAPIP();

  // Print the SSID and IP address of the access point to the serial port.
  Serial.print("Connect your wifi laptop/mobile phone to this NodeMCU Access Point : ");
  Serial.println(ssid);
  Serial.print("Visit this IP : ");
  Serial.print(apip);
  Serial.println(" in your browser.");

  // Set up the web server.
  server.on("/",handleRoot);
  server.on("/setPOS",handleServo);
  server.begin();  
  // Print a message to the serial port to indicate that the HTTP server is started.
  Serial.println("HTTP server started");
}

//This function loops forever and handles requests from the web server.
void loop() {
 server.handleClient();
}
