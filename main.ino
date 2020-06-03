// 0 is BLACK
// 1 is White



#include "define.h"



void setup() {
  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);
  pinMode(lineFollowSensor5, INPUT);
  pinMode(lineFollowSensor6, INPUT);
  pinMode(lineFollowSensor7, INPUT);
  pinMode(motor_en_left,OUTPUT);
  pinMode(motor_left_for,OUTPUT);
  pinMode(motor_left_back,OUTPUT);
  pinMode(motor_en_right,OUTPUT);
  pinMode(motor_right_for,OUTPUT);
  pinMode(motor_right_back,OUTPUT);
  analogWrite(motor_en_left,255);
  analogWrite(motor_en_right,255);
}

void loop() {

  readSensors();
  switch(mode)
  {
    case FOLLOWING_LINE:
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            right_forward();
            left_forward();
            break;
      
    case LEFT_LINE:
            right_forward();
            left_backward();
            delay(480);
            right_stop();
            left_stop();
            delay(500);
            pathI+='L';
            break;


     case THRE_LINE:
            right_stop();
            left_stop();
            delay(300);
            readSensors();

            if(mode==THRE_LINE){
              right_stop();
              left_stop();
              delay(5000);
            }
            else{
              right_forward();
              left_backward();
              delay(480);
              right_stop();
              left_stop();
              delay(500);
              pathI+='L';
            }

            break;


       
    case RIGHT_LINE:
            right_stop();
            left_stop();
            delay(300);
            readSensors();
      
            if(mode==NO_LINE){
              left_forward();
              right_backward();
              delay(480);
              right_stop();
              left_stop();
              delay(500);
              pathI+='L';
            }
            else{
              pathI+='S';
            }
            
            break;

  
     
      
    case NO_LINE:
            delay(170);
            right_forward();
            left_backward();
            delay(900);
            right_stop();
            left_stop();
            delay(100);
            pathI+='U';
            break;
      
    case ERR_RIGHT:
            analogWrite(motor_en_left,180);
            analogWrite(motor_en_right,255);
            right_forward();
            left_forward();
            delay(5);
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            break;
            
    case ERR_LEFT:
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,180);
            right_forward();
            left_forward();
            delay(5);
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            break;

    case ERR_R_RIGHT:
            analogWrite(motor_en_right,255);
            right_forward();
            left_stop();
            delay(20);
            right_stop();
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            break;
            
    case ERR_R_LEFT:
            analogWrite(motor_en_left,255);
            left_forward();
            right_stop();
            delay(20);
            right_stop();
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            break;
    
  }
  delay(5);
}
  
