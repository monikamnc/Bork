#include "Entity.h"

#include <iostream>

Entity::Entity(const string name, const string description, Entity* parent) :
	name(name), description(description), parent(parent)
{
	
	if (parent != NULL) {
		parent->childEntities.push_back(this);
	}
}

Entity::~Entity()
{
}

void Entity::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
}
