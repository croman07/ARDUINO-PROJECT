int stepsPerRevolution = 200;
#include <Stepper.h>
Stepper myStepper (stepsPerRevolution,8,9,10,11);
Stepper myStepper1 (stepsPerRevolution,3,4,5,6);
int button = 2;
int button1 = 7;
int buttonState = 0;
int buttonState1 = 0;
void setup(){
  myStepper.setSpeed(60);
  myStepper1.setSpeed(60);
  pinMode (button, INPUT_PULLUP);
  pinMode (button1, INPUT_PULLUP);
  Serial.begin(9600);
 
}
void loop(){
  buttonState = digitalRead(button);
 buttonState1 = digitalRead(button1);
  if (buttonState == LOW && buttonState1 == HIGH) {
    Serial.println("endavant");
  myStepper.step(stepsPerRevolution);
  myStepper1.step(stepsPerRevolution);
  //els dos motors van endavant
   
  }
   if (buttonState == HIGH && buttonState1 == LOW) {
  myStepper.step(-stepsPerRevolution);
  myStepper1.step(-stepsPerRevolution);
  //els dos motors van endarrera
  Serial.println("endarrera");
}
}
