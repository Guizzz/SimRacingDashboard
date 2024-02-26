#include "posizioni.h"
#include "gestioneLed.h"
GFXcanvas1 canvas(128, 32); // 128x32 pixel canvas
//********************************
//Gestione Della pagina principale
//********************************
void aggiornaSchermo(Adafruit_ST7735 tft)
{
  if(marcia!=marciaPre)
  {
    tft.setTextSize(8);
    tft.setCursor(RigaM,ColM);
    tft.setTextColor(ST7735_BLACK);
    tft.print(marciaPre);

    tft.setCursor(RigaM,ColM);
    tft.setTextColor(ST7735_WHITE);
    tft.print(marcia);
  }

  if(ers!=ersPre)
  {
    //stampaERS(ers,ersPre,tft);

    tft.setTextSize(2);
    tft.setCursor(RigaErs,ColErs);
    tft.setTextColor(ST7735_BLACK);
    tft.print(ersPre);

    tft.setCursor(RigaErs,ColErs);
    tft.setTextColor(ST7735_WHITE);
    tft.print(ers);
    
  }
  
  if(vel!= velPre)
  {
    stampaVel(vel,velPre,tft);
  }
  
  if (DRSdisp==1)
  {
    tft.setTextSize(4);
    tft.setCursor(RigaDrs,ColDrs);
    
    if(DRSaperto==1)
    {
      tft.setTextColor(ST7735_YELLOW);
      tft.print("DRS"); 
    }
    else
    {
      tft.setTextColor(ST7735_WHITE);
      tft.print(F("DRS")); 
    }
  }
  else
  {
    tft.setTextSize(4);
    tft.setCursor(RigaDrs,ColDrs);
    tft.setTextColor(ST7735_BLACK);
    tft.print(F("DRS")); 
  }

  if(delta!=deltaPre)
  {
    tft.setTextSize(1);
    tft.setCursor(RigaDelta,ColDelta);
    tft.setTextColor(ST7735_BLACK);
    tft.println(deltaPre);
    
    if(delta.charAt(0)=='-')
    {
      tft.setTextColor(ST7735_GREEN);
    }
    else
    {
      tft.setTextColor(ST7735_RED);
    }
    tft.setCursor(RigaDelta,ColDelta);
    tft.println(delta);
  }

  if(migliorTempoPre!=migliorTempo)
  {
    tft.setTextSize(2);
    tft.setCursor(RigaBestLap,ColBestLap);
    tft.setTextColor(ST7735_BLACK);
    tft.println(migliorTempoPre);

    tft.setCursor(RigaBestLap,ColBestLap);
    tft.setTextColor(0xF81F);
    tft.println(migliorTempo);
  }

  if (ultimoGiro != ultimoGiroPre)
  {
	  count = 5;

	  tft.setTextSize(2);
	  tft.setCursor(RigaT, ColT);
	  tft.setTextColor(ST7735_BLACK);
	  tft.print(tempoPre);

	  tft.setCursor(RigaT, ColT);
	  tft.setTextColor(ST7735_BLUE);
	  tft.print(ultimoGiro);
	  
  }

  if(tempo!=tempoPre && count==0)
  {
		stampaTempo(tempoPre,tempo,tft, ST7735_WHITE);
  }
  else
  {
	  if (count > 0)
	  {
		  if (secondi != secondiPre && count > 0)
		  {
			  count--;
		  }

		  if (count == 0)
		  {
			  tft.setTextSize(2);
			  tft.setCursor(RigaT, ColT);
			  tft.setTextColor(ST7735_BLACK);
			  tft.print(ultimoGiro);

			  tft.setCursor(RigaT, ColT);
			  tft.setTextColor(ST7735_WHITE);
			  tft.print(tempo);
		  }
	  }
  }

  if (rpmPre != rpm)
  {
	  rpmStr = String(rpm);
	  rpmPStr = String(rpmPre);
	  int lunrpmStr = rpmStr.length();
	  int lunrpmPStr = rpmPStr.length();

	  if (lunrpmPStr > lunrpmStr)
	  {
		  rpmStr = rpmStr + " ";
		  lunrpmStr = lunrpmPStr;
	  }
	  else if (lunrpmPStr < lunrpmStr)
	  {
		  rpmPStr = rpmPStr + " ";
		  lunrpmPStr = lunrpmStr;
	  }

	  //tft.setCursor(RigaRpm,ColRpm);
	  tft.setTextSize(2);
	  int pos = RigaRpm;
	  for (int i = 0;i < lunrpmStr;i++)
	  {
      char Crpm=rpmStr.charAt(i);
      char CrpmPre=rpmPStr.charAt(i);
		  if (Crpm != CrpmPre)
		  {
			  tft.setCursor(pos, ColRpm);
			  tft.setTextColor(ST7735_BLACK);
			  tft.print(CrpmPre);

			  tft.setCursor(pos, ColRpm);
			  tft.setTextColor(ST7735_WHITE);
			  tft.print(Crpm);
		  }
		  pos += 12;
	  }
	}
}
//*********************************

