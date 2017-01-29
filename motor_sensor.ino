#include "NewPing.h"
NewPing sonar[3] = {
  NewPing(1,3,400),
  NewPing(5,4,400),
  NewPing(6,7,400)
};

void setup(){
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
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
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}

void motorBackward(){
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}

void motorLeft(){
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void motorRight(){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}

void motorOff(){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

