#include "Ball.h"

Ball::Ball(Vector2 p, Vector2 dir, int dmg) {
    position = p;
    direction = dir;
    damage = dmg;
}

void Ball::Bounce(Vector2 normal) {

    direction = direction + normal;
}

int Ball::GetDamage() {
    return damage;
}
Vector2 Ball::GetDirection() {
    return direction;
}
Vector2 Ball::GetPosition() {
    return position;
}


void Ball::Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pads) {


}

void Ball::Render() {

   
    ConsoleXY(position.x, position.y);

  
    ConsoleSetColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);

    std::cout << "@";
}