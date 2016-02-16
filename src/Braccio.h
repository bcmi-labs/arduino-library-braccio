/*
  Braccio.h - board library Version 1.1
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

#ifndef BRACCIO_H_
#define BRACCIO_H_

#include <Arduino.h>
#include <Servo.h>

class _Braccio {

public:
  _Braccio();
  
  /**
   * Braccio initializations and set intial position
   * Modifing this function you can set up the initial position of all the
   * servo motors of the Braccio
   */
  unsigned int begin(); 
  
  /**
   * This functions allow you to control all the servo motors in the Braccio
   */
  int ServoMovement(int delay, int Vbase,int Vshoulder, int Velbow, int Vwrist_ver, int Vwrist_rot, int Vgripper); 


};

extern _Braccio Braccio;

#endif // BRACCIO_H_
