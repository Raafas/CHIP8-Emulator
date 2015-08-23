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

#ifdef __APPLE__
#define b(...) printf(__VA_ARGS__);
#else
#include <windows.h>
#define b(...) Beep(__VA_ARGS__);
#endif


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
    void draw_sprite(uint8_t x, uint8_t y, uint8_t n);
    
public:
    void init();
    void emulateCycle();
    void initialize();
    void debugRender();
    bool loadApplication(const char * filename);
    void tick();
    void setkeys();
};
