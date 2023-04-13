#include "Pad.h"
#include <iostream>

void Pad::Render() {
    ConsoleXY(position.x, position.y);
    ConsoleSetColor(ConsoleColor::DARKYELLOW,ConsoleColor::BLACK);
    std::cout << "-";
}


int Pad::GetWidth(){
    return 0;
}

Vector2 Pad::GetPosition(){
    return Vector2();
}

void Pad::SetPosition(Vector2 pos){

}

void Pad::Update(Wall w[]){

}
