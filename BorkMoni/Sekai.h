#pragma once

#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include "Room.h"
#include "Entity.h"
#include "Creature.h"

using namespace std;

class Sekai
{

public:

	Sekai();
	~Sekai();

	bool GameLogic(string args);
	//bool isDead();
	bool youWin;
	vector<Room> heya;

private:


	//Player* player;

};

