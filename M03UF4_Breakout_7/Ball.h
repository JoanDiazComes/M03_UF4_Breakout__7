#pragma once
#include <Vector>
#include "Vector2.h"
#include "Brick.h"
#include "Pad.h"
#include "Wall.h"

#define LAST_WALL 30

class Ball
{
public:
	Ball(Vector2 pos, Vector2 dir, int dmg);
	void Bounce(Vector2 normal);
	void Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pads);
	int GetDamage();
	Vector2 GetDirection();
	Vector2 GetPosition();
	void Render();

private:
	Vector2 position;
	Vector2 direction;
	int damage;
};

