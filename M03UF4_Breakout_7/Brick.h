#pragma once
#include "Vector2.h"
#include "ConsoleControl.h"



class Brick {
private: 
	Vector2 position;
	int health;
public:
	Brick(Vector2 p, int h);
	Vector2 GetPosition();
	void SetPosition(Vector2 p);
	int Gethealth();
	void TakeDamage(int amount);
	void Render();
};
