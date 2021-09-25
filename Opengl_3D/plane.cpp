#include "plane.h"
#include <gl/glut.h>

void Plane::drawBitmapText(char* str, float x, float y, float z) {
	glRasterPos3f(x, y, z); //문자열이 그려질 위치 지정

	while (*str)
	{
		//GLUT_BITMAP_TIMES_ROMAN_24 폰트를 사용하여 문자열을 그린다.
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);

		str++;
	}
}

void Plane::drawplane() { // 벡터 내적
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, -100.0f, 0.0f);
	glVertex3f(-100.0f, 100.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f);
	glVertex3f(100.0f, -100.0f, 0.0f);
	glEnd();
}

void Plane::drawsystem() {
	float num = 0;
	while (num <= 200) {
		glLineWidth(1);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
		glVertex3f(-100, -100 + num, 0);
		glVertex3f(100, -100 + num, 0);
		glVertex3f(-100 + num, -100, 0);
		glVertex3f(-100 + num, 100, 0);
		glEnd();
		num += 1;
	}

	char* arr[3][2] = { {"+X","-X"},{"+Y","-Y"},{"+Z","-Z"} };
	float matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	for (int i = 0; i <= 2; i++) {
		glLineWidth(3);
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex3f(5.0 * matrix[i][0], 5.0 * matrix[i][1], 5.0 * matrix[i][2]);
		glVertex3f(-5.0 * matrix[i][0], -5.0 * matrix[i][1], -5.0 * matrix[i][2]);
		glEnd();
		drawBitmapText(arr[i][0], 5.0 * matrix[i][0], 5.0 * matrix[i][1], 5.0 * matrix[i][2]);
		drawBitmapText(arr[i][1], -5.0 * matrix[i][0], -5.0 * matrix[i][1], -5.0 * matrix[i][2]);
	}
}
