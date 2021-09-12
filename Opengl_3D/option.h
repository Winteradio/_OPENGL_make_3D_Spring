#include "particle.h"
#include <GL/freeglut.h>
#include "particle.h"
#ifndef __OPT_H__
#define __OPT_H__
class Option {
public:

	void reset();

	void start();

	void drawBitmapText(char* str, float x, float y, float z);
};

#endif // !__OPT_H__
