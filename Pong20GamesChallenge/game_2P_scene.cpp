#include <string>
#include "game_2P_scene.h"
#include "player.h"
#include "ball.h"
#include "game.h"
#include "main_menu.h"

Game2PScene::Game2PScene() {
	p1 = new Player(50);
	p2 = new Player(GetScreenWidth() - 60);
	b = new Ball();

	b->OnLeftGoal = std::bind(&Player::IncreaseScore, p2);
	b->OnRightGoal = std::bind(&Player::IncreaseScore, p1);
}

Game2PScene::~Game2PScene()
{
	delete p1;
	delete p2;
	delete b;
}

void Game2PScene::Physics() {
	if (CheckCollisionCircleRec(b->GetPosition(), b->GetRadius(), p1->GetRectangle()) || CheckCollisionCircleRec(b->GetPosition(), b->GetRadius(), p2->GetRectangle())) {
		b->BounceX();
		b->SetIsHit(true);
	}
	else {
		b->SetIsHit(false);
	}
}

void Game2PScene::Input() {
	
	this->p1->Move(KEY_S, KEY_W);
	b->Move();
	this->p2->Move(KEY_DOWN, KEY_UP);

	if (IsKeyPressed(KEY_R)) {
		Game::ChangeScene(new MainMenu());
	}

}

void Game2PScene::Draw() {
	ClearBackground(BLACK);
	this->p1->Draw();

	DrawText("Press R to restart", 0, GetScreenHeight() - 10, 10, WHITE);

	std::string p1Score = std::to_string(p1->GetScore());
	std::string p2Score = std::to_string(p2->GetScore());
	float halfScreen = GetScreenWidth() / 2.0;

	DrawText(p1Score.c_str(), halfScreen - MeasureText(p1Score.c_str(), 70) - 50, 50, 50, WHITE);
	DrawText(p2Score.c_str(), halfScreen + 50, 50, 50, WHITE);

	for (int i = 0; i < GetScreenHeight(); i += 10) {
		DrawLine(GetScreenWidth() / 2, i, GetScreenWidth() / 2, i + 5, WHITE);
	}
	b->Draw();
	this->p2->Draw();

}

