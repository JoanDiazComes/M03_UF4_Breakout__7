#pragma once
#include <vector>
#include "ConsoleControl.h"
#include "Vector2.h"
#include "Wall.h"

class Pad
{
private:
	Vector2 position;
	int width;
	int life;
public:
	Pad(Vector2 p, int w)
		: position(p), width(w), life(3) {}
	int GetWidth();
	Vector2 GetPosition();
	void SetPosition(Vector2 pos);
	void Update(std::vector<Wall>walls);
	bool CheckingWalls(std::vector<Wall>walls, int direction);
	int Lifes();
	void Render();
};

