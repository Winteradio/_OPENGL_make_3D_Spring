#ifndef __PHY_H__
#define __PHY_H__

class Physics {
private : 
	float G = -0.0f; // 중력 상수 // 단위 [m/s^2]
	float Ks = 500.0f; // 용수철 계수 // 단위 [N/m]
	float Kd = 0.5f; // 항력 계수 
	float Kr = 0.5f; // 반발계수
	float mass = 10.0f; // 점들의 무게
	float L = 200.0f; // 용수철 원래 길이 // 단위 [m] >> [cm]로 변경 필요, [m]일 경우 크기가 너무 커지기에 시각적으로 시뮬레이션 효과 와닿지 않음
	float e = 0.00001f; // e 충돌과 접촉 시에 쓰이는 상수

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
