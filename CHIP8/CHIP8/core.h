//
//  core.h
//  CHIP8
//
//  Created by Rafael Leandro on 22/08/15.
//  Copyright (c) 2015 Rafael Leandro. All rights reserved.
//

#ifndef __CHIP8__core__
#define __CHIP8__core__

#include <stdio.h>

#endif /* defined(__CHIP8__core__) */


class core {
private:
    unsigned short opcode; //store current opcode
    unsigned char memory[4096]; //4k memory emulated
    unsigned char V[16]; //8bit register
    unsigned short I; //Index register
    unsigned short pc; //Program count
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned char key[16]; //HEX based keypad. Current state of key
    unsigned short stack[16]; //The stack is used to remember the current location before a jump is performed
    unsigned short sp; //remember which level of the stack is used
    
    void clearScreen();
    
    
public:
    void init();
    void emulateCycle();
    void initialize();

    
    unsigned char gfx[64 * 32]; //2048 pixels
};
