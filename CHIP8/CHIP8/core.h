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
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#endif /* defined(__CHIP8__core__) */

#define MEM_SIZE 4096
#define GFX_ROWS 32
#define GFX_COLS 64
#define GFX_SIZE (GFX_ROWS * GFX_COLS)
#define STACK_SIZE 16
#define KEY_SIZE 16

#define GFX_INDEX(row, col) ((row)*GFX_COLS + (col))

#define MAX_GAME_SIZE (0x1000 - 0x200)

class core {
private:
//    unsigned short opcode; //store current opcode
//    unsigned char memory[4096]; //4k memory emulated
//    unsigned char V[16]; //8bit register
//    unsigned short I; //Index register
//    unsigned short pc; //Program count
//    unsigned char delay_timer;
//    unsigned char sound_timer;
//    unsigned short stack[16]; //The stack is used to remember the current location before a jump is performed
//    unsigned short sp; //remember which level of the stack is used
    
    void clearScreen();
    void gfxSprite(unsigned short X, unsigned short Y, unsigned short N);
    void draw_sprite(uint8_t x, uint8_t y, uint8_t n);
    
public:
    void init();
    void emulateCycle();
    void initialize();
    void debugRender();
    bool loadApplication(const char * filename);
    void tick();
    void setkeys();
    
//    bool drawFlag;
//    unsigned char gfx[64 * 32]; //2048 pixels
//    bool gfx[32][64];
//    unsigned char key[16]; //HEX based keypad. Current state of key
};
