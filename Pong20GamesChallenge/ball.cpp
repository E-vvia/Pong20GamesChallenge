#include "ball.h"

void Ball::BounceY()
{
	if (!isHit)
		this->speed.y *= -1;
}

void Ball::BounceX()
{
	if (!isHit)
		this->speed.x *= -1;
}

void Ball::Reset()
{
	this->position.x = GetScreenWidth() / 2.0;
	this->position.y = GetScreenHeight() / 2.0;
	int direction = 0;

	do {

		direction = GetRandomValue(-1, 1);

	} while (direction == 0);

	this->speed.x = 300 * direction;
	this->speed.y = -300 * direction;
}

void Ball::SetIsHit(bool isHit)
{
	this->isHit = isHit;
}

Vector2 Ball::GetPosition()
{
	return this->position;
}

float Ball::GetRadius()
{
	return this->radius;
}

void Ball::Draw()
{
	DrawCircle(this->position.x, this->position.y, this->radius, WHITE);
}

void Ball::Move() {

	this->position.x += this->speed.x * GetFrameTime();
	this->position.y += this->speed.y * GetFrameTime();

	if (this->position.y <= 0) {
		this->BounceY();
	}
	else if (this->position.y >= GetScreenHeight()) {
		this->BounceY();
	}

}

Ball::Ball()
{
	this->Reset();
}
