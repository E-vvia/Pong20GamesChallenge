#include "player_ai.h"
#include <raymath.h>


void PlayerAI::determineMovement()
{
	Vector2 ballPosition = this->ball->GetPosition();
	Vector2 centerPosition = Vector2();
	centerPosition.x = this->rectangle.x;
	centerPosition.y = this->rectangle.y + this->rectangle.height / 2;

	Vector2 distance = Vector2Subtract(centerPosition, ballPosition);

	if (distance.x > GetScreenWidth() / 2.0)
	{
		this->movement = NONE;
		return;
	}

	if (distance.y > 1) {
		this->movement = MOVE_UP;
	}
	else if (distance.y < -1) {
		this->movement = MOVE_DOWN;
	}
	else {
		this->movement = NONE;
	}

	this->actionTimer = maxActionTimer;
}

void PlayerAI::Move(KeyboardKey down, KeyboardKey up)
{
	if (this->actionTimer <= 0)
		determineMovement();

	switch (this->movement) {
	case MOVE_UP:
		this->MoveUp();
		break;

	case MOVE_DOWN:
		this->MoveDown();
		break;

	case NONE:
		break;
	}

	this->actionTimer -= GetFrameTime();
}
