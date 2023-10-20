#pragma once
#include <raylib.h>
#include "player.h"
#include "ball.h"


enum AIMove {
	MOVE_UP,
	MOVE_DOWN,
	NONE,
};

class PlayerAI : public Player {

private:
	float actionTimer = 0;
	float maxActionTimer = 0.25;
	Ball* ball;
	AIMove movement = NONE;

	void determineMovement();
public:

	PlayerAI(float posX, Ball* ball ) : Player(posX) 
	{
		this->ball = ball;
	};

	void Move(KeyboardKey down, KeyboardKey up);
};