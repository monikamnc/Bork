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

void Entity::ChangeParent(Entity* parentNew)
{
	for (int i = 0; i < parent->childEntities.size(); i++)
	{
		/*if (parent->childEntities[i]->type == PLAYER)
		{
			parent->childEntities.erase(parent->childEntities.begin() + i);
			break;
		}*/
		if (parent->childEntities[i] == this)
		{
			parent->childEntities.erase(parent->childEntities.begin() + i);
			break;
		}
	}
	
	parent = parentNew;
	if (parentNew != NULL)
		parent->childEntities.push_back(this);
	
}
