# Joystick MSX ROM fR3E_SX SDCC Library

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

* char **STICK**(char joy) - Returns the joystick status.
* signed char **STRIG**(char joy) - Returns the trigger status.
 
 
# About fR3E_SX SDCC Libraries

I have developed a series of libraries for the community of MSX computer users. 
They are Open Source, so you can use them in your C developments with the SDCC compiler.

They are published as independent objects instead of a library, so that it is more versatile and you can include those that fit the needs of your project. 

Most of the libraries use the BIOS of the MSX system, with what is achieved lightness and compatibility but not speed. 
It will not be a problem, for most of the cases where the use is controlled, but if you need to perform tasks that work with large volumes of data (such as dynamic graphics), you may need to program more optimal functions and adapted to your needs.

You can improve them, cut what you need or transform them to other compilers, for your personal projects or you can share them with the community. 

The choice is yours.

**Note:** The main reason for developing this project is learning. 
You can use it freely, but keep in mind that there are better and more complete libraries, such as [Fusion-C](https://github.com/ericb59/Fusion-C-v1.2) by [Eric Boez](https://github.com/ericb59). 

They are divided into three groups, since in some cases they have been developed to work in specific execution environments: ROMs or MSX-DOS.

## For develop MSX ROMs:

- **MSX 8/16K 8000h ROM startup file (CRT)** [(gitHub project)](https://github.com/mvac7/SDCC_startup_MSX816kROM8000)
- **MSX 8/16K 4000h ROM startup file (CRT)** [(gitHub project)](https://github.com/mvac7/SDCC_startup_MSX816kROM4000)
- **MSX 32K 4000h ROM startup file (CRT)** [(gitHub project)](https://github.com/mvac7/SDCC_startup_MSX32kROM4000)
- **Keyboard MSX ROM Library** - _Functions for reading the keyboard of MSX computers._ [(gitHub project)](https://github.com/mvac7/SDCC_KEYBOARD_MSXROM_Lib)
- **Joystick MSX ROM Library** - _Basic functions for reading Joystick controllers or Cursor Keys._ [(gitHub project)](https://github.com/mvac7/SDCC_JOYSTICK_MSXROM_Lib)
- **Textmode MSX ROM Library** - _Functions for starting and printing in text modes._ [(gitHub project)](https://github.com/mvac7/SDCC_TEXTMODE_MSXROM_Lib)
- **VDP TMS9918A MSX ROM Library** - _Basic functions to work with the TMS9918A video processor using the MSX BIOS._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_TMS9918A_MSXROM_Lib)
- **SPRITES MSX ROM Library** - _Functions to facilitate the use of Sprites of the TMS9918A._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_MSXROM_Lib)
- **SPRITES 12 MSX ROM Library** - _Basic functions for managing Sprites with facilities to work with G3 mode (Screen 4)._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_12_MSXROM_Lib)
- **SPRITES Small MSX ROM Library** - _Functions for the initialization of Sprites and the PUTSPRITE function._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_S_MSXROM_Lib)


## For develop MSX-DOS applications (.COM):

- **Keyboard MSX-DOS Library** - _Functions for reading the keyboard of MSX computers._ [(gitHub project)](https://github.com/mvac7/SDCC_KEYBOARD_MSXDOS_Lib)
- **Joystick MSX-DOS Library** - _Basic functions for reading Joystick controllers or Cursor Keys._ [(gitHub project)](https://github.com/mvac7/SDCC_JOYSTICK_MSXDOS_Lib)
- **Textmode MSX-DOS Library** - _Functions for starting and printing in text modes._ [(gitHub project)](https://github.com/mvac7/SDCC_TEXTMODE_MSXDOS_Lib)


## For develop MSX-DOS and ROMs applications:

- **MSX Z80 Memory Library** - _Basic functions for Z80's memory and page slots/sublots access._ [(gitHub project)](https://github.com/mvac7/SDCC_MEMORY_MSX_Lib)
- **VDP TMS9918A Library** - _Functions to work with the TMS9918A without using the MSX BIOS._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_TMS9918A_Lib) 
- **VDP SPRITES Library** - _Functions to facilitate the use of Sprites of the TMS9918A._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_SPRITES_Lib)
- **VDP VPRINT Library** - _Functions Library for display text strings in the graphic modes of the TMS9918A (G1 and G2)._ [(gitHub project)](https://github.com/mvac7/SDCC_VDP_VPRINT_Lib)
- **String BASICs Library** - _Basic functions for the treatment of Character Arrays in SDCC, similar to those of MSX BASIC._ [(gitHub project)](https://github.com/mvac7/SDCC_STRING_B_Lib)
- **PSG AY-3-8910 Library** - _Basic functions to work with PSG AY-3-8910 or compatible._ [(gitHub project)](https://github.com/mvac7/SDCC_AY38910_Lib)
- **PSG AY-3-8910 playFX Library** - _Functions for playing sound effects with the AY-3-8910._ [(gitHub project)](https://github.com/mvac7/SDCC_AY38910_playFX_Lib)
- **PT3 Player Library for MSX** - _SDCC PT3 Player (Vortex Tracker) Library for MSX._ [(gitHub project)](https://github.com/mvac7/SDCC_PT3player)
- **WYZ Player Library for MSX** - _SDCC WYZ Tracker Player Library for MSX._ [(gitHub project)](https://github.com/mvac7/SDCC_WYZplayer)
- **Z80 RLEWB decompress** - _C functions and Z80 Assembler source for decompress RLEWB data encoding._ [(gitHub project)](https://github.com/mvac7/Z80_RLEWB)
