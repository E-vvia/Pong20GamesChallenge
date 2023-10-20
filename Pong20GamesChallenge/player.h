#pragma once
#include <raylib.h>

class Player {

protected:

	Color color = WHITE;
	float speed = 500;
	int score;
	Rectangle rectangle;

	void MoveUp();
	void MoveDown();

public:

	Player(float posX);
	
	Rectangle GetRectangle();
	int GetScore();

	void Draw();
	virtual void Move(KeyboardKey down, KeyboardKey up);
	void IncreaseScore();
};