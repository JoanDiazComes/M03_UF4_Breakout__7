#pragma once
#include "ConsoleControl.h"
#include "Vector2.h"
#include "Wall.h"

class Pad
{
private:
	Vector2 position;
	int width;
public:
	Pad(Vector2 p, int w)
		: position(p), width(w) {}
	int GetWidth();
	Vector2 GetPosition();
	void SetPosition(Vector2 pos);
	void Update(Wall w[]);
	void Render();
};

