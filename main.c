// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
const int sensor = 32;
int val;
/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
String readCahaya() {
val = analogRead(sensor);
Serial.println(val);
delay(1);
String valtext = String(val);
return valtext;
}
void setup(){
// Serial port for debugging purposes
Serial.begin(115200);
Serial.println();
pinMode(sensor,INPUT);
// Setting the ESP as an access point
Serial.print("Setting AP (Access Point)…");
// Remove the password parameter, if you want the AP (Access Point) to be open
WiFi.softAP(ssid, password);
IPAddress IP = WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(IP);
server.on("/cahaya", HTTP_GET, [](AsyncWebServerRequest *request){
request->send_P(200, "text/plain", readCahaya().c_str());
});
// Start server
server.begin();
}
void loop(){
}
