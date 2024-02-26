#define MESSAGE_HEADER 0x03

void Command_Hello() 
{
	FlowSerialTimedRead();
	delay(10);
	FlowSerialPrint(VERSION);
	FlowSerialFlush();
}

void Command_SetBaudrate()
{
	SetBaudrate();
}

void Command_ButtonsCount() 
{
	FlowSerialWrite((byte)(ENABLED_BUTTONS_COUNT + ENABLED_BUTTONMATRIX * (BMATRIX_COLS * BMATRIX_ROWS)));
	FlowSerialFlush();
}

void Command_TM1638Count() 
{
	FlowSerialWrite((byte)(TM1638_ENABLEDMODULES));
	FlowSerialFlush();
}

void Command_SimpleModulesCount()
{
	FlowSerialWrite((byte)(MAX7221_ENABLEDMODULES + TM1637_ENABLEDMODULES + ENABLE_ADA_HT16K33_7SEGMENTS));
	FlowSerialFlush();
}

void Command_Acq() 
{
	FlowSerialWrite(0x03);
	FlowSerialFlush();
}

void Command_DeviceName() 
{
	FlowSerialPrint(DEVICE_NAME);
	FlowSerialPrint("\n");
	FlowSerialFlush();
}

void Command_MCUType() 
{
	FlowSerialPrint(SIGNATURE_0);
	FlowSerialPrint(SIGNATURE_1);
	FlowSerialPrint(SIGNATURE_2);
	FlowSerialFlush();
}

void Command_ExpandedCommandsList()
{
	FlowSerialPrintLn("mcutype");
	FlowSerialPrintLn();
	FlowSerialFlush();
}


void Command_Features() 
{
	delay(10);

	// Matrix
	if (MAX7221_MATRIX_ENABLED == 1 || ENABLE_ADA_HT16K33_BiColorMatrix == 1 || ENABLE_ADA_HT16K33_SingleColorMatrix == 1)
	{
		FlowSerialPrint("M");
	}

	if (ENABLED_NOKIALCD > 0 || ENABLED_OLEDLCD > 0)
	{
		FlowSerialPrint("K");
	}

	// Gear
	FlowSerialPrint("G");
	// Name
	FlowSerialPrint("N");
	// Additional buttons
	FlowSerialPrint("J");
	// Custom Protocol Support
	FlowSerialPrint("P");
	// Xpanded support
	FlowSerialPrint("X");

	// RGB MATRIX
	if (WS2812B_MATRIX_ENABLED > 0) 
	{
		FlowSerialPrint("R");
	}

	FlowSerialPrint("\n");
	FlowSerialFlush();
}


void Command_RGBLEDSCount() 
{
	FlowSerialWrite((byte)(WS2812B_RGBLEDCOUNT + PL9823_RGBLEDCOUNT + WS2801_RGBLEDCOUNT));
	FlowSerialFlush();
}

void Command_RGBLEDSData()
{
	// Acq !
	FlowSerialWrite(0x15);
}

void Command_RGBMatrixData() 
{
	// Acq !
	FlowSerialWrite(0x15);
}


void Command_CustomProtocolData() 
{
	shCustomProtocol.read();
	FlowSerialWrite(0x15);
}
