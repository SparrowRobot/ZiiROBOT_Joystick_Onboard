#include <Arduino.h>

#define JOYSTICK_X_PIN  (A6)
#define JOYSTICK_Y_PIN  (A7)

/*
  M1: left motor
  M2: right motor
  DIR HIGH: rotate counter-clockwise
*/
#define M1_PWM_PIN    (10)
#define M1_DIR_PIN    (8)
#define M2_PWM_PIN    (9)
#define M2_DIR_PIN    (7)

const int control_period = 300; // ms
unsigned long last_control_time = 0;

/**
 * @brief Method to test motor function at 50% power
 * 
 */
void motorTest()
{
  // *** left motor ccw ***
  // digitalWrite(M1_DIR_PIN, HIGH);
  // analogWrite(M1_PWM_PIN, 255 * 0.5);
  // *** left motor ccw ***
  // *** left motor cw ***
  // digitalWrite(M1_DIR_PIN, LOW);
  // analogWrite(M1_PWM_PIN, 255 * 0.5);
  // *** left motor cw ***
  // *** right motor ccw ***
  // digitalWrite(M2_DIR_PIN, HIGH);
  // analogWrite(M2_PWM_PIN, 255 * 0.5);
  // *** right motor ccw ***
  // *** right motor cw ***
  // digitalWrite(M2_DIR_PIN, LOW);
  // analogWrite(M2_PWM_PIN, 255 * 0.5);
  // *** right motor cw ***
}

void setup() 
{
  Serial.begin(115200);
  Serial.println("Hello, World!");

  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);

  pinMode(M1_DIR_PIN, OUTPUT);
  pinMode(M1_PWM_PIN, OUTPUT);
  analogWrite(M1_PWM_PIN, 0);
  digitalWrite(M1_DIR_PIN, LOW);

  pinMode(M2_DIR_PIN, OUTPUT);
  pinMode(M2_PWM_PIN, OUTPUT);
  analogWrite(M2_PWM_PIN, 0);
  digitalWrite(M2_DIR_PIN, LOW);
}

void loop() 
{
  unsigned long curr_time = millis();
  if (curr_time - last_control_time >= control_period)
  {
    last_control_time = curr_time;

    Serial.print("x: ");
    Serial.println(analogRead(JOYSTICK_X_PIN));
    Serial.print("y: ");
    Serial.println(analogRead(JOYSTICK_Y_PIN));

    // // set left motor pwm
    // if (left_pwm_target_prev > 0) { // forward
    //     digitalWrite(M1_DIR_PIN, HIGH);
    // } else {
    //     digitalWrite(M1_DIR_PIN, LOW);
    // }
    // analogWrite(M1_PWM_PIN, 255 * (abs(left_pwm_target_prev) / 100.0));
    // // set right motor pwm
    // if (right_pwm_target_prev > 0) { // forward
    //     digitalWrite(M2_DIR_PIN, LOW);
    // } else {
    //     digitalWrite(M2_DIR_PIN, HIGH);
    // }
    // analogWrite(M2_PWM_PIN, 255 * (abs(right_pwm_target_prev) / 100.0));
  }
}