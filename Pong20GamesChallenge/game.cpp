#include <raylib.h>
#include <iostream>
#include "game.h"
#include "main_menu.h"

Game* Game::instance = nullptr;
static bool exitGame = false;

void Game::Init() {

	InitWindow(getInstance().screenWidth, getInstance().screenHeight, "Pong! 20 Games challenge");

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

	getInstance().currentScene = new MainMenu();
}

Game& Game::getInstance() {
	if (instance == nullptr) {
		instance = new Game();
	}

	return *instance;
}

void Game::physics() {
	currentScene->Physics();
}

void Game::input() {
	currentScene->Input();
}

void Game::draw() {
	BeginDrawing();

	currentScene->Draw();

	EndDrawing();
}

void Game::Loop() {
	while (!WindowShouldClose() && !exitGame) {
		getInstance().input();
		getInstance().physics();
		getInstance().draw();
	}
}

void Game::Close() {

	delete getInstance().currentScene;

	CloseWindow();

	delete &getInstance();
}

void Game::Exit() {
	exitGame = true;
}

void Game::ChangeScene(Scene* newScene) {
	delete getInstance().currentScene;

	getInstance().currentScene = newScene;
}