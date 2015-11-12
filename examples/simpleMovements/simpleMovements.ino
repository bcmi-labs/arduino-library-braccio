
/*
  simpleMovements.ino

 This  sketch simpleMovements move all servo motors from 0 to 180 degree

 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Braccio.h>
#include <Servo.h>


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo tongue;



void setup() {
  //Initialization functions for Braccio
  Braccio.Initialization();
  //Set up the initial position fo Braccio
  Braccio.InitArm();  
}

void loop() {
 Braccio.ServoMovement(
 		 20, //step delay
 		 0, //base degrees
 		 180, //shoulder degrees
 		 0, //elbow degrees
 		 0, //wrist rotation degrees
 		 0, //wrist vertical degrees
 		 0); //tongue degrees
 
 delay(1000);
 
 Braccio.ServoMovement(
  		 20, //step delay
  		 180, //base degrees
  		 0, //shoulder degrees
  		 180, //elbow degrees
  		 180, //wrist rotation degrees
  		 180, //wrist vertical degrees
  		 70); //tongue degrees
  
 delay(1000);

}
