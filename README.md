# SDCC Joystick MSX ROM Functions Library

```
Author: mvac7 [mvac7303b@gmail.com]
Architecture: MSX
Format: C Object (SDCC .rel)
Programming language: C and Z80 assembler
```



## Introduction

This project is an Open Source library with basic functions for reading joystick controllers or cursor keys of MSX computers.

It uses the functions from the MSX BIOS, so it is designed to create applications in ROM format.
  
Use them for developing MSX applications using Small Device C Compiler (SDCC) compilator.

Includes two applications for test and learning purposes.

![TEST2](https://user-images.githubusercontent.com/5410950/101158049-63c0b780-362b-11eb-9f41-49ba2e8ceb13.png)


## Acknowledgments
  
Thanks for Info & help, to:

* Avelino Herrera > http://msx.atlantes.org/index_es.html
* Nerlaska > http://albertodehoyonebot.blogspot.com.es
* Fubu > http://www.gamerachan.org/fubu/
* Andrear > http://andrear.altervista.org/home/msxsoftware.php
* Sapphire/Z80ST > http://z80st.auic.es/
* MSX Assembly Page > http://map.grauw.nl/resources/msxbios.php
* Portar MSX Tech Doc > http://nocash.emubase.de/portar.htm
* MSX Resource Center > http://www.msx.org/
* Karoshi MSX Community (RIP 2007-2020)
* BlueMSX >> http://www.bluemsx.com/
* OpenMSX >> http://openmsx.sourceforge.net/
* Meisei  >> ?



## Requirements

* Small Device C Compiler (SDCC) v3.9 http://sdcc.sourceforge.net/
* Hex2bin v2.5 http://hex2bin.sourceforge.net/ 



## Functions

* char STICK(char joy) - Returns the joystick status.
* signed char STRIG(char joy) - Returns the trigger status.
 
 
## About mvac7 SDCC Libraries

I have developed a series of libraries for the community of MSX computer users. 
They are Open Source, so you can use them in your C developments with the SDCC 
compiler. 

You can improve them, cut them and transform them to other compilers, for your 
personal projects or you can share them with the community. 

The choice is yours.

### For develop MSX ROMs:

- SDCC C MSX 8/16K 8000h ROM startup file (CRT) [Go to github project](https://github.com/mvac7/SDCC_startup_MSX816kROM8000)
- SDCC C MSX 8/16K 4000h ROM startup file (CRT) [Go to github project](https://github.com/mvac7/SDCC_startup_MSX816kROM4000)
- SDCC C MSX 32K 4000h ROM startup file (CRT) [Go to github project](https://github.com/mvac7/SDCC_startup_MSX32kROM4000)
- SDCC Joystick MSX ROM Functions Library - Basic functions for reading Joystick controllers or Cursor Keys [Go to github project](https://github.com/mvac7/SDCC_JOYSTICK_MSXROM_Lib)
- SDCC Keyboard MSX ROM Functions Library [Go to github project](https://github.com/mvac7/SDCC_KEYBOARD_MSXROM_Lib)
- SDCC TEXTMODE MSX ROM Functions Library [Go to github project](https://github.com/mvac7/SDCC_TEXTMODE_MSXROM_Lib)
- SDCC VDP TMS9918A MSX ROM Functions Library [Go to github project](https://github.com/mvac7/SDCC_VDP_TMS9918A_MSXROM_Lib)
- SDCC SPRITES MSX ROM Functions Library [Go to github project](https://github.com/mvac7/SDCC_VDP_SPRITES_MSXROM_Lib)
- SDCC SPRITES 12 MSX ROM Functions Library [Go to github project](https://github.com/mvac7/SDCC_VDP_SPRITES_12_MSXROM_Lib)
- SDCC SPRITES Small MSX ROM Functions Library [Go to github project](https://github.com/mvac7/SDCC_VDP_SPRITES_S_MSXROM_Lib)

### For develop MSX-DOS applications:

- SDCC Keyboard MSX-DOS Functions Library [Go to github project](https://github.com/mvac7/SDCC_KEYBOARD_MSXDOS_Lib)
- SDCC Joystick MSX-DOS Functions Library [Go to github project](https://github.com/mvac7/SDCC_JOYSTICK_MSXDOS_Lib)
- SDCC TEXTMODE MSX-DOS Functions Library [Go to github project](https://github.com/mvac7/SDCC_TEXTMODE_MSXDOS_Lib)

### For develop MSX-DOS and ROMs applications:

- SDCC PSG AY-3-8910 Functions Library [Go to github project](https://github.com/mvac7/SDCC_AY38910_Lib)
- SDCC PSG AY-3-8910 playFX Functions Library [Go to github project](https://github.com/mvac7/SDCC_AY38910_playFX_Lib)
- SDCC VDP VPRINT Functions Library [Go to github project](https://github.com/mvac7/SDCC_VDP_VPRINT_Lib)
- SDCC VDP SPRITES Functions Library [Go to github project](https://github.com/mvac7/SDCC_VDP_SPRITES_Lib)
- SDCC MSX Z80 Memory Functions Library [Go to github project](https://github.com/mvac7/SDCC_MEMORY_MSX_Lib)
- SDCC String BASICs Functions Library [Go to github project](https://github.com/mvac7/SDCC_STRING_B_Lib)
- SDCC PT3 Player Library for MSX [Go to github project](https://github.com/mvac7/SDCC_PT3player)
- SDCC WYZ Player Library for MSX [Go to github project](https://github.com/mvac7/SDCC_WYZplayer)
- Z80 RLEWB for SDCC & Assembler [Go to github project](https://github.com/mvac7/Z80_RLEWB)
