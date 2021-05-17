#pragma once
using namespace std;

#pragma once
#include <string>
#include <list>


enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	NPC,
	PLAYER
};

class Entity
{
public:
	
	string name;
	string description;
	Entity* parent;
	list<Entity*> childEntities;
	EntityType type;

	Entity(const string name, const string description, Entity* parent);
	~Entity();

	void Look() const;
};

