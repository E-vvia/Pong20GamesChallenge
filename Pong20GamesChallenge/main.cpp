#include <raylib.h>
#include "game.h"

int main() {

	Game::Init();
	Game::Loop();
	Game::Close();

	return 0;
}