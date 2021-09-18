#include <Arduino.h>

int value = 0;
const int LED_RED = 2;
const int LED_YELLOW = 8;
const int LED_GREEN = 12;
const int SENSOR = A5;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, LOW);

  pinMode(LED_YELLOW, OUTPUT);
  digitalWrite(LED_YELLOW, LOW);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
}

void loop()
{
  value = (analogRead(SENSOR) / 700.0) * 100.0;
  Serial.println(value);

  if (value >= 80.0)
  {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
  }
  else if (value >= 30.0 && value < 80.0)
  {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
  }
  else
  {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }
}