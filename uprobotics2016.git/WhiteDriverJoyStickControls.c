// Read Buttons to see if any are pushed

bool strafeMode = false;

int strafeSpeed = 0;
int rightDriveSpeed = 0;
int leftDriveSpeed = 0;

task controllerPolling(){
	while(true){
		if((vexRT[Ch2] > 20) || (vexRT[Ch2] < -20)) {
			rightDriveSpeed = vexRT[Ch2];
		}
		else {
			rightDriveSpeed = 0;
		}
		if((vexRT[Ch3] > 20) || (vexRT[Ch3] < - 20)) {
			leftDriveSpeed = vexRT[Ch3];
		}
		else {
			leftDriveSpeed = 0;
		}
		if(strafeMode	== true){
			rightDriveSpeed = leftDriveSpeed;
			if ((vexRT[Ch1] > 20) || (vexRT[Ch1] < - 20)) {
				strafeSpeed = vexRT[Ch1];
			}
			else {
				strafeSpeed = 0;
			}
		}
		if(vexRT[Btn5U] == 1)
		{
			motor[rightThrow] = 127;
			motor[leftThrow] = 127;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[rightThrow] = -127;
			motor[leftThrow] = -127;
		}
		else
		{
			if((vexRT[Ch3Xmtr2] > 20) || (vexRT[Ch3Xmtr2] < - 20))
			{
				motor[rightThrow] = vexRT[Ch3Xmtr2];
				motor[leftThrow] = vexRT[Ch3Xmtr2];
			}
			else {
				motor[rightThrow] = 0;
				motor[leftThrow] = 0;
			}
		}
		if(vexRT[Btn7U] == 1){
			// Turn drive train into strafe mode to enable easier access around the field
			strafeMode = !strafeMode;
			delay(300);
		}
		delay(10);
	}
}
// Add driver joystick Controls here
task driving(){

	while(true)
	{
		// Tank Drive Mode
		if(strafeMode == false){
			//Right Drive;
				motor[rightDrive] = rightDriveSpeed;
				motor[leftDrive] = leftDriveSpeed;
		}
//In strafeMode
		else {
			//writeDebugStreamLine("***** Drive Loop ******");
			motor[rightDrive] 	= rightDriveSpeed;
			motor[leftDrive] 		= leftDriveSpeed;
			motor[strafeDrive] 	= strafeSpeed;
		}
	}
		delay(5);
}
// End Driver joystick Controls
