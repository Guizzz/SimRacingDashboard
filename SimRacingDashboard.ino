// J revision sketch
#define VERSION 'j'
//#define INCLUDE_TACHOMETER  
// ----------------------------------------------------- HW SETTINGS, PLEASE REVIEW ALL -------------------------------------------
#define DEVICE_NAME "SimHub Dash" //{"Group":"General","Name":"DEVICE_NAME","Title":"Device name,\r\n make sure to use a unique name when using multiple arduinos","DefaultValue":"SimHub Dash","Type":"string","Template":"#define DEVICE_NAME \"{0}\""}
#define ENABLE_MICRO_GAMEPAD 0           //{"Group":"GAMEPAD","Name":"ENABLE_MICRO_GAMEPAD","Title":"Enable arduino micro gamepad output for all the activated buttons/encoders","DefaultValue":"0","Type":"bool"}
#define MICRO_GAMEPAD_ENCODERPRESSTIME 50 //{"Name":"MICRO_GAMEPAD_ENCODERPRESSTIME","Title":"Define how long (in milliseconds) the encoder related button will be hold after an encoder movement","DefaultValue":"50","Type":"int","Condition":"ENABLE_MICRO_GAMEPAD>0","Max":100}
#define TM1638_ENABLEDMODULES 0 //{"Group":"TM1638 7 Segments Modules","Name":"TM1638_ENABLEDMODULES","Title":"TM1638 modules connected","DefaultValue":"0","Type":"int","Max":6}
#define TM1637_ENABLEDMODULES 0 //{"Group":"TM1637 7 Segment Modules","Name":"TM1637_ENABLEDMODULES","Title":"TM1637 modules connected","DefaultValue":"0","Type":"int","Max":8}
#define MAX7221_ENABLEDMODULES 0 //{"Group":"MAX7221 7 Segments Modules","Name":"MAX7221_ENABLEDMODULES","Title":"MAX7219 / MAX7221 7 Segment modules connected \r\nMultiple modules can be cascaded connected module output to next module input","DefaultValue":"0","Type":"int","Max":8}
#define MAX7221_MATRIX_ENABLED 0 //{"Group":"MAX7221 Led Matrix","Name":"MAX7221_MATRIX_ENABLED","Title":"MAX7221 led matrix enabled ","DefaultValue":"0","Type":"bool"}
#define ENABLE_ADA_HT16K33_SingleColorMatrix 0     //{"Group":"HT16K33 Single Color Matrix","Name":"ENABLE_ADA_HT16K33_SingleColorMatrix","Title":"Adafruit HT16K33 single color matrix display enabled","DefaultValue":"0","Type":"bool","Pins":"nano:18,HT16K33 SC MATRIX DAT;19,HT16K33 SC MATRIX CLK|uno:18,HT16K33 SC MATRIX DAT;19,HT16K33 SC MATRIX CLK"}
#define WS2812B_RGBLEDCOUNT 0 //{"Group":"WS2812B RGB Leds","Name":"WS2812B_RGBLEDCOUNT","Title":"WS2812B RGB leds count","DefaultValue":"0","Type":"int","Max":150}
#define PL9823_RGBLEDCOUNT 0 //{"Group":"PL9823 RGB Leds","Name":"PL9823_RGBLEDCOUNT","Title":"PL9823 RGB leds count","DefaultValue":"0","Type":"int","Max":150}
#define WS2801_RGBLEDCOUNT 0 //{"Group":"WS2801 RGB Leds","Name":"WS2801_RGBLEDCOUNT","Title":"WS2801 RGB leds count","DefaultValue":"0","Type":"int","Max":150}
#define WS2812B_MATRIX_ENABLED 0 //{"Group":"WS2812B Matrix","Name":"WS2812B_MATRIX_ENABLED","Title":"DEPRECATED, DO NOT USE","DefaultValue":"0","Type":"bool"}
#define I2CLCD_enabled 0   //{"Group":"20x4 I2C LCD","Name":"I2CLCD_enabled","Title":"I2C LCD (2004) enabled\r\nUno, Ethernet, Nano : A4(SDA), A5(SCL)\r\nMega2560 : 20 (SDA), 21 (SCL)\r\nLeonardo : 2 (SDA), 3 (SCL)\r\nDue : 20 (SDA), 21 (SCL), SDA1, SCL1","DefaultValue":"0","Type":"bool","Pins":"nano:18,I2C LCD SDA;19,I2C LCD SCL|uno:18,I2C LCD SDA;19,I2C LCD SCL"}
#define ENABLE_ADA_HT16K33_7SEGMENTS 0 //{"Group":"HT16K33 7 Segments Module","Name":"ENABLE_ADA_HT16K33_7SEGMENTS","Title":"Adafruit HT16K33 7 segments display enabled","DefaultValue":"0","Type":"bool","Pins":"nano:18,HT16K33 7SEG DAT;19,HT16K33 7SEG CLK|uno:18,HT16K33 7SEG DAT;19,HT16K33 7SEG CLK"}
#define ENABLE_ADA_HT16K33_BiColorMatrix 0     //{"Group":"HT16K33 Bi Color Matrix","Name":"ENABLE_ADA_HT16K33_BiColorMatrix","Title":"Adafruit HT16K33 Bicolor matrix display enabled","DefaultValue":"0","Type":"bool","Pins":"nano:18,HT16K33 MATRIX DAT;19,HT16K33 MATRIX CLK|uno:18,HT16K33 MATRIX DAT;19,HT16K33 MATRIX CLK"}
#define ENABLED_BUTTONS_COUNT 0 //{"Group":"Additional Buttons","Name":"ENABLED_BUTTONS_COUNT","Title":"Additional buttons (directly connected to the arduino, 12 max) buttons count","DefaultValue":"0","Type":"int","Max":12}
#define ENABLED_ENCODERS_COUNT 0     //{"Group":"Rotary Encoders","Name":"ENABLED_ENCODERS_COUNT","Title":"Rotary encoders enabled","DefaultValue":"0","Type":"int","Max":8}
#define ENABLED_BUTTONMATRIX 0 //{"Group":"Button matrix","Name":"ENABLED_BUTTONMATRIX","Title":"Button matrix enabled","DefaultValue":"0","Type":"bool"}
#define BMATRIX_COLS 3         //{"Name":"BMATRIX_COLS","Title":"Columns","DefaultValue":"3","Type":"int","Condition":"ENABLED_BUTTONMATRIX>0","Min":2,"Max":8}
#define BMATRIX_ROWS 3         //{"Name":"BMATRIX_ROWS","Title":"Rows","DefaultValue":"3","Type":"int","Condition":"ENABLED_BUTTONMATRIX>0","Min":2,"Max":8}
#define ADAMOTORS_SHIELDSCOUNT 0 //{"Group":"SHAKEIT Adafruit Motorshield V2","Name":"ADAMOTORS_SHIELDSCOUNT","Title":"Number of adadruit shields connected (up to 3)","DefaultValue":"0","Type":"int","Max":3}
#define MOTOMONSTER_ENABLED 0          //{"Group":"SHAKEIT MotoMonster Board","Name":"MOTOMONSTER_ENABLED","Title":"Moto Monster board enabled","DefaultValue":"0","Type":"bool"}
#define DKMOTOR_SHIELDSCOUNT 0       //{"Group":"SHAKEIT DK Motor Shield","Name":"DKMOTOR_SHIELDSCOUNT","Title":"DK shield enabled","DefaultValue":"0","Type":"bool"}
#define L98NMOTORS_ENABLED 0 //{"Group":"SHAKEIT L298N Motors Board","Name":"L98NMOTORS_ENABLED","Title":"L298N motor board enabled","DefaultValue":"0","Type":"bool"}
#define SHAKEITPWM_ENABLED_MOTORS 0 //{"Group":"SHAKEIT PWM Outputs","Name":"SHAKEITPWM_ENABLED_MOTORS","Title":"ShakeIT direct PWM outputs enabled, for fans, TIP120 or any PWM driven custom boards","DefaultValue":"0","Type":"int","Max":4}
#define ENABLED_OLEDLCD 0 //{"Group":"Oled GLCD","Name":"ENABLED_OLEDLCD","Title":"OLED LCD enabled","DefaultValue":"0","Type":"bool","Pins":"nano:18,OLED LCD SDA;19,OLED LCD SCK|uno:18,OLED LCD SDA;19,OLED LCD SCK|micro:2,OLED LCD SDA;3,OLED LCD SCK"}
#define ENABLED_NOKIALCD 0 //{"Group":"Nokia GLCD","Name":"ENABLED_NOKIALCD","Title":"Nokia LCD enabled","DefaultValue":"0","Type":"bool","Max":2}
#define ENABLE_74HC595_GEAR_DISPLAY 0 

