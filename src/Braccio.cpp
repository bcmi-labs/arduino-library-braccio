/*
 Braccio.cpp - board library Version 1.1
 Written by Andrea Martino

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Braccio.h"

extern Servo base;
extern Servo shoulder;
extern Servo elbow;
extern Servo wrist_rot;
extern Servo wrist_ver;
extern Servo gripper;

extern int step_base = 0;
extern int step_shoulder = 45;
extern int step_elbow = 180;
extern int step_wrist_rot = 180;
extern int step_wrist_ver = 90;
extern int step_gripper = 10;

_Braccio Braccio;

//Initialize Braccio object
_Braccio::_Braccio() {
}

/**
 * Braccio initialization and set intial position
 * Modifing this function you can set up the initial position of all the
 * servo motors of the Braccio
 */
unsigned int _Braccio::begin() {
	// initialization pin Servo motors
	#if defined(ARDUINO_ARCH_SAMD)
		base.attach(11);
		shoulder.attach(7);
		elbow.attach(9);
		wrist_rot.attach(6);
		wrist_ver.attach(8);
		gripper.attach(3);
	#else
		base.attach(11);
		shoulder.attach(10);
		elbow.attach(9);
		wrist_rot.attach(6);
		wrist_ver.attach(5);
		gripper.attach(3);
	#endif	

	//For each step motor this set up the initial degree
	base.write(90);
	shoulder.write(45);
	elbow.write(180);
        wrist_ver.write(180);
        wrist_rot.write(90);
        gripper.write(10);
	//Previous step motor position
	step_base = 90;
	step_shoulder = 45;
	step_elbow = 180;
	step_wrist_ver = 180;
	step_wrist_rot = 90;
	step_gripper = 10;
	return 1;
}

/**
 * This functions allow you to control all the servo motors in the Braccio setting the funcion parameters.
 * 
 * @param stepDelay The delay between each servo movement
 * @param vBase next base servo motor degree
 * @param vShoulder next shoulder servo motor degree
 * @param vElbow next elbow servo motor degree
 * @param vWrist_ver next wrist rotation servo motor degree
 * @param vWrist_rot next wrist vertical servo motor degree
 * @param vgripper next gripper servo motor degree
 */
int _Braccio::ServoMovement(int stepDelay, int vBase, int vShoulder, int vElbow,int vWrist_ver, int vWrist_rot, int vgripper) {

        // Check values
        if (stepDelay > 30) stepDelay = 30;
	if (stepDelay < 10) stepDelay = 10;
	if (vBase < 0) vBase=0;
	if (vBase > 180) vBase=180;
	if (vShoulder < 15) vShoulder=15;
	if (vShoulder > 165) vShoulder=165;
	if (vElbow < 0) vElbow=0;
	if (vElbow > 180) vElbow=180;
	if (vWrist_ver < 0) vWrist_ver=0;
	if (vWrist_ver > 180) vWrist_ver=180;
	if (vWrist_rot > 180) vWrist_rot=180;
	if (vWrist_rot < 0) vWrist_rot=0;
        if (vgripper < 10) vgripper = 10;
	if (vgripper > 73) vgripper = 73;

	int exit = 1;

	//Until the all motors are in the desired position
	while (exit) 
	{			
		//For each servo motor if next degree is not the same of the previuos than do the movement		
		if (vBase != step_base) 
		{			
			base.write(step_base);
			//One step ahead
			if (vBase > step_base) {
				step_base++;
			}
			//One step beyond
			if (vBase < step_base) {
				step_base--;
			}
		}

		if (vShoulder != step_shoulder)  
		{
			shoulder.write(step_shoulder);
			//One step ahead
			if (vShoulder > step_shoulder) {
				step_shoulder++;
			}
			//One step beyond
			if (vShoulder < step_shoulder) {
				step_shoulder--;
			}

		}

		if (vElbow != step_elbow)  
		{
			elbow.write(step_elbow);
			//One step ahead
			if (vElbow > step_elbow) {
				step_elbow++;
			}
			//One step beyond
			if (vElbow < step_elbow) {
				step_elbow--;
			}

		}

		if (vWrist_ver != step_wrist_rot) 
		{
			wrist_rot.write(step_wrist_rot);
			//One step ahead
			if (vWrist_ver > step_wrist_rot) {
				step_wrist_rot++;				
			}
			//One step beyond
			if (vWrist_ver < step_wrist_rot) {
				step_wrist_rot--;
			}

		}

		if (vWrist_rot != step_wrist_ver)
		{
			wrist_ver.write(step_wrist_ver);
			//One step ahead
			if (vWrist_rot > step_wrist_ver) {
				step_wrist_ver++;
			}
			//One step beyond
			if (vWrist_rot < step_wrist_ver) {
				step_wrist_ver--;
			}
		}

		if (vgripper != step_gripper)
		{
			gripper.write(step_gripper);
			if (vgripper > step_gripper) {
				step_gripper++;
			}
			//One step beyond
			if (vgripper < step_gripper) {
				step_gripper--;
			}
		}

		
		//The delay between each movement
		delay(stepDelay);
		
		//It checks if all the servo motors are in the desired position 
		if ((vBase == step_base) && (vShoulder == step_shoulder)
				&& (vElbow == step_elbow) && (vWrist_ver == step_wrist_rot)
				&& (vWrist_rot == step_wrist_ver) && (vgripper == step_gripper)) {
			step_base = vBase;
			step_shoulder = vShoulder;
			step_elbow = vElbow;
			step_wrist_rot = vWrist_ver;
			step_wrist_ver = vWrist_rot;
			step_gripper = vgripper;
			exit = 0;
		} else {
			exit = 1;
		}

	}

}
