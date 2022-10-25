// Yanked from my 425 Project, changes to pin values may be needed.
#define LMOTOR_IN1 2
#define LMOTOR_IN2 3
#define LMOTOR_IN3 4 // define pins, changes might be needed
#define LMOTOR_IN4 5
#define RMOTOR_IN1 23
#define RMOTOR_IN2 25
#define RMOTOR_IN3 27
#define RMOTOR_IN4 29


void setup() {
  pinMode (LMOTOR_IN1, OUTPUT);
  pinMode (LMOTOR_IN2, OUTPUT); // sets up motors with pins
  pinMode (LMOTOR_IN3, OUTPUT);
  pinMode (LMOTOR_IN4, OUTPUT);
  pinMode (RMOTOR_IN1, OUTPUT);
  pinMode (RMOTOR_IN2, OUTPUT);
  pinMode (RMOTOR_IN3, OUTPUT); 
  pinMode (RMOTOR_IN4, OUTPUT);


}

void loop() { // BEFORE YOU START, PROP UP THE ROBOT OR HOLD IT BECAUSE IT WILL MOVE AFTER BRAKE COMMAND

  // Code below is for testing the robot's navigation and to ensure the motors are wired to the motor controllers correctly.
  Brake();
  delay(3000);
  Forward();
  delay(500);
  Brake();
  delay(2000);
  Backward();
  delay(500);
  Brake();
  delay(2000);
  Right();
  delay(500);
  Brake();
  delay(2000);
  Left();
  delay(500);
  while(1) {
    Brake();
  }
}




void Forward(){
  digitalWrite(LMOTOR_IN1,LOW); // HIGH,LOW sets the motor fowards
  digitalWrite(LMOTOR_IN2,HIGH); //LIN1 and LIN2 is motor 1(Left side)
  digitalWrite(LMOTOR_IN3,HIGH);//LIN3 and LIN4 is motor 2(Left Side)
  digitalWrite(LMOTOR_IN4,LOW);
  
  digitalWrite(RMOTOR_IN1,LOW); // Both left and right side go foward
  digitalWrite(RMOTOR_IN2,HIGH);
  digitalWrite(RMOTOR_IN3,HIGH);//RIN1 and RIN2 is motor 3(Right side)
  digitalWrite(RMOTOR_IN4,LOW); //RIN3 and RIN4 is motor 4(Right side)
  
}

void Backward(){
  digitalWrite(LMOTOR_IN1,HIGH); //LOW,HIGH sets the motor backwards
  digitalWrite(LMOTOR_IN2,LOW);
  digitalWrite(LMOTOR_IN3,LOW);
  digitalWrite(LMOTOR_IN4,HIGH);

  digitalWrite(RMOTOR_IN1,HIGH); // Both left and right side go backwards
  digitalWrite(RMOTOR_IN2,LOW);
  digitalWrite(RMOTOR_IN3,LOW);
  digitalWrite(RMOTOR_IN4,HIGH);
  
}
void Left(){
  digitalWrite(LMOTOR_IN1,HIGH); // Left side goes backwards, 
  digitalWrite(LMOTOR_IN2,LOW);// Right side goes forwards,
  digitalWrite(LMOTOR_IN3,LOW); // this results in the robot turning0 counter-clockwise
  digitalWrite(LMOTOR_IN4,HIGH);

  digitalWrite(RMOTOR_IN1,LOW); 
  digitalWrite(RMOTOR_IN2,HIGH);
  digitalWrite(RMOTOR_IN3,HIGH);
  digitalWrite(RMOTOR_IN4,LOW);
}

void Right(){
  digitalWrite(RMOTOR_IN1,HIGH); // Right side goes backwards,
  digitalWrite(RMOTOR_IN2,LOW);// Left side goes forwards,
  digitalWrite(RMOTOR_IN3,LOW);// this results in the robot turning clock-wise,
  digitalWrite(RMOTOR_IN4,HIGH);

  digitalWrite(LMOTOR_IN1,LOW); 
  digitalWrite(LMOTOR_IN2,HIGH);
  digitalWrite(LMOTOR_IN3,HIGH);
  digitalWrite(LMOTOR_IN4,LOW);
}

void Brake(){
  digitalWrite(LMOTOR_IN1,LOW);
  digitalWrite(LMOTOR_IN2,LOW);
  digitalWrite(LMOTOR_IN3,LOW);
  digitalWrite(LMOTOR_IN4,LOW);

  digitalWrite(RMOTOR_IN1,LOW);
  digitalWrite(RMOTOR_IN2,LOW);
  digitalWrite(RMOTOR_IN3,LOW);
  digitalWrite(RMOTOR_IN4,LOW);
  
}