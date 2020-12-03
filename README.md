# SDCC Joystick MSX ROM Functions Library

Version: 1.2

Author: mvac7/303bcn

Architecture: MSX

Format: C Object (SDCC .rel)

Programming language: C and Z80 assembler
 
mail: mvac7303b@gmail.com




## 1. Introduction

This project is an Open Source library with basic functions for reading joystick controllers or cursor keys of MSX computers.

It uses the functions from the MSX BIOS, so it is designed to create applications in ROM format.
  
Use them for developing MSX applications using Small Device C Compiler (SDCC) compilator.

Includes two applications for test and learning purposes.



## 2. Acknowledgments
  
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



## 3. Requirements

* Small Device C Compiler (SDCC) v3.9 http://sdcc.sourceforge.net/
* Hex2bin v2.5 http://hex2bin.sourceforge.net/ 



## 4. Functions

* char STICK(char joy) - Returns the joystick status.
* signed char STRIG(char joy) - Returns the trigger status.