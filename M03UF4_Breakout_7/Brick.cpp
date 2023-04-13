#include "Brick.h"

Brick::Brick(Vector2 p, int h) {
	health = h;
	position = p;
	

}

void Brick::TakeDamage(int amount) {
	health -= amount;
}

Vector2 Brick::GetPosition() {
	return position;
}

int Brick::Gethealth() {
	return health;
}

void Brick::SetPosition(Vector2 p) {
	position = p;
}

void Brick::Render() {
	ConsoleXY(position.x, position.y);

	std::cout << "#";


}
