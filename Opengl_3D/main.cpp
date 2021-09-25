#include "GL/freeglut.h"
#include "Camera.h"
#include "particle.h"
#include "option.h"
#include "physics.h"
#include "plane.h"
#include <iostream>

//사용할 라이브러리를 지정해줍니다.
#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glew32s.lib")

using namespace std;

float T_Time = 0.0f;

Camera C = Camera();
Particle Pa = Particle();
Physics P = Physics();
Option O = Option();
Plane Pl = Plane();

// 극좌표계
double camera[3] = { 5.0f,45.0f,45.0f }; // 카메라의 극 좌표계 { 반지름 , XY 평면 각도, Z 축 각도}

// 직교 좌표계
double CX[3];                           // CX : 카메라 위치의 직교 좌표계
double up[3] = { 0.0f,0.0f,1.0f };      // 카메라 상단의 직교 좌표계
double CY[3] = { 0,0,0 };               // 카메라 초점의 직교 좌표계

// 마우스의 상태 표현
int drag;   // drag 0 : 아무것도 누르지 않은 상태
			// drag 1 : 마우스 왼쪽 키를 누른 상태
			// drag 2 : 마우스 오른쪽 키를 누른 상태

// 윈도우 내에서의 마우스 위치 및 이동 반경 변수
double mousePos[2];
double mouseMove[2];


void changesize(int w, int h)
{
	// 창이 너무 작아졌을때 0 으로 나뉘는 것을 방지합니다.
	if (h == 0)
		h = 1;

	double ratio = 1.0f * w / h;
	// 좌표계를 수정하기 전에 초기화합니다.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 뷰포트를 창 전체크기로 설정합니다. 
	glViewport(0, 0, w, h);

	// 절단 공간을 설정합니다.
	gluPerspective(60, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(CX[0], CX[1], CX[2], -CX[0] + CY[0], -CX[1] + CY[1], -CX[2] + CY[2], up[0], up[1], up[2]);
}

void C_Timer(int value) {
	C.degree(camera);
	if (drag == 1 || drag == 0) {
		C.calculate(camera, CX);
	}
	else if (drag == 2) {
		double CX1[3];
		C.calculate(camera, CX);
		camera[0] = sqrt(pow(camera[0], 2) + C.Dot(mouseMove));
		camera[1] -= atan2(mouseMove[1], camera[0]) / (3.14);
		camera[2] += atan2(mouseMove[0], camera[0]) / (3.14);
		C.calculate(camera, CX1);
		for (int i = 0; i <= 2; i++) {
			CY[i] += CX1[i] - CX[i];
			CX[i] = CX1[i];
		}

	}
	glLoadIdentity();
	gluLookAt(CX[0], CX[1], CX[2], -CX[0] + CY[0], -CX[1] + CY[1], -CX[2] + CY[2], up[0], up[1], up[2]);
	glutPostRedisplay();
	glutTimerFunc(P.Time, C_Timer, 0);
}


void Timer(int value) {
	P.S_Force(Pa.particle);
	for (int i = 0; i < Pa.num; i++) {
		P.G_Force(i, Pa.particle);
		P.D_Force(i, Pa.particle);
		P.Contact(i, Pa.particle);
		P.E_Velocity(i, Pa.particle);
		P.Collision(i, Pa.particle);
		for (int j = 0; j <= 2; j++) {
			Pa.particle[i][0][j] += Pa.particle[i][1][j] * (float)P.Time / 1000;
		}

	}
	O.reset(Pa.particle);
	T_Time += (float)P.Time / 1000;
	glutPostRedisplay();
	glutTimerFunc(P.Time, Timer, 1);
}

void mouse_click(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			drag = 1;
			mousePos[0] = (double)(x - GLUT_INIT_WINDOW_WIDTH / 2) * 2 / GLUT_INIT_WINDOW_WIDTH;
			mousePos[1] = (double)(y - GLUT_INIT_WINDOW_HEIGHT / 2) * 2 / GLUT_INIT_WINDOW_HEIGHT;

		}
		else {
			drag = 0;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			drag = 2;
			mousePos[0] = (double)(x - GLUT_INIT_WINDOW_WIDTH / 2) * 2 / GLUT_INIT_WINDOW_WIDTH;
			mousePos[1] = (double)(y - GLUT_INIT_WINDOW_HEIGHT / 2) * 2 / GLUT_INIT_WINDOW_HEIGHT;
		}
		else {
			drag = 0;
		}
		break;
	}
}
void mouse_move(int x, int y) {
	if (drag != NULL) {
		mouseMove[0] = (double)(x - GLUT_INIT_WINDOW_WIDTH / 2) * 2 / GLUT_INIT_WINDOW_WIDTH - mousePos[0];
		mouseMove[1] = (double)(y - GLUT_INIT_WINDOW_HEIGHT / 2) * 2 / GLUT_INIT_WINDOW_HEIGHT - mousePos[1];

		if (drag == 1) {
			camera[2] += atan2(mouseMove[0], camera[0]) / (3.14);
			camera[1] -= atan2(mouseMove[1], camera[0]) / (3.14);
		}
	}
}

void mouse_wheel(int button, int dir, int x, int y) {
	if (dir > 0) {
		camera[0] = camera[0] / 2;
	}
	else {
		camera[0] = camera[0] * 2;
	}
	return;
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	Pl.drawplane();
	Pl.drawsystem();
	
	glPointSize(10);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	{
		for (int i = 0; i < Pa.num; i++) {
			glVertex3f(Pa.particle[i][0][0], Pa.particle[i][0][1], Pa.particle[i][0][2]);
		}
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	{for (int i = 0; i < Pa.num - 1; i++) {
		for (int j = i + 1; j < Pa.num; j++) {
			glVertex3f(Pa.particle[i][0][0], Pa.particle[i][0][1], Pa.particle[i][0][2]);
			glVertex3f(Pa.particle[j][0][0], Pa.particle[j][0][1], Pa.particle[j][0][2]);
		}
	}}
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	O.start(Pa.particle);
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(120, 50);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(display);
	glClearColor(0.0, 0.0, 0.0, 0);
	glutTimerFunc(0, Timer, 1);
	glutTimerFunc(0, C_Timer, 1);
	glutReshapeFunc(changesize);

	glutMouseFunc(mouse_click);
	glutMotionFunc(mouse_move);
	glutMouseWheelFunc(mouse_wheel);
	glutMainLoop();
	return 0;
}
