#pragma once
#include <iostream>
#include "ConsoleControl.h"
#include "Vector2.h"

enum WallType{VERTICAL, HORIZONTAL, CORNER};

class Wall
{
private:
	Vector2 position;
	WallType type;

public:
	Wall(WallType t, Vector2 p)
		: type(t), position(p) {}
	Vector2 GetPosition() { return position; }
	WallType GetType() { return type; }
	void Render();
};



