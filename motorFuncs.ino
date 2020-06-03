void right_forward()
{
  digitalWrite(motor_right_for,HIGH);
  digitalWrite(motor_right_back,LOW);
  
}

void left_forward()
{
  digitalWrite(motor_left_for,HIGH);
  digitalWrite(motor_left_back,LOW);
  
}

void right_backward()
{
  digitalWrite(motor_right_for,LOW);
  digitalWrite(motor_right_back,HIGH);
  
}


void left_backward()
{
  digitalWrite(motor_left_for,LOW);
  digitalWrite(motor_left_back,HIGH);
  
}

void right_stop()
{
  digitalWrite(motor_right_for,LOW);
  digitalWrite(motor_right_back,LOW);
  
}

void left_stop()
{
  digitalWrite(motor_left_for,LOW);
  digitalWrite(motor_left_back,LOW);
  
}
