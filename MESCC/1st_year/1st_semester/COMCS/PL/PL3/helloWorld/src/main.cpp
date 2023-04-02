#include <Arduino.h>

void setup()
{
  Serial.begin(9600); // This value represents the Character encoder (This value has to match the one present in the serial monitor)
  Serial.println("Hello World");
}
void loop()
{
  // If coded in here, the message will continue to print.
}