#pragma once
#include <array>
#include "scene.h"

class Game {

private:
	static const int screenWidth = 800;
	static const int screenHeight = 450;

	Game() {};
	
	static Game* instance;

	void physics();
	void input();
	void draw();

	static Game& getInstance();

	Scene* currentScene = nullptr;

public:

	Game(Game& other) = delete;
	void operator=(const Game&) = delete;

	static void Init();
	static void Loop();
	static void Close();
	static void Exit();
	static void ChangeScene(Scene* newScene);
};
