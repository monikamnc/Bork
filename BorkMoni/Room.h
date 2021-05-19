#pragma once
#include <string>
#include "Entity.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"


using namespace std;

//class Exit;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

 
	void Look() const;
};

