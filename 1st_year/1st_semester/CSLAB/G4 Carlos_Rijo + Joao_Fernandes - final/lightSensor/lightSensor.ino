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
#include "DFRobot_VEML7700.h"

// Define ambient Light Sensors and Pins
#define TCAADDR 0x70
DFRobot_VEML7700 ambLightOut1;
DFRobot_VEML7700 ambLightOut2;
DFRobot_VEML7700 ambLightIn1;
DFRobot_VEML7700 ambLightIn2;

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";
// const char *ssid = "Vodafone-92FE43";
// const char *password = "2f6Mh95RKN";

WiFiClient ambLightSensorClient;
const char *host = "192.168.1.253";
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
String sensorStatusOut = "on";
String sensorStatusIn = "on";

void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);  // BaudRate

  // Inside Sensors
  tcaselect(0);
  ambLightIn1.begin();

  tcaselect(1);
  ambLightIn2.begin();

  // Outside Sensors
  tcaselect(3);
  ambLightOut1.begin();

  tcaselect(2);
  ambLightOut2.begin();

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

  deviceAddr = WiFi.macAddress();  // Get Device MAC Address
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
  if (String(topic) == "ambLightSensor/controlOut") {
    if (messageAmbLight == "on") {
      sensorStatusOut = "on";
    } else if (messageAmbLight == "off") {
      sensorStatusOut = "off";
    }
  }

  if (String(topic) == "ambLightSensor/controlIn") {
    if (messageAmbLight == "on") {
      sensorStatusIn = "on";
    } else if (messageAmbLight == "off") {
      sensorStatusIn = "off";
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
  int numberOfSensorsOut = 2;
  float ambLightArrayOut[numberOfSensorsOut];
  float ambLightAverageOut = 0;
  char ambLightStringOut[8];
  char ambLightStringOutError[8];
  int errorCodeOut = 1;

  int numberOfSensorsIn = 2;
  float ambLightArrayIn[numberOfSensorsIn];
  float ambLightAverageIn = 0;
  char ambLightStringIn[8];
  char ambLightStringInError[8];
  int errorCodeIn = 1;

  if (millis() >= time_now + msg_rate) {  // Check if required time as passed

    timestamp = millis();  // Get current time elapsed
    time_now += msg_rate;

    if (sensorStatusOut == "off") { Serial.println("Sensor Disabled"); }
    if (sensorStatusOut == "on" && errorCodeOut < 3) {

      // tcaselect(3);
      // ambLightOut1.getALSLux(ambLightArrayOut[0]);
      // if (ambLightArrayOut[0] == 255) {
      //   errorCodeOut = 1;
      //   ambLightArrayOut[0] = 0;
      // }
      // delay(200);

      tcaselect(2);
      //ambLightOut2.getALSLux(ambLightArrayOut[1]);
      if (ambLightOut2.getALSLux(ambLightArrayOut[1]) == 255) {
        if (errorCodeOut == 1) {
          errorCodeOut = 3;
        } else {
          errorCodeOut = 2;
        }
        ambLightArrayOut[1] = 0;
      }

      for (int i = 0; i < numberOfSensorsOut; i++) {
        ambLightAverageOut += ambLightArrayOut[i];
        // Serial.print("Ambient Light Out from sensor");
        // Serial.print(i);
        // Serial.print(" = ");
        // Serial.println(ambLightArrayOut[i]);
      }
      if (errorCodeOut == 1 || errorCodeOut == 2) {
        numberOfSensorsOut--;
      }
      ambLightAverageOut = ambLightAverageOut / numberOfSensorsOut;
      Serial.print("Ambient Light Out Average");
      Serial.print(" = ");
      Serial.println(ambLightAverageOut);
      dtostrf(ambLightAverageOut, 1, 2, ambLightStringOut);
      client.publish("ambLightSensor/valueOut", ambLightStringOut);
    }

    if (sensorStatusIn == "off") { Serial.println("Sensor Disabled"); }
    if (sensorStatusIn == "on" && errorCodeIn < 3) {

      // tcaselect(0);
      // ambLightIn1.getALSLux(ambLightArrayIn[0]);
      // if (ambLightArrayIn[0] == 255) {
      //   errorCodeIn = 1;
      //   ambLightArrayIn[0] = 0;
      // }

      // delay(200);

      tcaselect(1);
      //ambLightIn2.getALSLux(ambLightArrayIn[1]);
      if (ambLightIn2.getALSLux(ambLightArrayIn[1]) == 255) {
        if (errorCodeIn == 1) {
          errorCodeIn = 3;
        } else {
          errorCodeIn = 2;
        }
        ambLightArrayIn[1] = 0;
      }

      for (int i = 0; i < numberOfSensorsIn; i++) {
        ambLightAverageIn += ambLightArrayIn[i];
        // Serial.print("Ambient Light In from sensor");
        // Serial.print(i);
        // Serial.print(" = ");
        // Serial.println(ambLightArrayIn[i]);
      }
      if (errorCodeIn == 1 || errorCodeIn == 2) {
        numberOfSensorsIn--;
      }
      ambLightAverageIn = ambLightAverageIn / numberOfSensorsIn;
      Serial.print("Ambient Light In Average");
      Serial.print(" = ");
      Serial.println(ambLightAverageIn);
      dtostrf(ambLightAverageIn, 1, 2, ambLightStringIn);
      client.publish("ambLightSensor/valueIn", ambLightStringIn);

      dtostrf(errorCodeOut, 1, 2, ambLightStringOutError);
      client.publish("ambLightSensor/errorOut", ambLightStringOutError);

      dtostrf(errorCodeIn, 1, 2, ambLightStringInError);
      client.publish("ambLightSensor/errorIn", ambLightStringInError);
    }
  }
}