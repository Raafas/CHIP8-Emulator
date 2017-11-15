CHIP8-Emulator :space_invader:
==============
CHIP-8 is an interpreted programming language, developed by Joseph Weisbecker. It was initially used on the COSMAC VIP and Telmac 1800 8-bit microcomputers in the mid-1970s. CHIP-8 programs are run on a CHIP-8 virtual machine. It was made to allow video games to be more easily programmed for said computers.

Roughly twenty years after CHIP-8 was introduced, derived interpreters appeared for some models of graphing calculators (from the late 1980s onward, these handheld devices in many ways have more computing power than most mid-1970s microcomputers for hobbyists).

![game1](Docs/game1.png)

![game2](Docs/game2.png)

![game3](Docs/game3.png)

# Registers
CHIP-8 has 16 8-bit data registers named from V0 to VF. The VF register doubles as a carry flag.

# Timers
CHIP-8 has two timers. They both count down at 60 hertz, until they reach 0.

# Opcode table
| Opcode | Type | C Pseudo |  Explanation |
| -- | --- | -------- | ------------ |  
| 0NNN	| Call	| | Calls RCA 1802 program at address NNN. Not necessary for most ROMs. |
| 00E0	| Display| 	disp_clear()| 	Clears the screen. |
| 00EE	| Flow	| return;	| Returns from a subroutine. |
| 1NNN	| Flow	| goto NNN;	| Jumps to address NNN. | 
| 2NNN	| Flow	| *(0xNNN)()	| Calls subroutine at NNN.
| 3XNN	| Cond	| if(Vx==NN)	| Skips the next instruction if VX equals NN. (Usually the next instruction is a jump to skip a code block)| 
| 4XNN	| Cond	| if(Vx!=NN)	| Skips the next instruction if VX doesn't equal NN. (Usually the next instruction is a jump to skip a code block)
| 5XY0	| Cond	| if(Vx==Vy)	| Skips the next instruction if VX equals VY. (Usually the next instruction is a jump to skip a code block) | 
| 6XNN	| Const	| Vx = NN	| Sets VX to NN.| 
| 7XNN	| Const	| Vx += NN	| Adds NN to VX. (Carry flag is not changed)| 
| 8XY0	| Assign|  Vx=Vy	| Sets VX to the value of VY.| 
| 8XY1	| BitOp	| Vx=Vx| Vy	Sets VX to VX or VY. (Bitwise OR operation)| 
| 8XY2	| BitOp	| Vx=Vx&Vy	| Sets VX to VX and VY. (Bitwise AND operation)| 
| 8XY3	| BitOp	| Vx=Vx^Vy	| Sets VX to VX xor VY.| 
| 8XY4	| Math	| Vx += Vy	| Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.| 
| 8XY5	| Math	| Vx -= Vy	| VY is subtracted from VX. VF is set to 0 when there's a borrow, and 1 when there isn't.| 
| 8XY6	| BitOp	| Vx=Vy=Vy>>1	| Shifts VY right by one and copies the result to VX. VF is set to the value of the least significant bit of VY before the shift.| 
| 8XY7	| Math	| Vx=Vy-Vx	| Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there isn't.| 
| 8XYE	| BitOp	| Vx=Vy=Vy<<1	| Shifts VY left by one and copies the result to VX. VF is set to the value of the most significant bit of VY before the shift | 
| 9XY0	| Cond	| if(Vx!=Vy)	| Skips the next instruction if VX doesn't equal VY. (Usually the next instruction is a jump to skip a code block)| 
| ANNN	| MEM	| I = NNN | Sets I to the address NNN. | 
| BNNN	| Flow	| PC=V0+NNN | Jumps to the address NNN plus V0.| 
| CXNN	| Rand	| Vx=rand()&NN | Sets VX to the result of a bitwise and operation on a random number (Typically: 0 to 255) and NN. | 
| DXYN | Disp | draw(Vx,Vy,N) | 	Draws a sprite at coordinate (VX, VY) that has a width of 8 pixels and a height of N pixels. Each row of 8 pixels is read as bit-coded starting from memory location I; I value doesn’t change after the execution of this instruction. As described above, VF is set to 1 if any screen pixels are flipped from set to unset when the sprite is drawn, and to 0 if that doesn’t happen |
| EX9E	| KeyOp	| if(key()==Vx) | 	Skips the next instruction if the key stored in VX is pressed. (Usually the next instruction is a jump to skip a code block)|
| EXA1	| KeyOp	| if(key()!=Vx)	| Skips the next instruction if the key stored in VX isn't pressed. (Usually the next instruction is a jump to skip a code block) |
| FX07	| Timer	| Vx = get_delay() | 	Sets VX to the value of the delay timer. |
| FX0A	| KeyOp | Vx = get_key() | A key press is awaited, and then stored in VX. (Blocking Operation. All instruction halted until next key event) |
| FX15	| Timer | delay_timer(Vx) | Sets the delay timer to VX. |
| FX18	| Sound	| sound_timer(Vx) | Sets the sound timer to VX. |
| FX1E	| MEM	| I +=Vx | Adds VX to I. |
| FX29	| MEM	| I=sprite_addr[Vx]| 	Sets I to the location of the sprite for the character in VX. Characters 0-F (in hexadecimal) are represented by a 4x5 font.|
| FX33 | BCD | set_BCD(Vx); *(I+0)=BCD(3); *(I+1)=BCD(2); *(I+2)=BCD(1);| Stores the binary-coded decimal representation of VX, with the most significant of three digits at the address in I, the middle digit at I plus 1, and the least significant digit at I plus 2. (In other words, take the decimal representation of VX, place the hundreds digit in memory at location in I, the tens digit at location I+1, and the ones digit at location I+2.) |
| FX55	| MEM	| reg_dump(Vx,&I)| 	Stores V0 to VX (including VX) in memory starting at address I. I is increased by 1 for each value written. |
| FX65 | MEM | reg_load(Vx,&I) | 	Fills V0 to VX (including VX) with values from memory starting at address I. I is increased by 1 for each value written. |

# Compile
Depends on OpenGL and GLUT
-  Linux: 
  -  Ubuntu: sudo apt-get install freeglut3-dev
  -  Fedora/RedHat: sudo yum install freeglut-devel
-  Windows:
  -  Download link https://www.opengl.org/resources/libraries/glut/glut37.zip
- OS X:
  -  OpenGL and GLUT come with the OS and Xcode installations.

# Use
./CHIP8 game.c8

# More games
http://www.pong-story.com/chip8/ some games.
