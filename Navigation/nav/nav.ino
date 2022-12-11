#include <SoftwareSerial.h> // module for arduino to use BT
SoftwareSerial bluetooth(12, 13); // declare bluetooth serial object, with established pins for Rx and Tx 
// Yanked from my 425 Project, changes to pin values may be needed.
#define FMOTOR_IN1 47
#define FMOTOR_IN2 49
#define FMOTOR_IN3 51 // define pins, changes might be needed
#define FMOTOR_IN4 53
#define BMOTOR_IN1 23
#define BMOTOR_IN2 22
#define BMOTOR_IN3 25
#define BMOTOR_IN4 24

long tick = 0;
long max_ticks = 75000;
bool is_connected = false;
void setup() {
  pinMode (FMOTOR_IN1, OUTPUT);
  pinMode (FMOTOR_IN2, OUTPUT); // sets up motors with pins
  pinMode (FMOTOR_IN3, OUTPUT);
  pinMode (FMOTOR_IN4, OUTPUT);
  pinMode (BMOTOR_IN1, OUTPUT);
  pinMode (BMOTOR_IN2, OUTPUT);
  pinMode (BMOTOR_IN3, OUTPUT); 
  pinMode (BMOTOR_IN4, OUTPUT);
  Serial.begin(9600);  // limits the max amount of data that can be sent through
  bluetooth.begin(9600);
  Brake();
}

void loop() { // BEFORE YOU START, PROP UP THE ROBOT OR HOLD IT BECAUSE IT WILL MOVE AFTER BRAKE COMMAND

  while(1) {
    char varIn = bluetooth.read();
    if(varIn == 'b') {
      Backward();
    } else if(varIn == 'f') {
      Forward();
    } else if(varIn == 's') {
      Brake();
    } else if(varIn == 'l') {
      Left();
    } else if(varIn == 'r') {
      Right();
    }

    tick++;
    if(tick >= max_ticks) {
      tick = 0;
      Brake();
    }
  }
}


void Forward(){
  digitalWrite(FMOTOR_IN1,LOW); // HIGH,LOW sets the motor fowards
  digitalWrite(FMOTOR_IN2,HIGH); //LIN1 and LIN2 is motor 1(Left side)
  digitalWrite(FMOTOR_IN3,LOW);//LIN3 and LIN4 is motor 2(Left Side)
  digitalWrite(FMOTOR_IN4,HIGH);
  
  digitalWrite(BMOTOR_IN1,HIGH); // Both left and right side go foward
  digitalWrite(BMOTOR_IN2,LOW);
  digitalWrite(BMOTOR_IN3,HIGH);//RIN1 and RIN2 is motor 3(Right side)
  digitalWrite(BMOTOR_IN4,LOW); //RIN3 and RIN4 is motor 4(Right side)
  
}

void Backward(){
  digitalWrite(FMOTOR_IN1,HIGH); //LOW,HIGH sets the motor backwards
  digitalWrite(FMOTOR_IN2,LOW);
  digitalWrite(FMOTOR_IN3,HIGH);
  digitalWrite(FMOTOR_IN4,LOW);

  digitalWrite(BMOTOR_IN1,LOW); // Both left and right side go backwards
  digitalWrite(BMOTOR_IN2,HIGH);
  digitalWrite(BMOTOR_IN3,LOW);
  digitalWrite(BMOTOR_IN4,HIGH);
  
}
void Left(){
  digitalWrite(FMOTOR_IN1,HIGH); // Left side goes backwards, 
  digitalWrite(FMOTOR_IN2,LOW);// Right side goes forwards,
  digitalWrite(FMOTOR_IN3,LOW); // this results in the robot turning0 counter-clockwise
  digitalWrite(FMOTOR_IN4,HIGH);

  digitalWrite(BMOTOR_IN1,HIGH); 
  digitalWrite(BMOTOR_IN2,LOW);
  digitalWrite(BMOTOR_IN3,LOW);
  digitalWrite(BMOTOR_IN4,HIGH);
}

void Right(){
  digitalWrite(BMOTOR_IN1,LOW); // Right side goes backwards,
  digitalWrite(BMOTOR_IN2,HIGH);// Left side goes forwards,
  digitalWrite(BMOTOR_IN3,HIGH);// this results in the robot turning clock-wise,
  digitalWrite(BMOTOR_IN4,LOW);

  digitalWrite(FMOTOR_IN1,LOW); 
  digitalWrite(FMOTOR_IN2,HIGH);
  digitalWrite(FMOTOR_IN3,HIGH);
  digitalWrite(FMOTOR_IN4,LOW);
}

void Brake(){
  digitalWrite(FMOTOR_IN1,LOW);
  digitalWrite(FMOTOR_IN2,LOW);
  digitalWrite(FMOTOR_IN3,LOW);
  digitalWrite(FMOTOR_IN4,LOW);

  digitalWrite(BMOTOR_IN1,LOW);
  digitalWrite(BMOTOR_IN2,LOW);
  digitalWrite(BMOTOR_IN3,LOW);
  digitalWrite(BMOTOR_IN4,LOW);
  
}