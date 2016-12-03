#pragma config(Sensor, dgtl1,  LeftDriver,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  RightDriver,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  ThrowerEncoder, sensorQuadEncoder)
#pragma config(Motor,  port2,           leftDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           strafeDrive,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           liftRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           liftLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           rightThrow,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           leftThrow,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "ThrowerControl.c" // Controls the thrower
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "BlueDriverJoyStickControls.c" // User Controls For User Controlled Period
//#include "LEDLightTimers.c" // Led Light Timer for User Control Part
#include "Pid.c" // PID controller program its self explanatory idiot
//#include "LCDDisplay2016.c"

//int autoRoutineID = 0;

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
	//autoRoutineID = getAutoOption();

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...r
}
task autonomous()
{
	startTask(driving);
	startTask(throwerControl);
	startTask(autoRobotGo);
}

task usercontrol()
{
		startTask(throwerControl);
	  startTask(controllerPolling);
	  startTask(driving);
}
