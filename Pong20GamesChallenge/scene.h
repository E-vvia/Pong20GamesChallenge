#pragma once
#include "player.h"

class Scene {
protected:
	Player* p1;
	Player* p2;

public:
	virtual void Physics() = 0;
	virtual void Input() = 0;
	virtual void Draw() = 0;
};