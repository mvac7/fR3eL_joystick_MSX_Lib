/* =============================================================================
Joystick MSX BIOS SDCC Library (fR3eL)
Version: 1.3 (14/01/2025)
Author: mvac7/303bcn
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and z80 assembler
Compiler: SDCC 4.4 or newer

Description:
 Open Source library with basic functions for reading joystick controllers 
 or cursor keys of MSX computers. 

History of versions:
- v1.3 (14/01/2025)	Update to SDCC (4.1.12) Z80 calling conventions
- v1.2 (11/03/2018)
- v1.1 (03/03/2017) 
- v1.0 (01/02/2016)
============================================================================= */


#include "../include/joystick_MSX.h"
#include "../include/msxBIOS.h"


/* =============================================================================
STICK

Description: 
		Returns the joystick status
		Similar to the MSX BASIC STICK instruction
 
Input:	[char] cursor/joystick device identifier 
		0=cursor keys 
		1=joystick A 
		2=joystick B
		
Output: [char] state
		0=inactive
		1=up
		2=up & right
		3=right
		4=down & right
		5=down
		6=down & left
		7=left
		8=up & left 
============================================================================= */
char STICK(char joy) __naked
{
joy;	//A
__asm
	jp BIOS_GTSTCK

;  push IX
;  call BIOS_GTSTCK
;  pop  IX
;  ret  
__endasm;
}


/* =============================================================================
STRIG

Description: 
	Returns selected trigger status. 
	Similar to the MSX BASIC STRIG instruction.
		 
Input:	[char] trigger identifier
		0 - space key
		1 - joystick A button 1   
		2 - joystick B button 1
		3 - joystick A button 2
		4 - joystick B button 2
				
Output:	[signed char] status
		0 = inactive
	   -1 = pressed 
============================================================================= */
signed char STRIG(char button) __naked
{
button;	//A
__asm
	call BIOS_GTTRIG	;A --> 0 not pressed
	or   A
	ret  Z		;unpressed
	ld   A,#-1	;pressed
	ret
__endasm;
}

