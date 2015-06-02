#include "TimerOne.h"

////////////////////////////////////////////////////////////////////////////////////////////////
//                                    Variablen
////////////////////////////////////////////////////////////////////////////////////////////////

volatile int TimerFlag=0;
int zaehler1=0;
int zaehler2=0;

// Trittfrequenz/////////////////
int pinTrittsensor=3;
int interruptTrittsensor=0;
volatile int TrittZaehler=0;
float Trittfrequenz=0;

//Drehmoment/////////////////////
int pinDrehmoment=0;
int Drehmoment=0;


//Geschwindigkeit//////////////
int pinV=2;
int interruptV=1;
int V_zaehler=0;
float Geschwindigkeit;


int pwmDuty=0;


////////////////////////////////////////////////////////////////////////////////////////////////
//                                    Funktionen Interrupts
////////////////////////////////////////////////////////////////////////////////////////////////

void TimerISR()
{
  TimerFlag=1;
 }

void TrittISR()
{
  TrittZaehler++;
  //Serial.println(TrittZaehler);
 }
 
void VISR()
{
  V_zaehler++;
  
}
 

////////////////////////////////////////////////////////////////////////////////////////////////
//                                    Setup
////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{
  for (int i=0;i>=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  pinMode(pinTrittsensor, INPUT_PULLUP);
  attachInterrupt(interruptTrittsensor,TrittISR,RISING);
  attachInterrupt(interruptV,VISR,RISING);
  
  Timer1.initialize(10000);     //10ms Zeitbasis
  Timer1.attachInterrupt(TimerISR);
  //Timer1.pwm(9,500);
  
  Serial.begin(9600);
  
  
}


////////////////////////////////////////////////////////////////////////////////////////////////
//                                    Main-Loop
////////////////////////////////////////////////////////////////////////////////////////////////

void loop() 
{
  
  if (TimerFlag==1)
  {
    ///////////////// Zeitbasis 10ms /////////////////
    //Serial.println(zaehler1);
    
    if (zaehler1>=100)
    {
      ///////////////// Zeitbasis 1000ms //////////////////
      getTrittfrequenz(TrittZaehler, zaehler1);
      
      //setPWM(TrittZaehler);
            
      getDrehmoment();
      
      getGeschwindigkeit(V_zaehler);
      
      TrittZaehler=0;
      zaehler1=0;
      
    }
    else
    {
      zaehler1++;
    }
    
    TimerFlag=0;
  } 

}
