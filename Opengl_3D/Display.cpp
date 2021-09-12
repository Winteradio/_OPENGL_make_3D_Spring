#include "GL/freeglut.h"
#include "Display.h"
#include "physics.h"

void Display::D_display() {
    glPushMatrix();

    glPushMatrix();
    glLineWidth(2);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(2);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, -1.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(1);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    {
        float num = 0;
        while (num <= 40) {
            glVertex3f(-10, -10 + num / 2, 0);
            glVertex3f(10, -10 + num / 2, 0);
            glVertex3f(-10 + num / 2, -10, 0);
            glVertex3f(-10 + num / 2, 10, 0);
            num += 1;
        }
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glFlush();
}

void Display::Camera(){

}