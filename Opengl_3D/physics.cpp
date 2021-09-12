#include "GL/freeglut.h"
#include "physics.h"
#include "particle.h"
#include <math.h>

Particle N = Particle();

float Physics::Dot(float V1[3], float V2[3]) { // 벡터 내적
	return V1[0] * V2[0] + V1[1] * V2[1] + V1[2] * V2[2];
}

float Physics::Distance(float V1[3]) { // 두 점 사이의 거리
	return (float)pow((pow(V1[0], 2) + pow(V1[1], 2) + pow(V1[2], 2)), 0.5);
}


void Physics::G_Force(int i) { // 중력 계산
	N.particle[i][2][1] += G * mass;
}

void Physics::D_Force(int i) { // 항력 계산
	for (int j = 0; j <= 2; j++) {
		N.particle[i][2][j] += -Kd * N.particle[i][1][j];
	}
}

void Physics::S_Force() {// 탄성력 계산
	float X_Delta[3];
	float V_Delta[3];
	for (int i = 0; i < N.num - 1; i++) {
		for (int j = i + 1; j < N.num; j++) {
			for (int t = 0; t <= 2; t++) {
				X_Delta[t] = N.particle[i][0][t] - N.particle[j][0][t];
				V_Delta[t] = N.particle[i][1][t] - N.particle[j][1][t];
			}
			for (int t = 0; t <= 2; t++) {
				N.particle[i][2][t] += -(Ks * (Distance(X_Delta) - L) + Kd * Dot(V_Delta, X_Delta) / Distance(X_Delta)) * X_Delta[t] / Distance(X_Delta);
				N.particle[j][2][t] += -N.particle[i][2][t];
			}
		}
	}
}


void Physics::E_Velocity(int i) { // Euler Velocity 속도 계산
	for (int j = 0; j <= 2; j++) {
		N.particle[i][1][j] += ((float)Time / 1000) * N.particle[i][2][j] / mass;
	}
}

void Physics::Collision(int i) { // 충돌 계산
	float X_Delta[3] = { 0,0,0 };
	float N_Delta[3] = { 0,0,0 };
	float V_Delta[3] = { 0,0,0 };
	if (N.particle[i][0][1] <= 0) {
		N_Delta[1] = 1;
		for (int k = 0; k <= 2; k++) {
			V_Delta[k] = N.particle[i][0][k];
			if (k != 0) {
				X_Delta[k] = N.particle[i][0][k];
			}
		}
	}
	if (Dot(X_Delta, N_Delta) < e) {
		if (Dot(V_Delta, N_Delta) < 0) {
			for (int j = 0; j <= 2; j++) {
					N.particle[i][1][j] = -Kr * N.particle[i][1][j];
				}
			}
	}
}

void Physics::Contact(int i) { // 접촉 계산
	float X_Delta[3] = { 0,0,0 };
	float N_Delta[3] = { 0,0,0 };
	float V_Delta[3] = { 0,0,0 };
	if (N.particle[i][0][1] <= 0) {
		N_Delta[1] = 1;
		for (int k = 0; k <= 2; k++) {
			V_Delta[k] = N.particle[i][0][k];
			if (k != 0) {
				X_Delta[k] = N.particle[i][0][k];
			}
		}
	}
	if (sqrt(pow(Dot(X_Delta, N_Delta), 2)) < e) {
		if (fabs(Dot(V_Delta, N_Delta)) < e) {
			N.particle[i][2][1] = 0;
		}
	}
}

