/**********************************/
/*        ISEP MESCC CSLAB        */
/*             Heater             */
/*  Group 4                       */
/*    -> Carlos Rijo - 1101626    */
/*    -> João Fernandes - 1221973 */
/*                                */
/**********************************/

// Import Libraries
#include <WiFi.h>
#include <PubSubClient.h>
#include <string.h>
#include <Servo.h>

// Define Pins
#define HEATER_VALVE_PIN 22
#define HEATER_LED_PIN 23

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";


WiFiClient heaterClient;
const char *host = "192.168.1.253";
PubSubClient client(heaterClient);

// Define variables
Servo valve;
String deviceAddr = "";
char messageToSend[100];
long timestamp = 0;
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;
String officeID = "office1";
String actuatorType = "heater";
int val;

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

  valve.attach(HEATER_VALVE_PIN);
  pinMode(HEATER_LED_PIN, OUTPUT);
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

  if (String(topic) == "heater/control") {
    if (messageLights == "open") {
      digitalWrite(HEATER_LED_PIN, HIGH);
      valve.write(150);
    } else if (messageLights == "close") {
      valve.write(0);
      digitalWrite(HEATER_LED_PIN, LOW);
    } else if (messageLights == "done") {
      valve.write(0);
      digitalWrite(HEATER_LED_PIN, LOW);
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("heater")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("heater/control");
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

  int errorCode = 0;
  char heaterErrorString[8];

  dtostrf(errorCode, 1, 2, heaterErrorString);
  client.publish("heater/error", heaterErrorString);
}
