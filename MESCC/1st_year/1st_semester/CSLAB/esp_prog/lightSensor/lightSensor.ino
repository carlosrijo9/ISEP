/**********************************/
/*        ISEP MESCC CSLAB        */
/*         Ambient Light          */
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
#include <Adafruit_Sensor.h>
#include "Adafruit_VEML7700.h"

// Define ambient Light Sensors and Pins
#define TCAADDR 0x70
Adafruit_VEML7700 ambLight1 = Adafruit_VEML7700();
Adafruit_VEML7700 ambLight2 = Adafruit_VEML7700();

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";
WiFiClient ambLightSensorClient;
const char *host = "192.168.197.246";
PubSubClient client(ambLightSensorClient);

// Define variables
String deviceAddr = "";
char messageToSend[100];
long timestamp = 0;
int msg_rcv = 2000;   // in milliseconds
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;
String officeID = "office1";
String sensorType = "ambientLight";

void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}
void setup() {
  Serial.begin(115200);  // BaudRate

  tcaselect(2);
  ambLight1.begin();

  tcaselect(6);
  ambLight2.begin();

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

  // Set non-default gain and integration time to adjust for different lighting conditions.
  // ambLight.setGain(VEML7700_GAIN_1_8);
  // ambLight.setIntegrationTime(VEML7700_IT_100MS);

  tcaselect(2);
  ambLight1.setLowThreshold(10000);
  ambLight1.setHighThreshold(20000);
  ambLight1.interruptEnable(true);

  tcaselect(6);
  ambLight2.setLowThreshold(10000);
  ambLight2.setHighThreshold(20000);
  ambLight2.interruptEnable(true);
  //deviceAddr = WiFi.macAddress();  // Get Device MAC Address
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageAmbLight;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageAmbLight += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic ambLightSensor/control, you check if the message is either "on" or "off".
  if (String(topic) == "ambLightSensor/control") {
    if (messageAmbLight == "on") {
      //Serial.println("on");
    } else if (messageAmbLight == "off") {
      //Serial.println("off");
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ambLightSensor")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("ambLightSensor/control");
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
  float ambLightArray[numberOfSensors];
  float ambLightAverage = 0;
  int errorCode = 0;
  char ambLightString[8];

  if (millis() >= time_now + msg_rate) {  // Check if required time as passed

    time_now += msg_rate;

    tcaselect(2);
    ambLightArray[0] = ambLight1.readLux();  // Read Ambient Light from sensor1

    tcaselect(6);
    ambLightArray[1] = ambLight2.readLux();  // Read Ambient Light from sensor2
    timestamp = millis();                    // Get current time elapsed

    for (int i = 0; i < numberOfSensors; i++) {

      if (isnan(ambLightArray[i])) {  // Check if ambient light sensor returned a valid value
        if (i == 0) {
          errorCode = 1;
        } else if (i == 1 && errorCode == 0) {
          errorCode = 2;
        } else if (i == 1 && errorCode == 1) {
          errorCode = 3;
        }
      } else {
        ambLightAverage += ambLightArray[i];
      }
      Serial.print("Ambient Light from sensor");
      Serial.print(i);
      Serial.print(" = ");
      Serial.println(ambLightArray[i]);
    }
    ambLightAverage = ambLightAverage / numberOfSensors;
      Serial.print("Ambient Light Average");
      Serial.print(" = ");
      Serial.println(ambLightAverage);

    sprintf(messageToSend, "%s/%s/%f/%d", officeID, sensorType, ambLightAverage, errorCode);
    Serial.println(messageToSend);
    dtostrf(ambLightAverage, 1, 2, ambLightString);
    client.publish("ambLightSensor/value", ambLightString);
    //client.publish(messageToSend);
  }

  // raw ALS
  //ambLight.readALS();

  // raw white
  //ambLight.readWhite();

  // lux
  //ambLight.readLux();
}