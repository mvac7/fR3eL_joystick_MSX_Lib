/* =============================================================================
Test 2 for joystick_MSX SDCC Library (fR3eL Project)
Version: v1.1 (15/01/2025)
Architecture: MSX
Format: MSX-DOS .COM
Programming language: C and Z80 assembler
Compiler: SDCC 4.4 or newer 
  
History of versions:
- v1.1  (15/01/2025) update to SDCC (4.1.12) Z80 calling conventions
- v1.0b (10/02/2023) For v2 of the library and log format output 
- v0.9b (02/12/2020)    
============================================================================= */

#include "../include/newTypes.h"
#include "../include/msxSystemVariables.h"
#include "../include/msxBIOS.h"
#include "../include/msxDOS.h"

#include "../include/memory_Z80.h"
#include "../include/textmode_MSX.h"
#include "../include/keyboard_MSX.h"
#include "../include/joystick_MSX.h"


// -----------------------------------------------------------------------------
#define  HALT __asm halt __endasm   //wait for the next interrupt



// -----------------------------------------------------------------------------
void test(void);

void printTrig(char Ntrigger);
void printDIR(char Njoy, char state);




// ----------------------------------------------------------------------------- constants
const char text01[] = "Test2 joystick_MSX Lib";
const char text02[] = "Test STICK and STRIG";
const char text03[] = "Hold down ESC key to return to DOS";
const char text_cursor[] = "Keyboard   - ";
const char text_joyA[] = "Joystick A - ";
const char text_joyB[] = "Joystick B - ";
const char text_space[] = "[Spacebar]";
const char text_butA[] = "[Button 1]";
const char text_butB[] = "[Button 2]";


// ----------------------------------------------------------------------------- Functions

//
void main(void)
{
  
  CLS();
    
  test();  

  
//EXIT MSXDOS ------------------------------------------------------------------
 
  KillBuffer();
    

//--------------------------------------------------------------------- end EXIT    
}





// TEST ###############################################################
void test(void)
{
  char isExit = 0;
  
  char dir=0;
  char dirCURSOR=0;
  char dirJOY1=0;
  char dirJOY2=0;
  
  signed char button=0;
  boolean spaceBar_pressed=false;
  boolean but1JOY1_pressed=false;
  boolean but2JOY1_pressed=false;
  boolean but1JOY2_pressed=false;
  boolean but2JOY2_pressed=false;

      
  PrintLN(text01);
  PrintLN(text02);
  PrintLN(text03);
  
   

  while(isExit<60)
  {
    HALT;
    
    if (!(GetKeyMatrix(7)&Bit2)) isExit++;
    else isExit=0;
    
    //------------------------- cursor keys
    dir = STICK(CURSORKEYS);
    if(dir!=JOYSTICK_INACTIVE){
        if(dir!=dirCURSOR)
        {
            printDIR(CURSORKEYS, dir);
            dirCURSOR=dir;
        }
    }else dirCURSOR=JOYSTICK_INACTIVE;
    
   
    button=STRIG(SPACEBAR_BUTTON);
    if(button==BUTTON_PRESSED)
    {
        if(!spaceBar_pressed){
            printTrig(SPACEBAR_BUTTON);
            spaceBar_pressed = true;
        }    
    }else spaceBar_pressed = false; 
    
      
    //------------------------- joy1
    dir = STICK(JOYSTICKA);
    if(dir!=JOYSTICK_INACTIVE){
        if(dir!=dirJOY1)
        {
            printDIR(JOYSTICKA, dir);
            dirJOY1=dir;
        }
    }else dirJOY1=JOYSTICK_INACTIVE;
   
    button=STRIG(JOYSTICKA_BUTTONA);
    if(button==BUTTON_PRESSED)
    {
        if(!but1JOY1_pressed){
            printTrig(JOYSTICKA_BUTTONA);
            but1JOY1_pressed = true;
        }    
    }else but1JOY1_pressed = false;
    
    button=STRIG(JOYSTICKA_BUTTONB);
    if(button==BUTTON_PRESSED)
    {
        if(!but2JOY1_pressed){
            printTrig(JOYSTICKA_BUTTONB);
            but2JOY1_pressed = true;
        }    
    }else but2JOY1_pressed = false;
    

    
    //------------------------- joy2
    dir = STICK(JOYSTICKB);
    if(dir!=JOYSTICK_INACTIVE){
        if(dir!=dirJOY2)
        {
            printDIR(JOYSTICKB, dir);
            dirJOY2=dir;
        }
    }else dirJOY2=JOYSTICK_INACTIVE;
    
    button=STRIG(JOYSTICKB_BUTTONA);
    if(button==BUTTON_PRESSED)
    {
        if(!but1JOY2_pressed){
            printTrig(JOYSTICKB_BUTTONA);
            but1JOY2_pressed = true;
        }    
    }else but1JOY2_pressed = false;
    
    button=STRIG(JOYSTICKB_BUTTONB);
    if(button==BUTTON_PRESSED)
    {
        if(!but2JOY2_pressed){
            printTrig(JOYSTICKB_BUTTONB);
            but2JOY2_pressed = true;
        }    
    }else but2JOY2_pressed = false;
   
   
  }
  
  PRINT("End Test");

}




void printTrig(char Ntrigger)
{
  switch (Ntrigger) 
  {
    case SPACEBAR_BUTTON:
		PRINT(text_cursor);
		PRINT(text_space);  
		break;
      
    case JOYSTICKA_BUTTONA:
		PRINT(text_joyA);
		PRINT(text_butA);  
		break;
    
    case JOYSTICKA_BUTTONB:
		PRINT(text_joyA);
		PRINT(text_butB);  
		break;

    case JOYSTICKB_BUTTONA:
		PRINT(text_joyB);
		PRINT(text_butA);  
		break;
    
    case JOYSTICKB_BUTTONB:
		PRINT(text_joyB);
		PRINT(text_butB);  
		break;
  }
  PRINT(" pressed\n");
}



void printDIR(char Njoy, char state)
{
  if (Njoy==1) PRINT(text_joyA);
  else if (Njoy==2) PRINT(text_joyA);
  else PRINT(text_cursor); 


  switch (state) 
  {
    /*case JOYSTICK_INACTIVE:
      PRINT("            "); 
      break;*/
    case JOYSTICK_UP:
      PRINT("[Up]");  
      break;
    case JOYSTICK_UP_RIGHT:
      PRINT("[Up] & [Right]");  
      break;
    case JOYSTICK_RIGHT:
      PRINT("[Right]");  
      break;
    case JOYSTICK_DOWN_RIGHT:
      PRINT("[Down] & [Right]");  
      break;
    case JOYSTICK_DOWN:
      PRINT("[Down]");  
      break;
    case JOYSTICK_DOWN_LEFT:
      PRINT("[Down] & [Left]");  
      break;
    case JOYSTICK_LEFT:
      PRINT("[Left]");  
      break;
    case JOYSTICK_UP_LEFT:
      PRINT("[Up] & [Left]");  
      break;
  }
  
  PRINT("\n");
}

