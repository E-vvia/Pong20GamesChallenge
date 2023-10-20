#include <raylib.h>
#include <iostream>
#include "player.h"




Player::Player(float posX) {
	this->rectangle.x = posX;
	this->rectangle.y = (GetScreenHeight() / 2.0f) - 30.0f;

	this->rectangle.width = 10;
	this->rectangle.height = 60;

	this->score = 0;
}

Rectangle Player::GetRectangle() {
	return this->rectangle;
}

void Player::Draw() {
	DrawRectangle((int) this->rectangle.x, (int) this->rectangle.y, 10, (int) this->rectangle.height, WHITE);
}

void Player::Move(KeyboardKey down, KeyboardKey up) {

	if (IsKeyDown(up)) {

		this->MoveUp();
	}
	else if (IsKeyDown(down)) {

		this->MoveDown();
	}
}

void Player::MoveUp()
{
	this->rectangle.y -= this->speed * GetFrameTime();

	if (this->rectangle.y < 0) {
		this->rectangle.y = 0;
	}
}

void Player::MoveDown()
{
	this->rectangle.y += this->speed * GetFrameTime();

	if (this->rectangle.y + this->rectangle.height > GetScreenHeight()) {
		this->rectangle.y = GetScreenHeight() - this->rectangle.height;
	}
}

int Player::GetScore() {
	return this->score;
}

void Player::IncreaseScore()
{
	this->score++;
}
