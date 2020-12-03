/* =============================================================================
   Test
   v1.0 (01/02/2016)
   Description:
      Test SDCC JOYSTICK MSX ROM Library
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

//void printDIR(char A);



// constants  ------------------------------------------------------------------


const char text01[] = "Test SDCC JOYSTICK MSX ROM Lib.";
const char text02[] = "v1 (01/02/2016)";



// Functions -------------------------------------------------------------------


//
void main(void)
{
    
  test();

  

//EXIT MSXDOS
/*  screen(0);
    
__asm
 	ld b,4(ix)
	ld c,#0x62
	call 5 
__endasm;*/
//end EXIT

  return;
}





// TEST ###############################################################
void test()
{
  char A=0;
  
  COLOR(LIGHT_GREEN,DARK_GREEN,DARK_GREEN);      
  SCREEN0();
  WIDTH(40);
  
  LOCATE(0,0);
  PRINT(text01);
  LOCATE(0,1);
  PRINT(text02);
  
  LOCATE(0,5);
  PRINT(">Test STICK() & STRIG()");
 
  
  //CLS();
  while(1)
  {
    HALT;
    
    A = STICK(0);
 
    LOCATE(3,7);
    PRINT("*Cursor");
    LOCATE(4,8);
    PRINT("STICK(0)= ");
    PrintNumber(A);    
    LOCATE(4,9);
    PRINT("STRIG(0)=");
    printTrig(STRIG(0));  
    
    A = STICK(1);
    LOCATE(3,11);
    PRINT("*Joystick A");  // \n
    LOCATE(4,12);
    PRINT("STICK(1)= ");
    PrintNumber(A);
    LOCATE(4,13);
    PRINT("STRIG(1)=");
    printTrig(STRIG(1));
    
    LOCATE(4,14);
    PRINT("STRIG(3)=");
    printTrig(STRIG(3));
    
    A = STICK(2);
    LOCATE(3,16);
    PRINT("*Joystick B");
    LOCATE(4,17);
    PRINT("STICK(2)= ");
    PrintNumber(A);
    LOCATE(4,18);
    PRINT("STRIG(2)=");
    printTrig(STRIG(2));
    LOCATE(4,19);
    PRINT("STRIG(4)=");
    printTrig(STRIG(4));
   
  }
  

}



void printTrig(signed char value)
{
  if(value<0) PRINT("-1");
  else PRINT(" 0");
}



/*void printDIR(char A)
{
  switch (A) 
  {
    case 0:
      PRINT("            "); 
      break;
    case 1:
      PRINT("Up          ");  
      break;
    case 2:
      PRINT("Up & Right  ");  
      break;
    case 3:
      PRINT("Right       ");  
      break;
    case 4:
      PRINT("Down & Right");  
      break;
    case 5:
      PRINT("Down        ");  
      break;
    case 6:
      PRINT("Down & Left ");  
      break;
    case 7:
      PRINT("Left        ");  
      break;
    case 8:
      PRINT("Up & Left   ");  
      break;
  }
  return;
}*/

