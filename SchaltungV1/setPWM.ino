void setPWM(int zaehler)
{
  pwmDuty=map(zaehler, 0, 20, 0, 255);
  
  //Serial.print(zaehler);
  //Serial.print(" , ");
  //Serial.print(pwmDuty);
  //Serial.println();
  
  analogWrite(13,pwmDuty);
    
}
