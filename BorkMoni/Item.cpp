#include "Item.h"

#include <iostream>

Item::Item(const char* title, const char* description, Entity* parent, bool isClosed, ItemType item_type) : Entity(title, description, parent), usable(NULL), item_type(item_type)
{
	type = ITEM;
	min_value = max_value = 0;
	closed = isClosed;
}


Item::~Item()
{}

void Item::Look() const
{
	cout << "\n" << name << "\n";
	cout << description << "\n";
}