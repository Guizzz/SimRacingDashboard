//Posizione Marcia
int RigaM= 10;
int ColM = 10;
//---------------

//Posizione Velocita
int RigaVel= 70;
int ColVel = 10;
//---------------

//Posizione rpm
int RigaRpm= 70;
int ColRpm = 35;
//---------------

//Ers
int RigaErs=70;
int ColErs=60;
//--------------

//DRS
int RigaDrs=30;
int ColDrs=85;
//--------------

//Posizione Tempo
int RigaT= 10;
int ColT = 120;
//---------------

//Posizione Miglio Tempo
int RigaBestLap= 10;
int ColBestLap = 145;
//---------------

//Posizione delta
int RigaDelta = 10;
int ColDelta = 137;
//---------------

//*********************************************************
//                       VARIABILI
//********************************************************

//-------Variabili per la gestione dello schermo
bool n = true;
//bool stampaU = false;
char marcia ='N';
String tempo;
String migliorTempo;
String ultimoGiro;

String delta="0";
int vel=0;
int rpm=0;
int rpmMAX=0;
String ers="";
bool DRSdisp = 0;
bool DRSaperto = 0;
bool pagina=0;
int recoveryLevel=0;//mgu-k recovery
int pwrLevel=0; //mgu-k delivery
int heatCharging=0; //mgu-h mode

//Variabili per salvare i valori precedenti
String ersPre;
int velPre;
int rpmPre;
char marciaPre;
String tempoPre;
String migliorTempoPre;
String ultimoGiroPre;
String deltaPre;
int paginaP;
int recoveryLevelP;
int pwrLevelP;
int heatChargingP;

String rpmStr;
String rpmPStr;
//------------------------------------
char secondi='0';
char secondiPre;
char count = 0;

//-------funzioni che utilizzo

void setUp();
void setUp2();
void aggiornaLed(int);
void aggiornamentoVaiabili();
void aggiornaSchermo(Adafruit_ST7735);

void stampaVel(int,int,Adafruit_ST7735);
void stampaTempo(String,String,Adafruit_ST7735,int);
void stampaERS(String, String,Adafruit_ST7735);

String stampaDelivery(int);
String stampaMode(int);
//---------------------------
