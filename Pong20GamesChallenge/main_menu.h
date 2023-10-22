#pragma once
#include "scene.h"


class MainMenu : public Scene {
private:
	static const char* option1;
	static const char* option2;
	static const char* option3;

	int option = 0;

	Rectangle startP1;
	Rectangle startP2;
	Rectangle exit;

public:
	void Physics() {};
	void Input();
	void Draw();
};