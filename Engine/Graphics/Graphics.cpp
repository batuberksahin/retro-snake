#include "Graphics.h"

#include "../Engine.h"
#include "../../Assets/Objects/Snake.h"
#include "../Config.h"

#include <GL/glut.h>

#include <cmath>
#include <algorithm>
#include <iostream>

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

void Graphics::drawGridLines() {
    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_LINES);
    for (int i = 0; i <= FIXED_WINDOW_HEIGHT; i += CELL_SIZE) {
        auto positions = Engine::screenPositionToGLCoordinate(0, i);

        glVertex2f(-1.0f, positions.second);
        glVertex2f(1.0f, positions.second);
    }
    glEnd();

    glBegin(GL_LINES);
    for (int i = 0; i <= FIXED_WINDOW_WIDTH; i += CELL_SIZE) {
        auto positions = Engine::screenPositionToGLCoordinate(i, 0);

        glVertex2f(positions.first, 1.0f);
        glVertex2f(positions.first, -1.0f);
    }
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

    float head_part_width = static_cast<float>(CELL_SIZE) / FIXED_WINDOW_WIDTH;
    float head_part_height = static_cast<float>(CELL_SIZE) / FIXED_WINDOW_HEIGHT;

    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(0, 0, 0, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    switch (direction) {
        case Direction::UP:
            glVertex2f(0, head_part_height);
            glVertex2f(head_part_width, -head_part_height);
            glVertex2f(-head_part_width, -head_part_height);
            break;
        case Direction::DOWN:
            glVertex2f(0, -head_part_height);
            glVertex2f(-head_part_width, head_part_height);
            glVertex2f(head_part_width, head_part_height);
            break;
        case Direction::LEFT:
            glVertex2f(-head_part_width, 0);
            glVertex2f(head_part_width, head_part_height);
            glVertex2f(head_part_width, -head_part_height);
            break;
        case Direction::RIGHT:
            glVertex2f(head_part_width, 0);
            glVertex2f(-head_part_width, -head_part_height);
            glVertex2f(-head_part_width, head_part_height);
            break;
    }


    glEnd();
    glPopMatrix();
}

void Graphics::drawSnakeBodyPart(int posX, int posY) {
    std::pair<float, float> coordinates = Engine::screenPositionToGLCoordinate(posX, posY);

    float x = coordinates.first;
    float y = coordinates.second;

    float body_part_width = static_cast<float>(CELL_SIZE) / FIXED_WINDOW_WIDTH;
    float body_part_height = static_cast<float>(CELL_SIZE) / FIXED_WINDOW_HEIGHT;

    glPushMatrix();
    glTranslatef(x, y, 0);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-body_part_width, -body_part_height);
    glVertex2f(body_part_width, -body_part_height);
    glVertex2f(body_part_width, body_part_height);
    glVertex2f(-body_part_width, body_part_height);
    glEnd();

    glPopMatrix();
}
