#pragma once
#include "Entity.h"
#include "Room.h"
#include "Globals.h"
using namespace std;

class Room;

class Creature : public Entity
{
public:
	Creature(const string name, const string description, Room* room);
	~Creature();

	void AutoEquip();
	/*virtual*/ void Attack(string enemy);
	/*virtual*/ void ReceiveAttack(string enemy);

	//Variables
	int hit_points;
	Item* weapon;
	Item* armour;
};

