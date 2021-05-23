#include <AFMotor.h>

// Number of steps per output rotation
// Change this as per your motor's specification
const int stepsPerRevolution = 48;

// connect motor to port #1 (M1 and M2)
// connect motor to port #2 (M3 and M4)
AF_Stepper motor(stepsPerRevolution, 1);
AF_Stepper motor2(stepsPerRevolution, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");

  motor.setSpeed(200);  // 10 rpm
  motor2.setSpeed(200);  // 10 rpm   
}

void loop() {
  //Serial.println("Single coil steps");
  //motor.step(100, FORWARD, SINGLE); 
  //motor.step(100, BACKWARD, SINGLE); 

  //Serial.println("Double coil steps");
  //motor.step(100, FORWARD, DOUBLE); 
  //motor.step(100, BACKWARD, DOUBLE);

  //Serial.println("Interleave coil steps");
  //motor.step(100, FORWARD, INTERLEAVE); 
  //motor.step(100, BACKWARD, INTERLEAVE); 

  Serial.println("Micrsostep steps");
  motor.step(200, FORWARD, MICROSTEP); 
  motor.step(200, BACKWARD, MICROSTEP); 
  
  Serial.println("Micrsostep steps");
  motor2.step(200, FORWARD, MICROSTEP); 
  motor2.step(200, BACKWARD, MICROSTEP); 
}