#include <avr/pgmspace.h>
#include <EEPROM.h>
#include <SPI.h>
#include "FlowSerialRead.h"
#include "SHCustomProtocol.h"
SHCustomProtocol shCustomProtocol;
#include "SHCommands.h"

char loop_opt;

void setup()
{
	FlowSerialBegin(19200);
	setUpLed();
	tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
	tft.setTextWrap(false);
	tft.fillScreen(ST7735_BLACK);
 
  tempo.reserve(9);
  tempo="00:00.0--";
  
  migliorTempo.reserve(9);
  migliorTempo="00:00";
  
  ultimoGiro.reserve(9);
  ultimoGiro="00:00.0--";
}

void loop() 
{
	// Wait for data
	if (FlowSerialAvailable() > 0) 
	{
		if (FlowSerialTimedRead() == MESSAGE_HEADER)
		{
			// Read command
			loop_opt = FlowSerialTimedRead();

			if (loop_opt == '1') Command_Hello();
			else if (loop_opt == '8') Command_SetBaudrate();
			else if (loop_opt == 'N') Command_DeviceName();
			else if (loop_opt == 'J') Command_ButtonsCount();
			else if (loop_opt == '2') Command_TM1638Count();
			else if (loop_opt == 'B') Command_SimpleModulesCount();
			else if (loop_opt == 'A') Command_Acq();
			else if (loop_opt == '0') Command_Features();
			else if (loop_opt == '4') Command_RGBLEDSCount();
			else if (loop_opt == '6') Command_RGBLEDSData();
			else if (loop_opt == 'P') Command_CustomProtocolData();
			else if (loop_opt == 'X')
			{
				String xaction = FlowSerialReadStringUntil(' ', '\n');
				if (xaction == F("list")) Command_ExpandedCommandsList();
				else if (xaction == F("mcutype")) Command_MCUType();

			}
		}
	}
}
