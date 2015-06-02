void getGeschwindigkeit (float zaehler)
{
  float Umfang=223.43;
  Geschwindigkeit=(zaehler/15)*Umfang;
  
  
  Serial.print("V: ");
  Serial.print(Geschwindigkeit);
  Serial.println();
  
}
