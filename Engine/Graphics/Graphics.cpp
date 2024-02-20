#include "Graphics.h"

#include <GL/glut.h>
#include <cstring>
#include <iostream>

void Graphics::drawDebugTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void Graphics::drawRectangle() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void Graphics::drawString(float x, float y, char *string) {
    glBegin(GL_BITMAP);

    glRasterPos2f(x, y);
    glColor3f(1.0f, 1.0f, 1.0f);

    for (char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glEnd();
}