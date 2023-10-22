#pragma once
#include <raylib.h>

class Ball
{
private:

	Vector2 speed;
	Vector2 position;
	float radius = 4;
	bool isHit;

public:

	void SetIsHit(bool isHit);
	Vector2 GetPosition();
	float GetRadius();
	void Draw();
	void Move();
	void Reset();
	void BounceY();
	void BounceX();
	Ball();
};
