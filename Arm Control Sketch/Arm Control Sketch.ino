// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo shoulder, arm, forearm, grip;

// Define the servo pin:
#define shoulderPin 8
#define armPin 9
#define forearmPin 12
#define gripPin 13

// Create a variables to store the servos positions:
int shoulderAngle = 90;
int armAngle = 90;
int forearmAngle = 90;
int gripAngle = 0;

//Create variable to store the rx_byte received
char rx_byte = 0;

void setup() 
{
  shoulder.attach(shoulderPin);
  arm.attach(armPin);
  forearm.attach(forearmPin);
  grip.attach(gripPin);



  shoulder.write(shoulderAngle);
  arm.write(armAngle);
  forearm.write(forearmAngle);
  grip.write(gripAngle);

  Serial.begin(4800);
}




void loop() 
{

  if (Serial.available() > 0) 
  {    
    rx_byte = Serial.read();
    switch (rx_byte) 
    {
      case 'f': // forward pressed
      if(armAngle > 0)
      {
        armAngle--;
        forearmAngle--;
        arm.write(armAngle);
        forearm.write(forearmAngle);
        
      }
      break;

      case 'b': // backward pressed
      if(armAngle < 90)
      {
        armAngle++;
        forearmAngle++;
        arm.write(armAngle);
        forearm.write(forearmAngle);
        
      }
      break;

      case 'l': // left pressed
      if(shoulderAngle < 180)
      {
        shoulderAngle++;
        shoulder.write(shoulderAngle);
        
      }
      break;

      case 'r': // right pressed
      if(shoulderAngle > 0)
      {

        shoulderAngle--;
        shoulder.write(shoulderAngle);
        
      }
      break;

      case 'q': // forward + left pressed
      
      break;

      case 'e': // forward + right pressed
      
      break;

      case 'z': // backward + left pressed
      
      break;

      case 'c': // backward + right pressed
      
      break;

      case 'o': // open grip
      grip.write(180);
      break;

      case 'k': // close grip
      grip.write(0);
      break;

      default: // some other key is pressed
      //do nothing
      break;
    }
  } 
}
