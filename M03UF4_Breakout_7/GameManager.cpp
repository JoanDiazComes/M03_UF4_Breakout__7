#include "GameManager.h"
#include "Wall.h"
#include "Brick.h"

void GameManager::Update()
{
	switch (currentScene)
	{
	case GameManager::MENU:
		Menu();
		break;
	case GameManager::GAMEPLAY:
		Gameplay();
		break;
	case GameManager::HIGHSCORE:
		Highscore();
		break;
	}
}

void GameManager::Menu() {
	int sleepTime = 16;
	bool keyPressed = false;

	bool pressed1;
	bool pressed2;

	while (!keyPressed)
	{
		std::cout << "Main Menu\n\n";
		std::cout << "Press 1 to play" << std::endl;
		std::cout << "Press 2 to exit" << std::endl;
		
		 pressed1 = GetAsyncKeyState('1') != 0;
		 pressed2 = GetAsyncKeyState('2') != 0;

		 keyPressed = pressed1 || pressed2;
		
		Sleep(sleepTime);
		system("cls");	
	}
	if (pressed1)
		currentScene = Scene::GAMEPLAY;
	else
		isPlaying = false;
}


void GameManager::Gameplay() {
	int sleepTime = 1000;
	bool gameplayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	std::vector<Wall> walls;
	std::vector<Brick> bricks;

	InitGameplay(15, 25, &playerPad, &ball, walls, bricks);

	while (gameplayRunning)
	{
		ball->Update(walls, bricks, playerPad);

		playerPad->Render();

		for (std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++)
		{
			it->Render();
			
		for (std::vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); it++)
			{
				it->Render();
			}
		}

		ball->Render();

		Sleep(sleepTime); 
		system("cls");
	}
	
}



void GameManager::InitGameplay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& brick) {
	
	*p = new Pad(Vector2(width / 2, height / 2 + height / 4), 3);

	w.push_back(Wall(WallType::CORNER, Vector2(0, 0)));
	for(int i = 0; i < width; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, 0)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, 0)));

	for (int i = 0; i < height - 2; i++)
	{
		for (int j = 0; j < 2; j++) {
			w.push_back(Wall(WallType::VERTICAL, Vector2(0 + j * (width - 1), i + 1)));
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j < width - 1; j++)
		{
			brick.push_back(Brick(Vector2(j, i), 1));
		}
	}
	*b = new Ball(Vector2(width / 2, height / 2), Vector2(0,1), 1);
}

void GameManager::Highscore() {

}