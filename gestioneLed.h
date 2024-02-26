#define SET(x,y) (x|=(1<<y))
#define CLR(x,y) (x&=(~(1<<y)))
//------------per led
int latchPin = 8;
int clockPin = 6;
int dataPin = 3;
int pinState;
void modificaLedWorth(short);
//-------------------

void setUpLed();
void aggiornaLed(int);

int prog;
int inc;
char led=0;
char ledP;

void stampaLed(char l)
{
  if(l==0)
  {
     //digitalWrite(latchPin, 0);
     CLR(PORTB, 0);
     modificaLedWorth(0);
     SET(PORTB, 0);
     //digitalWrite(latchPin, 1);
   }
   else if(l==1)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(1);
      //modificaLed(  B00000000);
      //modificaLed(  B00000001);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==2)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(3);
      //modificaLed(  B00000000);
      //modificaLed(  B00000011);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==3)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(7);
      //modificaLed(  B00000000);
      //modificaLed(  B00000111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==4)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(15);
      //modificaLed(  B00000000);
      //modificaLed(  B00001111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==5)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(31);
      //modificaLed(  B00000000);
      //modificaLed(  B00011111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==6)
   { 
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(63);
      //modificaLed(  B00000000);
      //modificaLed(  B00111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==7)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(127);
      //modificaLed(  B00000000);
      //modificaLed(  B01111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if (l==8)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(255);
      //modificaLed(  B00000000);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if (l==9)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(511);
      //modificaLed(  B00000001);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==10)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(1023);
      //modificaLed(  B00000011);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if (l==11)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(2047);
      //modificaLed(  B00000111);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==12)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(4095);
      //modificaLed(  B00001111);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==13)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(8191);
      //modificaLed(  B00011111);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==14)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(16383);
      //modificaLed(  B00111111);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
   else if(l==15)
   {
      //digitalWrite(latchPin, 0);
      CLR(PORTB, 0);
      modificaLedWorth(32767);
      //modificaLed(  B01111111);
      //modificaLed(  B11111111);
      SET(PORTB, 0);
      //digitalWrite(latchPin, 1);
   }
}

void aggiornaLed(int rpm)
{
  //incP=inc;
  inc=3000;
  prog=(rpmMAX-3000)/15;
  
  if( rpm < inc)// and led!=0)
  {
    //ledP=led;
    led=0;
  }
  if( rpm> inc )//and led!=1)
  {
    //ledP=led;
    led=1;
  }
  inc+=prog;
  //led 2
  if( rpm> 4390)// and led!=2)
  {
    //ledP=led;
    led=2;
  }
  //led 3
  inc+=prog;
  if( rpm> inc)// and led!=3)
  {
     //ledP=led;
     led=3;
  }
  //led 4
  inc+=prog;
  if( rpm> inc )//and led!=4)
  {
    //ledP=led;
    led=4;
  }
  //led 5
  inc+=prog;
  if( rpm> inc )//and led!=5)
  {
    //ledP=led;
    led=5;
  }
  inc+=prog;
  //led 6
  if( rpm> inc )//and led!=6)
  {
    //ledP=led;
    led=6;
  }
  inc+=prog;
  //led 7
  if( rpm> inc )//and led!=7)
  {
    //ledP=led;
    led=7;
  }
  inc+=prog;
  //led 8
    if( rpm> inc )//and led!=8)
    {
      //ledP=led;
      led=8;
    }
    inc+=prog;
      //led 9
    if( rpm> inc )//and led!=9)
    {
      //ledP=led;
      led=9;
    }
    inc+=prog;
      //led 10
    if( rpm> inc )//and led!=10)
    {
      //ledP=led;
      led=10;
    }
    inc+=prog;
      //led 11
    if( rpm> inc )//and led!=11)
    {
      //ledP=led;
      led=11;
    }
  inc+=prog;
    //led 12
      //10730
    if( rpm> inc )//and led!=12)
    {      
      //ledP=led;
      led=12;
    }
  inc+=prog;
    //led 13
    if( rpm> inc )//and led !=13)
    {
      //ledP=led;
      led=13;
    }
    inc+=prog;
    if( rpm> inc )//and led!=14)
    {
      //ledP=led;
      led=14;
    }
  inc+=prog;
    if( rpm> inc )//and led!=15)
    {      
      //ledP=led;
      led=15;
    }
}

void setUpLed()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  CLR(PORTB, 0);
  modificaLedWorth(0);
  SET(PORTB, 0);
  delay(200);
}

void modificaLedWorth(short myDataOut)
{
  digitalWrite(dataPin, 0);
  digitalWrite(clockPin, 0);
  for (int i=15; i>=0; i--)
  {
    digitalWrite(clockPin, 0);
    if ( myDataOut & (1<<i) )
    {
      pinState= 1;
    }
    else
    {
      pinState= 0;
    }
    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(dataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(clockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);
  }

  //stop shifting
  digitalWrite(clockPin, 0);
}
