//Path Follower and Obstacle Avoider Car Using Arduino

// Install NewPing library 
/*
  Steps to install NewPing lib:-
   * GoTo Sketch menu
   * Hover on Include Library
   * Click on Library Manager
   * Search for NewPing Library
   * Download it and close
*/

#include<NewPing.h> //NewPing Library for Ultrasonic Sensor

int ENA = 3;  //ENA connected to digital pin 3
int ENB = 9;  //ENB connected to digital pin 9
int RIGHT = 4; // RIGHT IR sensor connected to digital pin 4
int LEFT = 5;  // LEFT IR sensor connected to digital pin 5
int MOTOR_L = 6; // MOTOR_B1 connected to digital pin 6
int MOTOR_R = 7; // MOTOR_B2 connected to digital pin 7

#define TRIG A2 // TRIG PIN connected to analog pin A2
#define ECHO A3 // ECHO PIN connected to analog pin A3
#define D 100 // Define Maximum Distance

NewPing sonar(TRIG, ECHO, D); //From NewPing Library

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT); // initialize ENA pin as an output
  pinMode(ENB, OUTPUT); // initialize ENB pin as an output
  pinMode(MOTOR_L, OUTPUT); // initialize MOTOR_L pin as an output
  pinMode(MOTOR_R, OUTPUT); // initialize MOTOR_R pin as an output
  pinMode(RIGHT, INPUT); // initialize RIGHT pin as an input
  pinMode(LEFT, INPUT);  // initialize LEFT pin as an input
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(60);
  int distance = sonar.ping_cm();
  if (distance == 0) {
    distance = 30;
  }
  if(distance<=20) {  //Obstacle Avoiding
    Stop();
    delay(150);
    turnRight();
    delay(300);
    moveForward();
    delay(400);
    turnLeft();
    delay(300);
    moveForward();
    delay(600);
    turnLeft();
    delay(300);
    moveForward();
    delay(400);
    turnRight();
    delay(400);
  }
  if (digitalRead(LEFT)==HIGH && digitalRead(RIGHT)==HIGH) {
    
    moveForward();
    
  }else if (digitalRead(LEFT)==LOW && digitalRead(RIGHT)==HIGH) {

    turnLeft();
  
  }else if (digitalRead(LEFT)==HIGH && digitalRead(RIGHT)==LOW) {
    
    turnRight();
    
  }else if (digitalRead(LEFT)==LOW && digitalRead(RIGHT)==LOW) {
   
    Stop();
  }
}

void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);
}
void turnRight() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, HIGH);
}
void turnLeft() {
  analogWrite(ENA,100);
  analogWrite(ENB, 100);
  digitalWrite(MOTOR_L, HIGH);
  digitalWrite(MOTOR_R, LOW);
}
void moveForward() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(MOTOR_L, HIGH);
  digitalWrite(MOTOR_R, HIGH);
}
