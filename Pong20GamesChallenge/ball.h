#pragma once
#include <raylib.h>
#include <functional>
#include <iostream>

class Ball
{
private:

	Vector2 speed;
	Vector2 position;
	float radius = 4;
	bool isHit;
	void reset();


public:

	std::function<void()> OnRightGoal;
	std::function<void()> OnLeftGoal;

	void SetIsHit(bool isHit);
	Vector2 GetPosition();
	float GetRadius();
	void Draw();
	void Move();
	void BounceY();
	void BounceX();
	Ball();
};
