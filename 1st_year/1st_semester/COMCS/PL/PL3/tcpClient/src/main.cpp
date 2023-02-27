#include <Arduino.h>
#include <WiFi.h>
#include <string.h>

#define LED_BUILTIN 2

// Replace with your network credentials
const char* ssid = "A12150F";
const char* password = "fzya2235";
// const char* ssid = "group5";
// const char* password = "11223344";
// Set server port number to 80
WiFiServer server(8080);

void sendResponse(WiFiClient* client, String response)
{
  client->print(response);
  // Debug print.
  Serial.println("sendResponse:");
  Serial.println(response);
}

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //prints the ip to which the server is listening
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      while (client.available()>0) {
        String request = client.readString();
        Serial.println(request);
        
        if(request.equalsIgnoreCase("OFF")){ 
          digitalWrite(LED_BUILTIN, LOW);
          sendResponse(&client, "LED OFF!");
        }else if(request.equalsIgnoreCase("ON")){
          digitalWrite(LED_BUILTIN, HIGH);
          sendResponse(&client, "LED ON!");
        }else sendResponse(&client, "INVALID COMMAND!");
      }
    }
  client.stop();
  Serial.println("Client disconnected");
  }
}