void aggiornaSchermo2(Adafruit_ST7735 tft)
{

	if (marcia != marciaPre)
	{
		tft.setTextSize(5);
		tft.setCursor(RigaM, ColM-5);
		tft.setTextColor(ST7735_BLACK);
		tft.print(marciaPre);

		tft.setCursor(RigaM, ColM-5);
		tft.setTextColor(ST7735_WHITE);
		tft.print(marcia);
	}


	//velocita
	if (vel != velPre)
	{
		stampaVel(vel, velPre, tft);
	}
	
	if (pwrLevel != pwrLevelP)
	{
		tft.setTextSize(2);
		tft.setCursor(5, 45);
		tft.setTextColor(ST7735_BLACK);
		tft.print(stampaDelivery(pwrLevelP));

		tft.setCursor(5, 45);
		tft.setTextColor(ST7735_WHITE);
		tft.print(stampaDelivery(pwrLevel));
	}

	if (recoveryLevel != recoveryLevelP)
	{
		tft.setTextSize(2);
		tft.setCursor(5, 77);
		tft.setTextColor(ST7735_BLACK);
		tft.print(recoveryLevelP);

		tft.setCursor(5, 77);
		tft.setTextColor(ST7735_WHITE);
		tft.print(recoveryLevel);
	}

	if (heatCharging != heatChargingP)
	{
		tft.setTextSize(2);
		tft.setCursor(5, 128);
		tft.setTextColor(ST7735_BLACK);
		tft.print(stampaMode(heatChargingP));

		tft.setCursor(5, 128);
		tft.setTextColor(ST7735_WHITE);
		tft.print(stampaMode(heatCharging));
	}

}

            //att   //pre
void stampaVel(int v,int vP,Adafruit_ST7735 tft)
{
  String speed=String(v);
  String vel=String(vP);
  int velLung=vel.length();
  int speedLung=speed.length();
  if (velLung>speedLung)
  {
        speed=speed+" ";
        speedLung++;
  }
  else if (velLung<speedLung)
  {
      vel=vel+" ";
      velLung++;
  }

  tft.setTextSize(3);
  int pos=RigaVel;
  for(int i=0;i<velLung;i++)
  {
    char Cspeed=speed.charAt(i);
    char Cvel=vel.charAt(i);
    if(Cspeed!=Cvel)
    {
        tft.setCursor(pos,ColVel);
        tft.setTextColor(ST7735_BLACK);
        tft.print(Cvel);

        tft.setCursor(pos,ColVel);
        tft.setTextColor(ST7735_WHITE);
        tft.print(Cspeed);
    }
    pos+=18;
  }
}

void stampaERS(String ERS, String ERSp,Adafruit_ST7735 tft)
{
  //String ERS=String(p*100).substring(0,String(p*100).indexOf('.'));
  //String ERSp=String(P*100).substring(0,String(P*100).indexOf('.'));
  
  int ERSplung=ERSp.length();
  int ERSlung=ERS.length();
  if (ERSplung>ERSlung)
  {
      ERSlung++;
      ERS=ERS+" ";
  }
  else if (ERSplung<ERSlung)
  {
      ERSplung++;
      ERSp=ERSp+" ";
  }
  
  tft.setCursor(RigaErs,ColErs);
  tft.setTextSize(2);
  int pos=RigaErs;
  for(int i=0;i<ERSplung;i++)
  {
    char CErspre = ERSp.charAt(i);
    char CErs = ERS.charAt(i);
    if(CErs!= CErspre)
    {
        tft.setCursor(pos,ColErs);
        tft.setTextColor(ST7735_BLACK);
        tft.print(CErspre);

        tft.setCursor(pos,ColErs);
        tft.setTextColor(ST7735_WHITE);
        tft.print(CErs);
    }
    pos+=12;
  }
}

void stampaTempo(String lap,String tempo,Adafruit_ST7735 tft, int color)
{
  tft.setTextSize(2);
  tft.setCursor(RigaT,ColT);
  int pos=RigaT;
  char l = 9 ; //lap.length();
  for(int i=0; i < l ;i++)
  {
    char Clap=lap.charAt(i);
    char Ctempo=tempo.charAt(i);
    if((Clap!=Ctempo))
    {
        tft.setCursor(pos,ColT);
        tft.setTextColor(ST7735_BLACK);
        tft.print(Clap);

        tft.setCursor(pos,ColT);
        tft.setTextColor(color);
        tft.print(Ctempo);
    }
    pos+=12;
  }
}
