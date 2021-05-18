#pragma once
#include <string>
#include "Entity.h"


enum ItemType
{
	GENERIC,
	WEAPON,
	ARMOUR
};

class Item : public Entity
{

public:
	Item(const char* name, const char* description, Entity* parent, bool isClosed, ItemType item_type = GENERIC);
	~Item();

	void Look() const;


	//Variables
	int min_value;
	int max_value;
	bool closed;
	Entity* usable;
	ItemType item_type;
};

