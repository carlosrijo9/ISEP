/**********************************/
/*        ISEP MESCC COMCS        */
/*                                */
/*  Group 5                       */
/*    -> Carlos Rijo - 1101626    */
/*    -> Eduardo Maia - 1121209   */
/*                                */
/**********************************/

// Import Libraries
#include <WiFi.h>
#include <string.h>
#include <Wire.h>
#include "DHT.h"

// Define Temperature Sensor and Pin
#define DHTPIN 4
#define DHTTYPE DHT11
// #define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Define Network Settings
const char *ssid = "Vodafone-92FE43";
const char *password = "2f6Mh95RKN";

// Define variables
String deviceAddr = "";
char messageToSend[100];
int timestamp = 0;
int msg_rcv = 2000;   // in milliseconds
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;

void sendResponse(WiFiClient *server, String response) {  // Function to send message via Wifi
  server->print(response);
}

void setup() {
  Serial.begin(115200);  // BaudRate
  dht.begin();           // Begin temperature sensor service

  WiFi.begin(ssid, password);              // Begin Wifi service
  while (WiFi.status() != WL_CONNECTED) {  // Check if the device is connected to Network
    delay(2000);
    Serial.println("Connecting to WiFi");
  }
  Serial.print("WiFi connected to ");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  deviceAddr = WiFi.macAddress();  // Get Device MAC Address
}

void loop() {
  WiFiClient secServer;

  // Define Host settings
  //const char *host = "192.168.42.49";
  const char *host = "192.168.1.97";
  uint16_t port[3] = { 10998, 10997, 10996 };

  int sizePort = sizeof(port) / sizeof(uint16_t);

  if (millis() >= time_now + msg_rate) {  // Check if required time as passed

    time_now += msg_rate;

    float temp = dht.readTemperature();  // Read Temperature from sensor
    timestamp = millis();                // Get current time elapsed

    if (isnan(temp)) {                                            // Check if temperature sensor returned a valid value
      sprintf(messageToSend, "%s/none/0\n", deviceAddr.c_str());  // The value is NOT valid
    } else {
      sprintf(messageToSend, "%s/%f/%d", deviceAddr.c_str(), temp, timestamp);  // The value is valid
    }
    // Serial.println(messageToSend);

    for (int i = 0; i < sizePort; i++) {       // Send message with value to all ports from the same host:
      if (secServer.connect(host, port[i])) {  // If there is a connection
        if (secServer) {
          while (secServer.connected()) {             // While the device is connected
            sendResponse(&secServer, messageToSend);  // Send Message functin call

            String request = secServer.readString();  // Receive data acquisition rate
            msg_rcv = request.toInt();
            if (msg_rcv > 0) {
              msg_rate = msg_rcv;
            }
            break;
          }
        }
      } else {  // If there is no connection with port, report an error
        Serial.print(F("No Com with port "));
        Serial.println(port[i]);
      }
      secServer.stop();  // Close Connection with port
      //Serial.println(F("Client disconnected"));
    }
  }
}