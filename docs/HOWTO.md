# How to use the Joystick MSX SDCC Library

| Attention! |
| :---       |
| The following document has been written using an English translator.<br/>You can participate in the improvement of this document, transmitting your corrections or suggestions in the issues of this project or the main fR3eL project.<br/>Thanks for understanding. |

<br/>

## Index

- [1 Description](#1-Description)
- [2 Requirements](#2-Requirements)
- [3 Definitions](#3-Definitions)
    - [3.1 Joystick type](#31-Joystick-type)
    - [3.2 Joystick state](#32-Joystick-state)
    - [3.3 Trigger type](#33-Trigger-type)
    - [3.4 Trigger state](#34-Trigger-state)
- [4 Functions](#4-Functions)
    - [4.1 STICK](#41-STICK)
    - [4.2 STRIG](#42-STRIG)
- [5 References](#5-References)

<br/>

---

## 1 Description

Library with basic functions for reading joystick controllers or cursor keys of MSX computers.

In this project you will find two libraries for different environments:
- **joystick_MSX** Does not use the MSX BIOS. You can use it for any environment (ROM, MSX BASIC or MSX-DOS)
- **joystick_MSXBIOS** Uses the MSX BIOS. It takes up very little memory. You can use it in ROMs from 8 to 32K or programs that run from MSX BASIC environment.

The functions work with the same values ​​as the corresponding instructions in MSX BASIC.

You will find definitions to improve the readability of the source code.

These libraries are part of the [MSX fR3eL Project](https://github.com/mvac7/SDCC_MSX_fR3eL).

Use them for developing MSX applications using Small Device C Compiler [`SDCC`](http://sdcc.sourceforge.net/).

This project is an Open Source. 
You can add part or all of this code in your application development or include it in other libraries/engines.

<br/>

---


## 2 Requirements

- [Small Device C Compiler (SDCC) v4.4](http://sdcc.sourceforge.net/)
- [Hex2bin v2.5](http://hex2bin.sourceforge.net/)


<br/>

---

## 3 Definitions

### 3.1 Device identifier

Label | Value
:---  | ---:
CURSORKEYS | 0
JOYSTICKA  | 1
JOYSTICKB  | 2

<br/>

### 3.2 Joystick state

Label | Value
:---  | ---:
JOYSTICK_INACTIVE   | 0
JOYSTICK_UP         | 1
JOYSTICK_UP_RIGHT   | 2
JOYSTICK_RIGHT      | 3
JOYSTICK_DOWN_RIGHT | 4
JOYSTICK_DOWN       | 5
JOYSTICK_DOWN_LEFT  | 6
JOYSTICK_LEFT       | 7
JOYSTICK_UP_LEFT    | 8

<br/>

### 3.3 Trigger identifier

Label | Value
:---  | ---:
SPACEBAR_BUTTON   | 0
KEYBOARD_BUTTON   | 0
JOYSTICKA_BUTTONA | 1
JOYSTICKB_BUTTONA | 2
JOYSTICKA_BUTTONB | 3
JOYSTICKB_BUTTONB | 4

<br/>

### 3.4 Trigger state

Label | Value
:---  | ---:
BUTTON_UNPRESSED |  0
BUTTON_PRESSED   | -1

<br/>

---

## 4 Functions


### 4.1 STICK

<table>
<tr><th colspan=3 align="left">STICK</th></tr>
<tr><td colspan=3>Returns the joystick status</td></tr>
<tr><th>Function</th><td colspan=2>char STICK(char joy)</td></tr>
<tr><th>Input</th><td><pre>char</pre></td><td>cursor/joystick device identifier</td></tr>
<tr><th>Output</th><td><pre>char</pre></td><td>status</td></tr>
</table>


#### Input

`char` cursor/joystick device identifier 

Value | Button
---:  | :---
0     | Cursor Keys
1     | Joystick A
2     | Joystick B

<br/>

#### Output 

[char] state value 

Value | State
---:  | :---
0 | Inactive
1 | Up
2 | Up & Right
3 | Right
4 | Down & Right
5 | Down
6 | Down & Left
7 | Left
8 | Up & Left

<br/>

Uncommon game controller direction combinations return the same values as the BIOS GTSTCK function.

Combination | Result
:---        | :---
`UP`+`DOWN`+`RIGHT`+`LEFT` | 0 
`UP`+`DOWN` | 0
`RIGHT`+`LEFT` | 0 
`UP`+`LEFT`+`DOWN`  | LEFT
`UP`+`RIGHT`+`DOWN` | RIGHT
`LEFT`+`UP`+`RIGHT`   | UP
`LEFT`+`DOWN`+`RIGHT` | DOWN


#### Example
  
```c
  char joyval;
  
  joyval = STICK(JOYSTICKA);
  
  if (joyval!=JOYSTICK_INACTIVE){  
    switch (joyval) 
    {     
      case JOYSTICK_UP:
        moveUp();
        break;
  
      case JOYSTICK_RIGHT:              
        moveRight();
        break;
  
      case JOYSTICK_DOWN:
        moveDown();
        break;
  
      case JOYSTICK_LEFT:
        moveLeft();
        break;   
    }
  }
```


### 4.2 STRIG

<table>
<tr><th colspan=3 align="left">STRIG</th></tr>
<tr><td colspan=3>Returns the trigger status</td></tr>
<tr><th>Function</th><td colspan=2>signed char STRIG(char triggerN)</td></tr>
<tr><th>Input</th><td><pre>char</pre></td><td>cursor/joystick button identifier</td></tr>
<tr><th>Output</th><td><pre>signed char</pre></td><td>status</td></tr>
</table>


#### Input

`char` cursor/joystick button identifier 

Value | Button
---:  | :---
0     | space key
1     | Joystick A - button 1
2     | Joystick B - button 1
3     | Joystick A - button 2
4     | Joystick B - button 2

<br/> 

#### Output

`signed char` status value 

Value | State
---:  | :---
 0    | inactive
-1    | pressed 

<br/>

#### Example
  
```c
  signed char press;
  
  press = STRIG(KEYBOARD_BUTTON); //spacebar
  if (press==BUTTON_UNPRESSED) press = STRIG(JOYSTICKA_BUTTONA);
  if (press==BUTTON_PRESSED) Fire();
```

<br/>

---

## 5 References

- MSX2 Technical Handbook - Chapter 5 - Access to peripherals through BIOS - [5.2 Joystick use](https://konamiman.github.io/MSX2-Technical-Handbook/md/Chapter5a.html#52-joystick-use)
- The MSX Red Book - 3. Programmable Sound Generator - [Register 14 and 15](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md#register_14)
- The MSX Red Book - 1. Programmable Peripheral Interface - [PPI Port B and C](https://github.com/gseidler/The-MSX-Red-Book/blob/master/the_msx_red_book.md#ppi_port_b)
- [MSX Resource Center](https://www.msx.org/) - Wiki - [Joystick/joypad controller](https://www.msx.org/wiki/Joystick/joypad_controller)
- [MSX Resource Center](https://www.msx.org/) - Wiki - [MSX-BASIC Instructions)(https://www.msx.org/wiki/Category:MSX-BASIC_Instructions) - [STICK](https://www.msx.org/wiki/STICK())
- [MSX Resource Center](https://www.msx.org/) - Wiki - [MSX-BASIC Instructions)(https://www.msx.org/wiki/Category:MSX-BASIC_Instructions) - [STICK](https://www.msx.org/wiki/STRIG())

<br/>

---

![Creative Commons License](https://i.creativecommons.org/l/by-nc/4.0/88x31.png) 
<br/>This document is licensed under a [Creative Commons Attribution-NonCommercial 4.0 International License](http://creativecommons.org/licenses/by-nc/4.0/).
