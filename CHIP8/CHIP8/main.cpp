//
//  main.cpp
//  CHIP8
//
//  Created by Rafael Leandro on 11/09/14.
//  Copyright (c) 2014 Rafael Leandro. All rights reserved.
//


#ifdef __APPLE__
#include "GLUT/glut.h"
#else 
#include <GL/glut.h>
#endif
#include "core.h"


core chip8;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5,  0.5);
    glVertex2f(0.5,  0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    
    glFlush();
}

void init()
{
    glClearColor(0.000, 0.110, 0.392, 0.0); // JMU Gold
    
    glColor3f(0.314, 0.314, 0.000); // JMU Purple
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CHIP8");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}


