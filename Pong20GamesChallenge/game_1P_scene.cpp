#include <string>
#include "game_1P_scene.h"
#include "player.h"
#include "player_ai.h"
#include "ball.h"
#include "game.h"
#include "main_menu.h"

Game1PScene::Game1PScene() {
	p1 = new Player(50);
	b = new Ball();
	p2 = new PlayerAI(GetScreenWidth() - 60, b);

	b->OnLeftGoal = std::bind(&Player::IncreaseScore, p2);
	b->OnRightGoal = std::bind(&Player::IncreaseScore, p1);
}
