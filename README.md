# 382-Lab-4

## Prelab

### Data types

| Size       | Signed/Unsigned | Type | Min Value | Max Value |
| ---------- | --------------- | ---- | --------- | --------- |
|   8-bit    | unsigned        | unsigned char, bool, _Bool | 0 | 255 |
|   8-bit    | signed          | signed char | -128 | 127 |
|   16-bit   | unsigned        | unsigned short | 0 | 65 535 |
|   16-bit   | signed          | short, signed short | -32 768 | 32 767 |
|   32-bit   | unsigned        | unsigned long | 0 |  4 294 967 295 |
|   32-bit   | signed          | long, signed long | -2,147,483,648 | 2 147 483 647 |
|   64-bit   | unsigned        | unsigned long long | 0 | 18 446 744 073 709 551 615 |
|   64-bit   | signed          | long long, signed long long | -9 223 372 036 854 775 808 | 9 223 372 036 854 775 807 |

| Type   | Meaning               | C typedef declaration |
| ------ | --------------------- | --------------------- | 
| int8   | unsigned 8-bit value  | typedef unsigned char int8;        |
| sint8  | signed 8-bit value    | typedef signed char sint8;         |
| int16  | unsigned 16-bit value | typedef unsigned short int16;      |
| sint16 | signed 16-bit value   | typedef signed short sint16;       | 
| int32  | unsigned 32-bit value | typedef unsigned long int32;       | 
| sint32 | signed 32-bit value   | typedef signed long sint32;        | 
| int64  | unsigned 64-bit value | typedef unsigned long long int64;  | 
| sint64 | signed 64-bit value   | typedef signed long long sint64;   |

### Calling/Return Convention

| Iteration  | a   | b   | c   | d   | e   |
| ---------- | --- | --- | --- | --- | --- |
| 1st        | 2 | 2 | 3 | 4 | 2 |
| 2nd        | 8 | 9 | 8 | 7 | 8 |
| 3rd        | 14 | 15 | 14 | 13 | 14 |
| 4th        | 20 | 21 | 20 | 19 | 20 |
| 5th        | 26 | 27 | 26 | 25 | 26 |

| Parameter  | Value Sought   |
| ---------- | -------------- |
| Starting address of func | c0ba |
| Ending address of func   | c0c6 | 
| Register holding w       | R12 | 
| Register holding x       | R13 |
| Register holding y       | R14 | 
| Register holding z       | R15 | 
| Register holding return value       | R12 | 

### Cross language build constructs

#### What is the role of the extern directive in a .c file?  

`extern` tells the .c file that the variable is defined elsewhere. The compiler asks the global symbol table what the  
matching global variable means (as defined in the .asm file as a `.global` variable).

#### What is the role of the .global directive in an .asm file (used in lines 28-32)?  

`.global` defines a variable as an entry into the global symbol table. When the .c file uses `extern`, this is where  
the compiler looks to know what to do with the variable

## Lab Report
### Objectives
The objectives of Lab 4 were to expand our C coding skills by combining C language with assembly language. This was done by first creating an etch-a-sketch program using the LCD display. Then, a Pong game was created to use previous knowledge gained through Assignment 6.
## Code
Code for the lab (lab4.c, nokia.asm, simpleLab4.c, lab4BFunc.c, nokiaBFunc.asm) can be found in the "Code" file.
## Debugging
Once the BLACK and WHITE colors had been defined in lab4.c, it took some effort to find out how to implement the change in the color itself. My original thought was to have two `if` statements- one after another. This prooved ineffective since the program would run through both; ultimately changing the color from black to white to black. To solve this, I had the second `if` statement changed to an `else if`- this solved the problem.  
For B functionality, it took me a while to figure out how to use the newly created velocity variables. I first tried to pass them in as I did with `color`. However, I found out that I needed to change what `R12` and `R13` were to begin with since changing them in the assembly code would prove to be much harder. To do this, I made the variables simply modify what `x` and `y` were in the C file, then pass them in with the changes already in place.
## Testing methodology / Results
I began by first finding out how to make the block drag, or not erase its earlier position after a movement. This only required removing the `clearDisplay` call on line 61 of lab4.c. This allowed me to make a solid line of black squares. Afterward, I needed to change the color of the block to white. This meant I had to define a color variable, what black and white meant, and the implementation for the changing of colors. The colors `BLACK` and `WHITE` were defined to 2 and 3 (respectively), and `color` was initialized to be equal to 2. A button poll was then setup with likeness to the syntax of the movement buttons, but with an `if` and `else if` statement to determine what the color needed to be changed to. The calls to `drawBlock` were then edited to include the `color` variable as well as the `x` and `y` terms for position. This new variable would be sent to `R14` by the method used by CCS. This meant that `R14` had to be pushed onto and popped off of the stack within the `drawBlock` subroutine. A `cmp` instruction was then used between `R14` and `#2` to determine if the block needed to be black (`jz`) or white (`jmp` if the `jz` was untrue). These separate loops `loopBlack` and `loopWhite` would either store `0xFF` or `0x00` as data for a filled (black) 8x8 square or a blank (white) 8x8 space, and then continue with the normal program.  
In order to create a bouncing block, I defined two new `signed int` variables `xVel` and `yVel`. These had to be `signed int` so that they could be changed to negative values. They were initialized the same way `x` and `y` were, and only the position values were passed onto `drawBlock`. I found out that trying to pass these into the subroutine would mean having to overmanipulate the registers, and would be quite the task. I used the `AUX_BUTTON` that I had used for the `color` variable originally, but instead used it as a delay function that would check for walls given the `y` and `x` values that the block was at. After changing the sign of the velocity, if needed, the block would move by adding the velocities to their position counterpart. Using the original `nokia.asm` that simply drew the 8x8 block, no additional changes had to be made to the file.
## Observations and Conclusions
When the C program needs to know what an `extern` variable is, it asks the assembly file's `global` variable list. If a C function calls an assembly subroutine, the variables passed are stored in `R12`, `R13`, `R14`, `R15`, and the stack. If the values being passed are to be modified, then it is wise to do so without passing the changes to the assembly subroutine as well- this creates problems with the registers and what may already be in place.
## Documentation
C2C Terragnoli and I collaborated on the required functionality portion of the lab. We explained our ideas to one another for how to define variables and how to implement the color change within the assembly file.
