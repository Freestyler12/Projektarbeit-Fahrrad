void rechts()
{
  if (halt==0)
  {
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  richtung=0;
  pwm=45;
  Serial.println();
  Serial.print(richtung);
  Serial.print("Rechts rum");
  }
}
