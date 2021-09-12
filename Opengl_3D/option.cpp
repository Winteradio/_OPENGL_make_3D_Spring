#include "option.h"
#include <random>

Particle n = Particle();

void Option::reset() {
	for (int i = 0 ; i < n.num; i ++){
		for (int j = 0; j <= 2; j++) {
			n.particle[i][2][j] = 0;
		}

	}
}

void Option::start() {
	for (int i = 0; i < n.num; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 2; k++) {
				n.particle[i][j][k] = ((float)(rand() % 100 - 50));
			}
		}
	}
}

void Option::drawBitmapText(char* str, float x, float y, float z) {
	glRasterPos3f(x, y, z); //���ڿ��� �׷��� ��ġ ����

	while (*str)
	{
		//GLUT_BITMAP_TIMES_ROMAN_24 ��Ʈ�� ����Ͽ� ���ڿ��� �׸���.
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);

		str++;
	}
}