#include <Stepper.h>
 
const int stepsPerRevolution = 20; 
 
//Connection pins:
Stepper myStepperX(stepsPerRevolution, 8,9,10,11); 
Stepper myStepperY(stepsPerRevolution, 2,3,4,5);
 
void setup() {
 //Set speed:
 pinMode(LED_BUILTIN, OUTPUT);
 myStepperX.setSpeed(150);
 myStepperY.setSpeed(150);
}
 
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  myStepperX.step(256);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  myStepperY.step(256);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH); 
  myStepperX.step(-256);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW); 
  myStepperY.step(-256);
  delay(500);
}
