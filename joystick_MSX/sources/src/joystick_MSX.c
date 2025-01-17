/* =============================================================================
Joystick MSX SDCC Library (fR3eL)
Version: 2.1 (14/1/2025)
Author: mvac7/303bcn
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and z80 assembler
Compiler: SDCC 4.4 or newer

Description:
 Open Source library with basic functions for reading joystick controllers 
 or cursor keys of MSX computers. 

History of versions:
- v2.1 (14/01/2025) Update to SDCC (4.1.12) Z80 calling conventions
- v2.0 (12/02/2023)	Programmed by directly reading the joystick (PSG) 
					and keyboard (PPI) ports.
- v1.0 (02/12/2020)	first versión. Uses the BIOS routines via interslot calls.       
============================================================================= */

#include "../include/joystick_MSX.h"

//#include "../include/msxSystemVars.h"




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

	or   A
	jr   Z,GetCursorKeys
		 
	dec  A             ;Joy port (Joy A=0 or Joy B>0)
	call READjoyvalue  ;get value in A
	and  #0b00001111

	ld   HL,#JOYVALUES
  
RETURNdirection:  
	ld   D,#0
	ld   E,A
	add  HL,DE
	ld   A,(HL)

	ret

;translates the returned keystrokes to standardized direction values
JOYVALUES:
	.DB 0,5,1,0,3,4,2,3
	.DB 7,6,8,7,0,5,1,0


GetCursorKeys:
	call READcursorKEYS
  	SRL  A
	SRL  A
	SRL  A
	SRL  A
	
	ld   HL,#CURSOR_VALUES
	jr   RETURNdirection 

;translates the returned keystrokes to standardized direction values
CURSOR_VALUES:
	.DB 0,3,5,4,1,2,0,3
	.DB 7,0,6,5,8,1,7,0 


;-------------------------------------------------------------------------------  
; input: A <-- Joy port (Joy A=0 or Joy B= >0)
; output: A --> PSG reg14 inverted value       
READjoyvalue:
	ex   AF,AF
	di  
	ld   A,#15      ;read PSG Register 15  
	out  (0xA0),A
	in   A,(0xA2)
	ei
	ex   AF,AF

	or   A
	jr   NZ,SETJOYB

SETJOYA:  
	ex   AF,AF
	res  6,A
	jr   SETREG15
  
SETJOYB:  
	ex   AF,AF
	set  6,A

          
;  Reg/Bit  7     6     5     4     3     2     1     0
;  15       Kana  Joy   Pulse Pulse 1     1     1     1
;           LED   Sel   2     1 
SETREG15:
	di  
	out  (0xA1),A		;write PSG register 15 (select joystick port)


;  Reg/Bit  7     6     5     4     3     2     1     0
;  14       Cas   Kbd   JOY   JOY   JOY   JOY   JOY   JOY
;           Input Mode  Trg.2 Trg.1 Right Left  Back  Fwd  
	ld   A,#14       ;PSG register 14
	out  (0xA0),A
	in   A,(0xA2)   ;read value
	ei
  
	ret


;-------------------------------------------------------------------------------
; get keyboard matrix row 8 
; output: A --> value
READcursorKEYS:
	ld    B,#8  ;Keyboard row 8
	di
	in    A,(0xAA)   ;PPI-register C
	and   #0xf0
	or    B
	out   (#0xAA),A

	in    A,(0xA9)  ;Keyboard matrix row input register (PPI-register B)
	ei
  
	ret  
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
signed char STRIG(char triggerN) __naked
{
triggerN;	//A
__asm

	ld   B,A
	or   A
	jr   Z,GetSpaceKey

	xor  A               ;JOYA

	bit  0,B
	jr   NZ,GetJoyValue  ;if odd (1 or 3) then is joystick 1

	inc  A               ;JOYB
  

GetJoyValue:        
	call READjoyvalue   ;get joystick state
	ld   L,A

	ld   A,B
	cp   #3
	jr   NC,JOYbutton2

;JOYbutton1  
	bit  4,L
	jr   returnTrigValue
  
JOYbutton2:
	bit  5,L
  
returnTrigValue:
	jr   NZ,TRIGinactive

	ld   A,#-1
	ret
  
TRIGinactive:  
	xor  A
	ret

GetSpaceKey:
	call READcursorKEYS
	bit  0,A
	jr   returnTrigValue
  
__endasm;
}

