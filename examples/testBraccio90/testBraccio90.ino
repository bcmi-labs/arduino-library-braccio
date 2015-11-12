
/*
  testBraccio90

 This sketch testBraccio90 move all servo motors ton 90 degrees


 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Servo.h>


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo tongue;


void setup() {
	//Initialization  the servo motor pins
	base.attach(11);
	shoulder.attach(10);
	elbow.attach(9);
	wrist_rot.attach(6);
	wrist_ver.attach(5);
	tongue.attach(3);

}

void loop() {
	//Move all the servo motors to 90 degrees	
	base.write(90);
	shoulder.write(90);
	elbow.write(90);
	wrist_rot.write(90);
	wrist_ver.write(90);
	tongue.write(90);
}
