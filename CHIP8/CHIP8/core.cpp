//
//  core.cpp
//  CHIP8
//
//  Created by Rafael Leandro on 22/08/15.
//  Copyright (c) 2015 Rafael Leandro. All rights reserved.
//

#include "core.h"


void core::init()
{
                //RESET
    pc = 0x200; //Start address program
    opcode = 0; //Current opcode
    I = 0;      //index register
    
    for(int i = 0; i < 2048; ++i) gfx[i] = 0; //clear display
    for(int i = 0; i < 4096; ++i) memory[i] = 0; //clear memory
    
    delay_timer = 0;
    sound_timer = 0;
}


void core::initialize()
{
    //init registers and memory
}


void core::emulateCicle()
{
    opcode = memory[pc] << 8 | memory[pc+1]; //fetch opcode
    
    //decode opcode
    switch (opcode & 0xF000) {
            
        case 0xA000: //Sets I to the address NNN.
            //execute opcode
            I = opcode & 0x0FF;
            pc += 2;
            break;
            
        default:
            printf("Invalid opcode: 0x%X\n",opcode);
            
    }
    //TODO: update timers
}






