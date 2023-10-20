#pragma once
#include <string>
#include "scene.h"


class MainMenu : public Scene {
private:
	static const std::string option1;
	static const std::string option2;
	static const std::string option3;

	int option = 0;
	
	Rectangle startP1;
	Rectangle startP2;
	Rectangle exit;

public:
	void Physics() {};
	void Input();
	void Draw();
};