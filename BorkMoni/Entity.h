#pragma once
using namespace std;

#include <string>
#include <list>

class Room;

class Entity
{
public:
	
	string name;
	string description;
	Entity* parent;
	list<Entity*> childEntities;

	Entity(const string name, const string description, Entity* parent);
	Entity(const string name, const string description);
	virtual ~Entity();
};

