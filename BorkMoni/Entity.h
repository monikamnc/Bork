#pragma once
#include <string>
#include <vector>

using namespace std;

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
	vector<Entity*> childEntities;
	EntityType type;

	Entity(const string name, const string description, Entity* parent);
	~Entity();

	void Look() const;
	void ChangeParent(Entity* parentNew);
};

