382-Lab-4
=========
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
