#pragma once
#include "scene.h"
#include "ball.h"

class Game2PScene : public Scene {
protected:

	Ball* b;

public:

	void Physics();
	void Input();
	void Draw();

	Game2PScene();
	~Game2PScene();
};