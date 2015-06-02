int eingabe=0;
int op=0;
int opadd=0;
int halt=0;
int pwm;

int richtung;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  
 
  
}

void loop() 
{
  opadd=0;
  for (int i=0; i<50;i++)
  {
  op=analogRead(A0);
  opadd=opadd+op;
  }
  opadd=opadd/50;
  opadd=map(opadd,0,1024,0,5000);
  
  Serial.println();
  Serial.print(millis());
  Serial.print(",");
  Serial.print(opadd);
  
  
  switch (richtung)
  {
    case 1:
      if (opadd >=2500)
      {
        halt=1;
        pwm=0;
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        }
       break;
     case 0:
       if (opadd>=2500)
       { 
        halt=1;
        pwm=0;
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
        Serial.print("STOP");
       }
      break;
      
   }
  
  
  if (Serial.available() >0)
  {
    eingabe= Serial.read()-32;
    
    switch (eingabe)
   {
    case 0:
      stopp();
      break;
    case 76:
      links();
      break;
    case 82:
      rechts();
      break;
   }
    
    Serial.flush();
    
   
    
   }
   analogWrite(3,pwm);
   
   delay(250);
}
