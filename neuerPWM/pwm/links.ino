void links()
{
  if (halt==0)
  {
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  richtung=1;
  pwm=50;
  Serial.println();
  Serial.print(richtung);
  Serial.print(" Links rum");
  }
}
