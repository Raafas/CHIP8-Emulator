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
    
    clearScreen();
    for(int i = 0; i < 4096; ++i) memory[i] = 0; //clear memory
    
    delay_timer = 0;
    sound_timer = 0;
}


void core::clearScreen(){
    for(int i = 0; i < 2048; ++i) gfx[i] = 0; //clear display
}

void core::initialize()
{
    //init registers and memory
}


void core::emulateCycle()
{
    opcode = memory[pc] << 8 | memory[pc+1]; //fetch opcode
    
    //decode opcode
    switch (opcode & 0xF000) {
        case 0x0000:
            switch(opcode & 0x000F){
                case 0x0000: // 0x00E0: Clears the screen
                    clearScreen();
                    break;
                    
                default:
                    printf("Invalid opcode: 0x%X\n",opcode);
            }
            break;

        case 0x1000: // 0x1NNN: Jumps to address NNN
            pc = opcode & 0x0FFF;
            break;
    
        case 0x2000: // 0x2NNN: Calls subroutine at NNN.
            stack[sp] = pc;			// Store current address in stack
            ++sp;					// Increment stack pointer
            pc = opcode & 0x0FFF;	// Set the program counter to the address at NNN
            break;
            
        case 0x3000: // 0x3XNN: Skips the next instruction if VX equals NN
            (V[(opcode & 0x0F00) >> 8] == (opcode & 0x00FF))? pc += 4 : pc += 2;
            break;
            
        case 0x4000: // 0x4XNN: Skips the next instruction if VX doesn't equal NN
            (V[(opcode & 0x0F00) >> 8] != (opcode & 0x00FF))? pc += 4 : pc += 2;
            break;
            
        case 0x5000: // 0x5XY0: Skips the next instruction if VX equals VY.
            (V[(opcode & 0x0F00) >> 8] == V[(opcode & 0x00F0) >> 4]) ? pc += 4 : pc += 2;
            break;
            
        case 0x6000: // 0x6XNN: Sets VX to NN.
            V[(opcode & 0x0F00) >> 8] = opcode & 0x00FF;
            pc += 2;
            break;
            
        case 0x7000: // 0x7XNN: Adds NN to VX.
            V[(opcode & 0x0F00) >> 8] += opcode & 0x00FF;
            pc += 2;
            break;
            
        // 0x8000
            
        case 0x9000: // 0x9XY0: Skips the next instruction if VX doesn't equal VY
            if(V[(opcode & 0x0F00) >> 8] != V[(opcode & 0x00F0) >> 4])
                pc += 4;
            else
                pc += 2;
            break;
            
            
        case 0xA000: //Sets I to the address NNN.
            //execute opcode
            I = opcode & 0x0FF;
            pc += 2;
            break;
            

            
    }
    //TODO: update timers
}






