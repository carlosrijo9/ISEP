/**********************************/
/*        ISEP MESCC CSLAB        */
/*       Temperature Sensor       */
/*  Group 4                       */
/*    -> Carlos Rijo - 1101626    */
/*    -> João Fernandes - 1221973 */
/*                                */
/**********************************/

// Import Libraries
#include <WiFi.h>
#include <PubSubClient.h>
#include <string.h>
#include <Wire.h>
#include "DHT.h"

// Define Temperature Sensors and Pins
#define DHT1PIN 18
#define DHT2PIN 27
#define DHTTYPE DHT11

DHT dht1(DHT1PIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";
// const char *ssid = "Vodafone-92FE43";
// const char *password = "2f6Mh95RKN";

WiFiClient tempSensorClient;
const char *host = "192.168.1.253";
PubSubClient client(tempSensorClient);

// Define variables
String deviceAddr = "";
char messageToSend[100];
long timestamp = 0;
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;
String officeID = "office1";
String sensorType = "temperature";
String sensorStatus = "on";

void setup() {
  Serial.begin(115200);  // BaudRate

  dht1.begin();
  dht2.begin();

  WiFi.begin(ssid, password);              // Begin Wifi service
  while (WiFi.status() != WL_CONNECTED) {  // Check if the device is connected to Network
    delay(2000);
    Serial.println("Connecting to WiFi");
  }
  Serial.print("WiFi connected to ");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(host, 1883);
  client.setCallback(callback);

  deviceAddr = WiFi.macAddress();  // Get Device MAC Address
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic temperatureSensor/control, you check if the message is either "on" or "off".
  if (String(topic) == "temperatureSensor/control") {
    if (messageTemp == "on") {
      sensorStatus = "on";
    } else if (messageTemp == "off") {
      sensorStatus = "off";
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("temperatureSensor")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("temperatureSensor/control");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Define Host settings
  int numberOfSensors = 2;
  float temperatureArray[numberOfSensors];
  float temperatureAverage = 0;
  char tempString[8];
  char tempStringError[8];
  int errorCode = 0;

  // Serial.print("Sensor Status: ");
  // Serial.println(sensorStatus);

  if (sensorStatus == "off") { Serial.println("Sensor Disabled"); }
  if (sensorStatus == "on" && errorCode < 3) {
    if (millis() >= time_now + msg_rate) {  // Check if required time as passed

      time_now += msg_rate;
      temperatureArray[0] = dht1.readTemperature();  // Read Temperature from sensor1
      if (isnan(temperatureArray[0])) {
        errorCode = 1;
        temperatureArray[0] = 0;
      }

      temperatureArray[1] = dht2.readTemperature();  // Read Temperature from sensor2
      if (isnan(temperatureArray[1])) {
        if (errorCode == 1) {
          errorCode = 3;
        } else {
          errorCode = 2;
        }
        temperatureArray[1] = 0;
      }
      timestamp = millis();
      temperatureAverage = 0;  // Get current time elapsed

      for (int i = 0; i < numberOfSensors; i++) {
        temperatureAverage += temperatureArray[i];
        // Serial.print("Temperature from sensor");
        // Serial.print(i + 1);
        // Serial.print(" = ");
        // Serial.println(temperatureArray[i]);
      }
      if (errorCode == 1 || errorCode == 2) {
        numberOfSensors--;
      }
      temperatureAverage = temperatureAverage / numberOfSensors;
      Serial.print("Temperature Average");
      Serial.print(" = ");
      Serial.println(temperatureAverage);

      dtostrf(temperatureAverage, 1, 2, tempString);
      client.publish("temperatureSensor/value", tempString);

      dtostrf(errorCode, 1, 2, tempStringError);
      client.publish("temperatureSensor/error", tempStringError);
    }
  }
}
