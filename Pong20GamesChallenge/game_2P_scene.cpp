#include "game_2P_scene.h"
#include "player.h"
#include "ball.h"
#include "game.h"
#include "main_menu.h"

Game2PScene::Game2PScene() {
	p1 = new Player(50);
	p2 = new Player(GetScreenWidth() - 60);
	b = new Ball();
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

	if (b->GetPosition().x >= GetScreenWidth()) {
		b->Reset();
		p1->IncreaseScore();
	}

	if (b->GetPosition().x <= 0) {
		b->Reset();
		p2->IncreaseScore();
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

	const char* p1Score = TextFormat("%d", p1->GetScore());
	const char* p2Score = TextFormat("%d", p2->GetScore());

	float halfScreen = GetScreenWidth() / 2.0;

	DrawText(p1Score, halfScreen - MeasureText(p1Score, 70) - 50, 50, 50, WHITE);
	DrawText(p2Score, halfScreen + 50, 50, 50, WHITE);

	for (int i = 0; i < GetScreenHeight(); i += 10) {
		DrawLine(GetScreenWidth() / 2, i, GetScreenWidth() / 2, i + 5, WHITE);
	}
	b->Draw();
	this->p2->Draw();

}

