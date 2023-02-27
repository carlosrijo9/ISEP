/**********************************/
/*        ISEP MESCC CSLAB        */
/*             Blinds             */
/*  Group 4                       */
/*    -> Carlos Rijo - 1101626    */
/*    -> João Fernandes - 1221973 */
/*                                */
/**********************************/

// Import Libraries
#include <WiFi.h>
#include <PubSubClient.h>
#include <string.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>


// Define Pins

#define BLINDS_UP_PIN 25
#define BLINDS_DOWN_PIN 33

#define BLINDS_POS_0 23
#define BLINDS_POS_25 22
#define BLINDS_POS_50 21
#define BLINDS_POS_75 19
#define BLINDS_POS_100 18

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";
// const char *ssid = "Vodafone-92FE43";
// const char *password = "2f6Mh95RKN";

WiFiClient blindsClient;
const char *host = "192.168.1.253";
PubSubClient client(blindsClient);

// Define variables
//Servo motor;

String deviceAddr = "";
char messageToSend[100];
long timestamp = 0;
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;
String officeID = "office1";
String actuatorType = "blinds";
int blindsPosition = 0;
int targetPosition = 0;

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

  pinMode(BLINDS_UP_PIN, OUTPUT);
  pinMode(BLINDS_DOWN_PIN, OUTPUT);
  pinMode(BLINDS_POS_0, INPUT);
  pinMode(BLINDS_POS_25, INPUT);
  pinMode(BLINDS_POS_50, INPUT);
  pinMode(BLINDS_POS_75, INPUT);
  pinMode(BLINDS_POS_100, INPUT);
  //motor.attach(BLINDS_MOTOR_PIN);
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageBlinds;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageBlinds += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "blinds/control") {
    targetPosition = messageBlinds.toInt();

    if (targetPosition > blindsPosition) {
      digitalWrite(BLINDS_UP_PIN, HIGH);

    } else if (targetPosition < blindsPosition) {
      digitalWrite(BLINDS_DOWN_PIN, HIGH);
    }

    while (blindsPosition != targetPosition) {
      if (targetPosition == 0) {
        if (digitalRead(BLINDS_POS_0) == HIGH) {
          blindsPosition = 0;
          break;
        }
      } else if (targetPosition == 25) {
        if (digitalRead(BLINDS_POS_25) == HIGH) {
          blindsPosition = 25;
          break;
        }
      } else if (targetPosition == 50) {
        if (digitalRead(BLINDS_POS_50) == HIGH) {
          blindsPosition = 50;
          break;
        }
      } else if (targetPosition == 75) {
        if (digitalRead(BLINDS_POS_75) == HIGH) {
          blindsPosition = 75;
          break;
        }
      } else if (targetPosition == 100) {
        if (digitalRead(BLINDS_POS_100) == HIGH) {
          blindsPosition = 100;
          break;
        }
      }
    }
    digitalWrite(BLINDS_UP_PIN, LOW);
    digitalWrite(BLINDS_DOWN_PIN, LOW);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("blinds")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("blinds/control");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
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
  char blindsErrorString[8];

  dtostrf(errorCode, 1, 2, blindsErrorString);
  client.publish("blinds/error", blindsErrorString);
}
