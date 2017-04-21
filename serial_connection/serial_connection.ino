
/*
SparkFun Inventor's Kit
Example sketch 08-1

SINGLE SERVO

  Sweep a servo back and forth through its full range of motion.

  A "servo", short for servomotor, is a motor that includes
  feedback circuitry that allows it to be commanded to move to
  specific positions. This one is very small, but larger servos
  are used extensively in robotics to control mechanical arms,
  hands, etc. You could use it to make a (tiny) robot arm,
  aircraft control surface, or anywhere something needs to be
  moved to specific positions.


This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


#include <Servo.h>  // servo library


Servo servo1;  // servo control object
Servo servo2;  // servo control object
Servo servo3;  // servo control object

int incomingByte = 0;

void setup()
{
  Serial.begin(9600);

  servo1.attach(9, 900, 2100);
  servo2.attach(10, 900, 2100);
  servo3.attach(11, 900, 2100);

  // calibration
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);

  delay(1000);
}


void loop()
{

    // send data only when you receive data:
  if (Serial.available() > 0) {
          // read the incoming byte:
          incomingByte = Serial.read();
          servo1.write(incomingByte);
          servo2.write(incomingByte);
          servo3.write(incomingByte);
  }

//
//  if (random(200) < 100) {
//    servo1.write(40);
//  } else {
//    servo1.write(140);
//  }
//
//  if (random(200) < 100) {
//    servo2.write(40);
//  } else {
//    servo2.write(140);
//  }
//
//  if (random(200) < 100) {
//    servo3.write(40);
//  } else {
//    servo3.write(140);
//  }
//
//  delay(200);
}
