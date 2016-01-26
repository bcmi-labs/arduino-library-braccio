
/*
  simpleMovements.ino V1.1

 This  sketch simpleMovements move all servo motors from 0 to 180 degree
 
 M1=base degrees
 M2=shoulder degrees
 M3=elbow degrees
 M4=wrist rotation degrees
 M5=wrist vertical degrees
 M6=tongue degrees

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
                      //step delay  M1, M2, M3, M4, M5, M6
 Braccio.ServoMovement(20,         ,0   180, 0,  0,  0, 0);
 
 delay(1000);
                      //step delay  M1, M2,   M3,   M4,  M5, M6
 Braccio.ServoMovement(20,         ,180, 0,  180,  180, 180, 67); 
  
 delay(1000);

}
