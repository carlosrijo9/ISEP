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


// Define Pins
#define BLINDS_UP_PIN 34
#define BLINDS_DOWN_PIN 35
#define BLINDS_POS_0 32
#define BLINDS_POS_25 33
#define BLINDS_POS_50 25
#define BLINDS_POS_75 26
#define BLINDS_POS_100 27

// Define Network Settings
const char *ssid = "group4";
const char *password = "1122334455";
WiFiClient blindsClient;
const char *host = "192.168.125.49";
PubSubClient client(blindsClient);

// Define variables
String deviceAddr = "";
char messageToSend[100];
long timestamp = 0;
int msg_rate = 2000;  // in milliseconds
unsigned long time_now = 0;
String officeID = "office1";
String actuatorType = "blinds";

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
}
int getBlindsPosition() {
  int position;
  int blindsPosition0;
  int blindsPosition25;
  int blindsPosition50;
  int blindsPosition75;
  int blindsPosition100;

  blindsPosition0 = digitalRead(BLINDS_POS_0);
  blindsPosition25 = digitalRead(BLINDS_POS_25);
  blindsPosition50 = digitalRead(BLINDS_POS_50);
  blindsPosition75 = digitalRead(BLINDS_POS_75);
  blindsPosition100 = digitalRead(BLINDS_POS_100);

  if (blindsPosition0 == HIGH && blindsPosition25 == LOW && blindsPosition50 == LOW && blindsPosition75 == LOW && blindsPosition100 == LOW) {
    position = 0;
  } else if (blindsPosition0 == LOW && blindsPosition25 == HIGH && blindsPosition50 == LOW && blindsPosition75 == LOW && blindsPosition100 == LOW) {
    position = 25;
  } else if (blindsPosition0 == LOW && blindsPosition25 == LOW && blindsPosition50 == HIGH && blindsPosition75 == LOW && blindsPosition100 == LOW) {
    position = 50;
  } else if (blindsPosition0 == LOW && blindsPosition25 == LOW && blindsPosition50 == LOW && blindsPosition75 == HIGH && blindsPosition100 == LOW) {
    position = 75;
  } else if (blindsPosition0 == LOW && blindsPosition25 == LOW && blindsPosition50 == LOW && blindsPosition75 == LOW && blindsPosition100 == HIGH) {
    position = 100;
  } else if (blindsPosition0 == HIGH && (blindsPosition25 == HIGH || blindsPosition50 == HIGH || blindsPosition75 == HIGH || blindsPosition100 == HIGH)) {
    position = -99;
  }

  return position;
}
void callback(char *topic, byte *message, unsigned int length) {
  int blindsPosition = 0;
  int targetPosition;

  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageBlinds;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageBlinds += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "esp32/output") {
    Serial.print("Changing output to ");
    if (messageBlinds == "up") {
      Serial.println("up");
      digitalWrite(BLINDS_DOWN_PIN, LOW);

      if (targetPosition = 100) {
        targetPosition = 100;
      } else {
        targetPosition = targetPosition + 25;
      }

      //blindsPosition = getBlindsPosition;
      while (blindsPosition != targetPosition) {
        //blindsPosition = getBlindsPosition;
        digitalWrite(BLINDS_UP_PIN, HIGH);
        // TODO: Turn actuator UP In Assembly
      }
      Serial.println("blind in position");
      digitalWrite(BLINDS_UP_PIN, LOW);
      // TODO: Turn actuator OFF In Assembly

    } else if (messageBlinds == "down") {
      Serial.println("down");
      digitalWrite(BLINDS_UP_PIN, LOW);
      if (targetPosition = 0) {
        targetPosition = 0;
      } else {
        targetPosition = targetPosition - 25;
      }

      //blindsPosition = getBlindsPosition;
      while (blindsPosition != targetPosition) {
        //blindsPosition = getBlindsPosition;
        digitalWrite(BLINDS_DOWN_PIN, HIGH);
        // TODO: Turn actuator DOWN In Assembly
      }
      Serial.println("blind in position");
      digitalWrite(BLINDS_DOWN_PIN, LOW);
      // TODO: Turn actuator OFF In Assembly
    }
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
      client.subscribe("esp32/output");
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
