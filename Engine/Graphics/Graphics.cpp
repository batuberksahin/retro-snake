#include "Graphics.h"

#include "../Engine.h"
#include "../../Assets/Objects/Snake.h"

#include <GL/glut.h>

#include <cmath>
#include <algorithm>

void Graphics::drawDebugTriangle(double time) {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, abs(sin(time * 2)), cos(time));
    glVertex2f(0.0f, 0.8f);
    glColor3f(cos(time), 1.0f, sin(time * 2));
    glVertex2f(0.4f, -0.2f);
    glColor3f(sin(time * 2), cos(time * 2), 1.0f);
    glVertex2f(-0.4f, -0.2f);
    glEnd();
}

void Graphics::drawRectangle() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.5f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void Graphics::drawString(int x, int y, char *string) {
    int length = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char *>(string));

    std::pair<float, float> positions = Engine::screenPositionToGLCoordinate(std::clamp(x - length / 2, 0, UINT16_MAX), y);

    glBegin(GL_BITMAP);

    glRasterPos2f(positions.first, positions.second);
    glColor3f(1.0f, 1.0f, 1.0f);

    for (char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glEnd();
}

void Graphics::drawSnakeHead(int posX, int posY, Direction direction) {
    std::pair<float, float> coordinates = Engine::screenPositionToGLCoordinate(posX, posY);

    float x = coordinates.first;
    float y = coordinates.second;

    float head_height = 0.05f;
    float head_width = 0.025f;

    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(static_cast<int>(direction) * 90, 0, 0, 1);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y + head_height);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x + head_width, y);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x - head_width, y);
    glEnd();
    glPopMatrix();
}