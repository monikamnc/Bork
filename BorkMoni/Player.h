#pragma once
#include "Creature.h"
#include "Room.h"
#include <vector>

class Player : public Creature
{

public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Look(string args) const;
	void Move(string args) const;

};

