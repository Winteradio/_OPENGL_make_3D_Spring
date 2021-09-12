#include "GL/freeglut.h"
#include "particle.h"
#include "option.h"
#include "physics.h"
#include "Display.h"
#include <iostream>

//사용할 라이브러리를 지정해줍니다.
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32s.lib")

using namespace std;

float T_Time = 0.0f;

Particle Pa = Particle();
Physics P = Physics();
Option O = Option();
Display D = Display();

void Timer(int value) {
	P.S_Force();
	for (int i = 0; i < Pa.num; i++) {
		P.G_Force(i);
		P.D_Force(i);
		P.E_Velocity(i);
		for (int j = 0; j <= 2; j++) {
			Pa.particle[i][0][j] += Pa.particle[i][1][j] * (float)P.Time / 1000;
		}
	}
	O.reset();
	T_Time += (float)P.Time / 1000;
	glutPostRedisplay();
	glutTimerFunc(P.Time, Timer, 1);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(5);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	{
		for (int i = 0; i < Pa.num; i++) {
			glVertex3f(Pa.particle[i][0][0] / 100, Pa.particle[i][0][1] / 100, Pa.particle[i][0][2]/100);
		}
	}
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	{for (int i = 0; i < Pa.num - 1; i++) {
		for (int j = i + 1; j < Pa.num; j++) {
			glVertex3f(Pa.particle[i][0][0] /100, Pa.particle[i][0][1] / 100, Pa.particle[j][0][2] / 100);
			glVertex3f(Pa.particle[j][0][0] / 100, Pa.particle[j][0][1] / 100 , Pa.particle[j][0][2]/100);
		}
	}}
	glEnd();
    glFlush();
}

int main(int argc, char** argv) {
	O.start();
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(120, 50);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(display);
	glClearColor(0.0, 0.0, 0.0, 0);
	glutTimerFunc(0, Timer, 1);
	glutMainLoop();
}
