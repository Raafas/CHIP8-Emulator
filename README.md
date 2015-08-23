CHIP8-Emulator
==============
CHIP-8 is an interpreted programming language, developed by Joseph Weisbecker. It was initially used on the COSMAC VIP and Telmac 1800 8-bit microcomputers in the mid-1970s. CHIP-8 programs are run on a CHIP-8 virtual machine. It was made to allow video games to be more easily programmed for said computers.

Roughly twenty years after CHIP-8 was introduced, derived interpreters appeared for some models of graphing calculators (from the late 1980s onward, these handheld devices in many ways have more computing power than most mid-1970s microcomputers for hobbyists).


#Registers
CHIP-8 has 16 8-bit data registers named from V0 to VF. The VF register doubles as a carry flag.

#Timers
CHIP-8 has two timers. They both count down at 60 hertz, until they reach 0.

#Opcode table

#Compile
Depends on OpenGL and GLUT
###Linux: Ubuntu# sudo apt-get install freeglut3-dev or Fedora/RedHat# sudo yum install freeglut-devel
###Windows: https://www.opengl.org/resources/libraries/glut/glut37.zip
###OS X: OpenGL and GLUT come with the OS and Xcode installations.

#Use
./CHIP8 <game.c8>

#More games
http://www.pong-story.com/chip8/ some games.
