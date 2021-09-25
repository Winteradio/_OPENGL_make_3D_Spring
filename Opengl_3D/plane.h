#ifndef __PLA_H__
#define __PLA_H__

class Plane {
private:
	float a_angle = 0.0, b_angle = 0.0, ratio;
	float x = 6.0f, y = 6.0f, z = 10.0f;
	float lx = -1.0f, ly = -1.0f, lz = -3.0f;
public :
	void drawplane();

	void drawsystem();

	void drawBitmapText(char* str, float x, float y, float z);
};

#endif