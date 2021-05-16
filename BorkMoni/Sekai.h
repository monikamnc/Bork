#pragma once

#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include "Room.h"
#include "Entity.h"
#include "Creature.h"
#include "Player.h"

using namespace std;

class Sekai
{

public:

	Sekai();
	~Sekai();

	bool GameLogic(vector<string> args);
	//bool isDead();
	bool youWin;
	Player* player;
	vector<Entity*> entities;
};

