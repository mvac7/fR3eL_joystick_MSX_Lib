/* =============================================================================
   Test 1
   version: v1.1b (04/12/2020) 
   author: mvac7
   Description:
      Test SDCC JOYSTICK MSX ROM Library
      
   History of versions:
     v1.1b (04/12/2020) 
     v1.0b (01/02/2016)
============================================================================= */

#include "../include/newTypes.h"
#include "../include/memory.h"
#include "../include/textmode.h"
#include "../include/joystick.h"
#include "../include/msxsystemvars.h"
#include "../include/msxBIOS.h"



#define  HALT __asm halt __endasm   //wait for the next interrupt



void test();

void printTrig(signed char value);
void printDIR(char A);



// constants  ------------------------------------------------------------------


const char text01[] = "Test SDCC JOYSTICK MSX ROM Lib.";
const char text02[] = "v1 (01/02/2016)";



// Functions -------------------------------------------------------------------


//
void main(void)
{
  COLOR(CYAN,DARK_BLUE,MAGENTA);
  WIDTH(32);      
  SCREEN1();
      
  test();

  return;
}





// TEST ###############################################################
void test()
{
  char dir=0;
  signed char button=0;

      
  LOCATE(0,0);
  PRINT(text01);
  LOCATE(0,1);
  PRINT(text02);
  
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
    dir = STICK(0);
    LOCATE(14,8);
    PrintFNumber(dir,32,2);
    
    button=STRIG(0);
    LOCATE(14,9);
    printTrig(button);

      
    //------------------------- joy1
    dir = STICK(1);
    LOCATE(14,12);
    PrintFNumber(dir,32,2);
    
    button=STRIG(1);
    LOCATE(14,13);
    printTrig(button);
    
    button=STRIG(3);
    LOCATE(14,14);
    printTrig(button); 

    
    //------------------------- joy2
    dir = STICK(2);
    LOCATE(14,17);
    PrintFNumber(dir,32,2);    
       
    button=STRIG(2);
    LOCATE(14,18);
    printTrig(button);
    
    button=STRIG(4);
    LOCATE(14,19);
    printTrig(button); 

   
  }

}



void printTrig(signed char value)
{
  if(value<0) PRINT("-1");
  else PRINT(" 0");
}


