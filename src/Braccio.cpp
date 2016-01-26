/*
 Braccio.cpp - board library Version 1.1
 Written by Andrea Martino
 Copyright (c) 2015 Medea-solutions  All right reserved.

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
extern Servo tongue;

extern int step_base = 0;
extern int step_shoulder = 135;
extern int step_elbow = 35;
extern int step_wrist_rot = 0;
extern int step_wrist_ver = 170;
extern int step_tongue = 120;

_Braccio Braccio;

//Initialize Braccio object
_Braccio::_Braccio() {
}


/**
 * Braccio initialization
 */
boolean _Braccio::Initialization() {
	// initialization pin Servo motors
	#if defined(ARDUINO_ARCH_SAMD)
		base.attach(11);
		shoulder.attach(7);
		elbow.attach(9);
		wrist_rot.attach(6);
		wrist_ver.attach(8);
		tongue.attach(3);
	#else
		base.attach(11);
		shoulder.attach(10);
		elbow.attach(9);
		wrist_rot.attach(6);
		wrist_ver.attach(5);
		tongue.attach(3);
	#endif	
	
		
	return HIGH;
}

/**
 * Braccio Intial position
 * Modifing this function you can set up the initial position of all the
 * servo motors of the Braccio
 */
unsigned int _Braccio::InitArm() {
	//For each step motor this set up the initial degree
	base.write(0);
	shoulder.write(45);
	elbow.write(180);
	wrist_rot.write(180);
	wrist_ver.write(180);
	tongue.write(0);

	//Previous step motor position
	step_base = 0;
	step_shoulder = 45;
	step_elbow = 180;
	step_wrist_rot = 180;
	step_wrist_ver = 180;
	step_tongue = 0;
	return 1;

}

/**
 * This functions allow you to control all the servo motors in the Braccio setting the funcion parameters.
 * 
 * @param stepDelay The delay between each servo movement
 * @param vBase next base servo motor degree
 * @param vShoulder next shoulder servo motor degree
 * @param vElbow next elbow servo motor degree
 * @param vWrist_rot next wrist rotation servo motor degree
 * @param vWrist_ver next wrist vertical servo motor degree
 * @param vTongue next tongue servo motor degree
 */
int _Braccio::ServoMovement(int stepDelay, int vBase, int vShoulder, int vElbow,
		int vWrist_rot, int vWrist_ver, int vTongue) {
	//check max tongue degree value
	if (vTongue > 67)
		vTongue = 67;

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

		if (vWrist_rot != step_wrist_rot) 
		{
			wrist_rot.write(step_wrist_rot);
			//One step ahead
			if (vWrist_rot > step_wrist_rot) {
				step_wrist_rot++;				
			}
			//One step beyond
			if (vWrist_rot < step_wrist_rot) {
				step_wrist_rot--;
			}

		}

		if (vWrist_ver != step_wrist_ver)
		{
			wrist_ver.write(step_wrist_ver);
			//One step ahead
			if (vWrist_ver > step_wrist_ver) {
				step_wrist_ver++;
			}
			//One step beyond
			if (vWrist_ver < step_wrist_ver) {
				step_wrist_ver--;
			}
		}

		if (vTongue != step_tongue)
		{
			tongue.write(step_tongue);
			if (vTongue > step_tongue) {
				step_tongue++;
			}
			//One step beyond
			if (vTongue < step_tongue) {
				step_tongue--;
			}
		}

		
		//The delay between each movement
		delay(stepDelay);
		
		//It checks if all the servo motors are in the desired position 
		if ((vBase == step_base) && (vShoulder == step_shoulder)
				&& (vElbow == step_elbow) && (vWrist_rot == step_wrist_rot)
				&& (vWrist_ver == step_wrist_ver) && (vTongue == step_tongue)) {
			step_base = vBase;
			step_shoulder = vShoulder;
			step_elbow = vElbow;
			step_wrist_rot = vWrist_rot;
			step_wrist_ver = vWrist_ver;
			step_tongue = vTongue;
			exit = 0;
		} else {
			exit = 1;
		}

	}

}

