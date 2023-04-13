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

    Vector2 targetPos = position + direction;

    // Check the walls
    for (auto it = walls.begin(); it != walls.end(); it++) {
        if (it->GetPosition() == position) {


            switch (it->GetType())
            {
            case HORIZONTAL:
                if (it->GetPosition().y == LAST_WALL) {
                   
                    position = Vector2(pads->GetPosition().x, pads->GetPosition().y - 5);
                    direction = Vector2(0, 1);
                    break;
                }
                Bounce(Vector2(1, -1));
                break;
            case VERTICAL:
                Bounce(Vector2(-1, 1));
                break;
            case CORNER:
                Bounce(Vector2(-1, -1));
                break;
            }
        }
    }

    auto brickToDestroy = bricks.end();
    int cont = 0;

    for (auto it = bricks.begin(); it != bricks.end(); it++) {
        if (it->GetPosition() == position) {
            direction.y *= -1;
            brickToDestroy = it;

            break;
        }
        cont++;
    }
    
    if (brickToDestroy != bricks.end()) {
        bricks.erase(brickToDestroy);
    }
    for (int i = 0; i <= pads->GetWidth() * 2; i++) {
        Vector2 padPosition(pads->GetPosition().x - pads->GetWidth() + i, pads->GetPosition().y);
        if (position == padPosition) {
            if (i < pads->GetWidth()) {
                direction.x = -1;
                direction.y = -1;
            }
            else if (i == pads->GetWidth()) {
                direction.x = 0;
                direction.y = -1;
            }
            else {
                direction.x = 1;
                direction.y = -1;
            }

          
        }
    }

    position = position + direction;
}

void Ball::Render() {

   
    ConsoleXY(position.x, position.y);

  
    ConsoleSetColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);

    std::cout << "@";
}