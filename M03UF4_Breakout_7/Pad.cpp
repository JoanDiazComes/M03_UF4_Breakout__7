#include "Pad.h"

int Pad::GetWidth() {
    return width;
}
Vector2 Pad::GetPosition() {
    return position;
}

void Pad::SetPosition(Vector2 p) {
    position = p;
}

int Pad::Lifes() {
    return life;
}

bool Pad::CheckingWalls(std::vector<Wall>walls, int direction) {

    Vector2 padRight(position.x + width + 1, position.y);
    Vector2 padLeft(position.x - width - 1, position.y);

    for (auto it = walls.begin(); it != walls.end(); it++) {
        if ((it->GetPosition() == padRight && direction == 1) || (it->GetPosition() == padLeft && direction == 0))
            return false;
    }

    return true;
}

void Pad::Update(std::vector<Wall>walls) {

    bool Right;
    bool Left;

    
    Right = GetAsyncKeyState(VK_RIGHT) != 0;
    Left = GetAsyncKeyState(VK_LEFT) != 0;

    
    if (Right) {
        if (CheckingWalls(walls, 1))
            position.x += 1;
    }
    else if (Left) {
        if (CheckingWalls(walls, 0))
            position.x -= 1;
    }
}

void Pad::Render() {
    
    ConsoleXY(position.x, position.y);

    
    std::cout << "-";
    for (int i = 0; i < width; i++) {
        ConsoleXY(position.x + i + 1, position.y);
        std::cout << "-";
        ConsoleXY(position.x - i - 1, position.y);
        std::cout << "-";
    }
}