#include <Stepper.h>
#include <Servo.h>
 
const int stepsPerRevolution = 20; 
int angulo = 0 ;
Servo servo1; 
 
//Connection pins:
Stepper myStepperX(stepsPerRevolution, 8,9,10,11); 
Stepper myStepperY(stepsPerRevolution, 2,3,4,5);

 
void setup() {
 //Set speed:
 pinMode(LED_BUILTIN, OUTPUT);
 myStepperX.setSpeed(150);
 myStepperY.setSpeed(150);
 servo1.attach(6);
}
 
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  myStepperX.step(256);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  myStepperY.step(256);
  delay(500);
  for(angulo  = 20; angulo  <= 50; angulo  += 1)   //incrementa angulo 1 grado
            {
                 servo1.write(angulo);
                 delay(10);
            }
        delay(250);
  digitalWrite(LED_BUILTIN, HIGH); 
  myStepperX.step(-256);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW); 
  myStepperY.step(-256);
  delay(500);
  for(angulo  = 50; angulo  >=20; angulo  -=1 )    //decrementa angulo 1 grado
    {
         servo1.write( angulo );
         delay(10);
    }
  delay(250);
}
