//-----------------per lo schermo
#include "Adafruit_GFX.h"
#include <Adafruit_ST7735.h>
#include "pagina1.h"

#define TFT_CS     5
#define TFT_RST    7
#define TFT_DC     9
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
//---------------------------

//*******************
//FUNZIONE PRINCIPALE
//*******************

//inizializzo lo schermo con dei dati base
void setUp()
{
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  //marcia
  tft.setCursor(RigaM,ColM);
  tft.setTextSize(8);
  tft.print(marcia);
  
  //velocita
  tft.setCursor(RigaVel,ColVel);
  tft.setTextSize(3);
  tft.print(vel);
  
  //giri motore
  tft.setCursor(RigaRpm,ColRpm);
  tft.setTextSize(2);
  tft.print(rpm);

  //ers
  tft.setCursor(RigaErs,ColErs);
  tft.print(ers);
  
  //tempo
  tft.setCursor(RigaT,ColT);
  tft.print(tempo);

  //miglior tempo
  tft.setCursor(RigaBestLap,ColBestLap);
  tft.setTextColor(0xF81F);
	tft.print(migliorTempo);
}

void setUp2()
{
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(RigaM,ColM-5);
  
  tft.setTextSize(5);
  tft.print(marcia);
  
  //velocita
  tft.setCursor(RigaVel,ColVel);
  tft.setTextSize(3);
  tft.print(vel);

  tft.setTextSize(2);
  tft.setCursor(5, 45);
  tft.setTextColor(ST7735_WHITE);
  tft.print(stampaDelivery(pwrLevel));
  //tft.setCursor(5,77);
  
  tft.setCursor(5, 77);
  tft.setTextColor(ST7735_WHITE);
  tft.print(recoveryLevel);

  tft.setCursor(5, 128);
  tft.setTextColor(ST7735_WHITE);
  tft.print(stampaMode(heatCharging));
  
}

void aggiornamentoVaiabili()
{
  velPre=vel;
  rpmPre=rpm;
  marciaPre= marcia;
  tempoPre=tempo;
  migliorTempoPre=migliorTempo;
  ultimoGiroPre=ultimoGiro;
  ersPre=ers;
  deltaPre=delta;
  paginaP=pagina;
  pwrLevelP=pwrLevel;
  recoveryLevelP=recoveryLevel;
  heatChargingP=heatCharging;
  secondiPre = secondi;
  
  pagina       = (bool)FlowSerialReadStringUntil(';').toInt();
  marcia         = FlowSerialReadStringUntil(';').charAt(0);
  vel        = FlowSerialReadStringUntil(';').toInt();
  rpm          = FlowSerialReadStringUntil(';').toInt();

	if (pagina == 0)
	{
    rpmMAX       = FlowSerialReadStringUntil(';').toInt();
    tempo        = FlowSerialReadStringUntil(';');
    migliorTempo = FlowSerialReadStringUntil(';');
    DRSdisp      = (bool)FlowSerialReadStringUntil(';').toInt();
    DRSaperto    = (bool)FlowSerialReadStringUntil(';').toInt();
    ultimoGiro   = FlowSerialReadStringUntil(';');
    delta        = FlowSerialReadStringUntil(';');
    //secondi      = FlowSerialReadStringUntil(';');
    secondi      =   tempo.charAt(4);
    ers          = FlowSerialReadStringUntil('\n');
	}
	else if (pagina==1)
	{
		pwrLevel      = FlowSerialReadStringUntil(';').toInt();
		recoveryLevel = FlowSerialReadStringUntil(';').toInt();
		heatCharging  = FlowSerialReadStringUntil('\n').toInt();
	}

  
  
  if(pagina!=paginaP and pagina==0)
  {
    setUp();
  }
  else if (pagina!=paginaP and pagina==1)
  {
    setUp2(); 
  }
    
}

String stampaDelivery(int n)
{
  switch(n)
  {
   case 0: return("Charging");
   case 1: return("Balanced low");
   case 2: return("Balanced high");
   case 3: return("Linear");
   case 4: return("Overtake");
   case 5: return("Top speed");
   case 6: return("Hotlap");
  }
}

String stampaMode(int n)
{
  switch(n)
  {
    case 0: return("Motor");
    case 1: return("Battery");
  }
}
