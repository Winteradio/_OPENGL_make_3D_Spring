
#include "particle.h"
#ifndef __PHY_H__
#define __PHY_H__

class Physics {
private : 
	float G = -10.0f; // �߷� ��� // ���� [m/s^2]
	float Ks = 200.0f; // ���ö ��� // ���� [N/m]
	float Kd = 0.5f; // �׷� ��� 
	float Kr = 0.5f; // �ݹ߰��
	float mass = 10.0f; // ������ ����
	float L = 5.0f; // ���ö ���� ���� // ���� [m] >> [cm]�� ���� �ʿ�, [m]�� ��� ũ�Ⱑ �ʹ� Ŀ���⿡ �ð������� �ùķ��̼� ȿ�� �ʹ��� ����
	float e = 0.0000001f; // e �浹�� ���� �ÿ� ���̴� ���

	float X_Delta[3];
	float N_Delta[3] = { 0,0,1 };
	float V_Delta[3];

	float Dot(float V1[3], float V2[3]);

	float Distance(float V1[3]);

public:
	int Time = 10; // Time_step

	void G_Force(int i,float particle[8][3][3]);

	void D_Force(int i, float particle[8][3][3]);

	void S_Force(float particle[8][3][3]);

	void E_Velocity(int i, float particle[8][3][3]);

	void Collision(int i, float particle[8][3][3]);

	void Contact(int i, float particle[8][3][3]);
};

#endif
