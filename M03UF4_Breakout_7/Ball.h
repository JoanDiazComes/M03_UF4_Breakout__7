#pragma once
#include <Vector>
#include "Vector2.h"
#include "Brick.h"
#include "Pad.h"
#include "Wall.h"


class Ball
{
public:
	Ball(Vector2 pos, Vector2 dir, int dmg)
		: position(pos), direction(dir), damage(dmg) {}
	void Bounce(Vector2 normal);
	void Update(std::vector<Wall> walls, std::vector<Brick> bricks[], Pad pads[]);
	int GetDamage() { return damage; }
	Vector2 GetDirection() { return direction; }
	Vector2 GetPosition() { return position; }
	void Render() {
		ConsoleXY(position.x, position.y);
		std::cout << "@";
	}

private:
	Vector2 position;
	Vector2 direction;
	int damage;
};

