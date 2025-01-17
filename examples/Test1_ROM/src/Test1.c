/* =============================================================================
Test 1 for joystick_MSX SDCC Library (fR3eL Project)
Version: 1.2 (17/01/2025) 
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and Z80 assembler
Compiler: SDCC 4.4 or newer 

Description:
  Test SDCC JOYSTICK MSX ROM Library
  
History of versions:
- v1.2 (17/01/2025) 
- v1.1 (04/12/2023)
- v1.0 (01/02/2016)
============================================================================= */

#include "../include/newTypes.h"
#include "../include/msxSystemVariables.h"
#include "../include/msxBIOS.h"

#include "../include/memory_Z80.h"
#include "../include/textmode_MSX.h"
#include "../include/joystick_MSX.h"


#define  HALT __asm halt __endasm   //wait for the next interrupt



void test(void);

void printTrig(signed char state);
void printDIR(char A);



// constants  ------------------------------------------------------------------


const char txtAppAbout[] = "Test 1 joystick_MSX Lib";



// Functions -------------------------------------------------------------------


//
void main(void)
{
	COLOR(CYAN,DARK_BLUE,LIGHT_BLUE);
	WIDTH(32);      
	SCREEN1();
	  
	test();

	return;
}





// TEST ###############################################################
void test(void)
{
	char dir;
	signed char button;

	  
	LOCATE(0,0);
	PRINT(txtAppAbout);

	LOCATE(0,5);
	PRINT(">Test STICK() & STRIG()");

	LOCATE(3,7);
	PRINT("*Cursor Keys");
	LOCATE(4,8);
	PRINT("STICK(0)= ");
	LOCATE(4,9);
	PRINT("STRIG(0)=");  

	LOCATE(3,11);
	PRINT("*Joystick A");
	LOCATE(4,12);
	PRINT("STICK(1)= ");
	LOCATE(4,13);
	PRINT("STRIG(1)=");
	LOCATE(4,14);
	PRINT("STRIG(3)=");

	LOCATE(3,16);
	PRINT("*Joystick B");
	LOCATE(4,17);
	PRINT("STICK(2)=");
	LOCATE(4,18);
	PRINT("STRIG(2)=");
	LOCATE(4,19);
	PRINT("STRIG(4)=");


	while(1)
	{
		HALT;

		//------------------------- cursor keys
		dir = STICK(CURSORKEYS);
		LOCATE(14,8);
		PrintFNumber(dir,32,2);

		button=STRIG(KEYBOARD_BUTTON);
		LOCATE(14,9);
		printTrig(button);

		  
		//------------------------- joy1
		dir = STICK(JOYSTICKA);
		LOCATE(14,12);
		PrintFNumber(dir,32,2);

		button=STRIG(JOYSTICKA_BUTTONA);
		LOCATE(14,13);
		printTrig(button);

		button=STRIG(JOYSTICKA_BUTTONB);
		LOCATE(14,14);
		printTrig(button); 


		//------------------------- joy2
		dir = STICK(JOYSTICKB);
		LOCATE(14,17);
		PrintFNumber(dir,32,2);    
		   
		button=STRIG(JOYSTICKB_BUTTONA);
		LOCATE(14,18);
		printTrig(button);

		button=STRIG(JOYSTICKB_BUTTONB);
		LOCATE(14,19);
		printTrig(button); 

	}

}



void printTrig(signed char state)
{
	if(state==BUTTON_PRESSED) PRINT("-1");
	else PRINT(" 0");
}


