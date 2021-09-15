#include <Arduino.h>

#define JOYSTICK_X_PIN  (A6)
#define JOYSTICK_Y_PIN  (A7)

// int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, World!");

  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // count++;
  // Serial.print(count);
  // Serial.println("Hello");
  Serial.print("x: ");
  Serial.println(analogRead(JOYSTICK_X_PIN));
  Serial.print("y: ");
  Serial.println(analogRead(JOYSTICK_Y_PIN));
  delay(100);
}