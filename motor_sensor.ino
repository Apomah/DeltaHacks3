#include "NewPing.h"
NewPing sonar[3] = {
  NewPing(4,5,400),
  NewPing(6,7,400),
  NewPing(8,9,400)
};

#define rightLow 13
#define rightHigh 12
#define leftHigh 11
#define leftLow 10

void setup(){
  pinMode(rightLow,OUTPUT);
  pinMode(rightHigh,OUTPUT);
  pinMode(leftHigh,OUTPUT);
  pinMode(leftHigh,OUTPUT);
  Serial.begin(9600);
  Serial.println("HC-SR4 testing..");
  delay(1000);
}

void loop(){
  sensorRun();
  motorForward();
  delay(1000);
  sensorRun();
  motorBackward();
  delay(1000);
  sensorRun();
  motorRight();
  delay(1000);
  sensorRun();
  motorLeft();
  delay(1000);
  sensorRun();
  motorOff();
  delay(1000);
}

void sensorRun(){
  Serial.print("Sonar 1: ");
  Serial.print(sonar[0].ping_cm());
  Serial.println("cm ");
  Serial.print("Sonar 2: ");
  Serial.print(sonar[1].ping_cm());
  Serial.println("cm ");
  Serial.print("Sonar 3: ");
  Serial.print(sonar[2].ping_cm());
  Serial.println("cm ");
}

void motorForward(){
  digitalWrite(rightLow,LOW);
  digitalWrite(rightHigh,HIGH);
  digitalWrite(leftHigh,HIGH);
  digitalWrite(leftLow,LOW);
}

void motorBackward(){
  digitalWrite(rightLow,HIGH);
  digitalWrite(rightHigh,LOW);
  digitalWrite(leftHigh,LOW);
  digitalWrite(leftLow,HIGH);
}

void motorLeft(){
  digitalWrite(rightLow,LOW);
  digitalWrite(rightHigh,LOW);
  digitalWrite(leftHigh,HIGH);
  digitalWrite(leftLow,LOW);
}

void motorRight(){
  digitalWrite(rightLow,LOW);
  digitalWrite(rightHigh,HIGH);
  digitalWrite(leftHigh,LOW);
  digitalWrite(leftLow,LOW);
}

void motorOff(){
  digitalWrite(rightLow,LOW);
  digitalWrite(rightHigh,LOW);
  digitalWrite(leftHigh,LOW);
  digitalWrite(leftLow,LOW);
}

