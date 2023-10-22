#include "main_menu.h"
#include "game.h"
#include "game_1P_scene.h"
#include "game_2P_scene.h"

const char* MainMenu::option1 = "1 Player";
const char* MainMenu::option2 = "2 Players";
const char* MainMenu::option3 = "Exit";

void MainMenu::Input()
{
	if (IsKeyPressed(KEY_S)) {
		this->option++;
		if (option >= 3)
			option = 0;
	}
	else if (IsKeyPressed(KEY_W)) {
		this->option--;
		if (option < 0)
			option = 2;
	}

	if (IsKeyPressed(KEY_SPACE)) {
		switch (option) {
		case 0:
			Game::ChangeScene(new Game1PScene());
			break;
		case 1:
			Game::ChangeScene(new Game2PScene());
			break;
		case 2:
			Game::Exit();
			break;
		default:
			break;
		}

	}
}

void MainMenu::Draw()
{
	int textLength1 = MeasureText(option1, 50);
	int textLength2 = MeasureText(option2, 50);
	int textLength3 = MeasureText(option3, 50);
	int halfScreenWidth = GetScreenWidth() / 2;
	int halfScreenHeight = GetScreenHeight() / 2;

	ClearBackground(BLACK);

	if (this->option == 0)
		DrawRectangle(halfScreenWidth - textLength1 / 2 - 5, halfScreenHeight - 85, textLength1 + 10, 60, DARKGRAY);

	DrawRectangleLines(halfScreenWidth - textLength1 / 2 - 5, halfScreenHeight - 85, textLength1 + 10, 60, LIGHTGRAY);
	DrawText(option1, halfScreenWidth - textLength1 / 2, halfScreenHeight - 80, 50, WHITE);

	if (this->option == 1)
		DrawRectangle(halfScreenWidth - textLength2 / 2 - 5, halfScreenHeight - 5, textLength2 + 10, 60, DARKGRAY);

	DrawRectangleLines(halfScreenWidth - textLength2 / 2 - 5, halfScreenHeight - 5, textLength2 + 10, 60, LIGHTGRAY);
	DrawText(option2, halfScreenWidth - textLength2 / 2, halfScreenHeight, 50, WHITE);

	if (this->option == 2)
		DrawRectangle(halfScreenWidth - textLength3 / 2 - 5, halfScreenHeight + 75, textLength3 + 10, 60, DARKGRAY);
	DrawRectangleLines(halfScreenWidth - textLength3 / 2 - 5, halfScreenHeight + 75, textLength3 + 10, 60, LIGHTGRAY);
	DrawText(option3, halfScreenWidth - textLength3 / 2, halfScreenHeight + 80, 50, WHITE);
}


