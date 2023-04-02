/**********************************/
/*        ISEP MESCC CSLAB        */
/*             Lights             */
/*  Group 4                       */
/*    -> Carlos Rijo - 1101626    */
/*    -> João Fernandes - 1221973 */
/*                                */
/**********************************/

// Import Libraries
#include <WiFi.h>
#include <PubSubClient.h>
#include <string.h>

// Define Pins
#define LIGHTS_PIN 4

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";
WiFiClient lightsClient;
const char *host = "192.168.197.246";
PubSubClient client(lightsClient);

// Define variables
String deviceAddr = "";
char messageToSend[100];
long timestamp = 0;
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;
String officeID = "office1";
String actuatorType = "lights";

void setup() {
  Serial.begin(115200);  // BaudRate

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

  pinMode(LIGHTS_PIN, OUTPUT);
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageLights;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageLights += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "lights/control") {
    if (messageLights == "on") {
      Serial.println("on");
      digitalWrite(LIGHTS_PIN, HIGH);
      // TODO: Turn actuator ON In Assembly

    } else if (messageLights == "off") {
      Serial.println("off");
      digitalWrite(LIGHTS_PIN, LOW);
      // TODO: Turn actuator OFF In Assembly
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("lights")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("lights/control");
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

  // int errorCode = 0;
  // char tempString[8];

  // sprintf(messageToSend, "%s/%s/%d", officeID, actuatorType, errorCode);
  // Serial.println(messageToSend);
  // dtostrf(temperatureAverage, 1, 2, tempString);
  // client.publish("esp32/temperature", tempString);
  // client.publish(messageToSend);
}
