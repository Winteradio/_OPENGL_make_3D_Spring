#ifndef __PHY_H__
#define __PHY_H__

class Physics {
private : 
	float G = -0.0f; // �߷� ��� // ���� [m/s^2]
	float Ks = 500.0f; // ���ö ��� // ���� [N/m]
	float Kd = 0.5f; // �׷� ��� 
	float Kr = 0.5f; // �ݹ߰��
	float mass = 10.0f; // ������ ����
	float L = 200.0f; // ���ö ���� ���� // ���� [m] >> [cm]�� ���� �ʿ�, [m]�� ��� ũ�Ⱑ �ʹ� Ŀ���⿡ �ð������� �ùķ��̼� ȿ�� �ʹ��� ����
	float e = 0.00001f; // e �浹�� ���� �ÿ� ���̴� ���

	float Dot(float V1[3], float V2[3]);

	float Distance(float V1[3]);

public:
	int Time = 1; // Time_step

	void G_Force(int i);

	void D_Force(int i);

	void S_Force();

	void E_Velocity(int i);

	void Collision(int i);

	void Contact(int i);
};

#endif
