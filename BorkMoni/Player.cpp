#include "Player.h"
#include <iostream>
#include <vector>


using namespace std;


Player::Player(const char* title, const char* description, Room* room) : Creature(title, description, room)
{
	type = PLAYER;
}


Player::~Player()
{
}


void Player::Look(string args) const
{
	Room* rum = (Room*)parent;
	rum->Look();


	/*cout << "\n" << this->name << "\n";
	cout << this->description << "\n";*/
}

void Player::Move(string args)
{
	
	for (auto var : parent->childEntities)
	{
		if (var->type == EXIT)
		{
			Exit* et = (Exit*)var;
			
			if (et->name == args && parent == var->parent) 
			{

				if (et->locked)
				{
					cout << "That exit is locked.\n";
					return;
				}

				//Si encontramos una salida y es la dirección correcta, borramos el child player de roomX
				//Asignar nuevo parent a player
				cout << "You take direction " << et->GetNameFrom((Room*)parent) << "...\n";

				Entity* aux = (et->GetDestinationFrom((Room*)parent));
				ChangeParent(aux);

				return;
			}
			else if (et->opposite_name == args && ((Room*)parent) == et->destination)
			{
				if (et->locked)
				{
					cout << "That exit is locked.\n";
					return;
				}

				//Si encontramos una salida y es la dirección correcta, borramos el child player de roomX
				//Asignar nuevo parent a player
				cout << "You take direction " << et->GetNameFrom((Room*)parent) << "...\n";

				Entity* aux = (et->GetDestinationFrom((Room*)parent));
				ChangeParent(aux);

				return;
			}
		}
	}
	cout << "There is no exit at '" << args << "'.\n";
}

void Player::Take(string item, string itemContainer)
{
	if (!itemContainer.size())
	{
		for (auto var : parent->childEntities)
		{
			if (var->type == ITEM)
			{
				//Item* it = (Item*)var;

				if (ToLowerCase(var->name) == item)
				{
					cout << "You take " << var->name << ".\n";
					var->ChangeParent(this);
					return;
				}
			}
		}
		cout << "There is no item here with that name.\n";
		return;
	}
	else if (item != itemContainer)
	{
		for (auto con : this->childEntities)
		{
			if (con->type == ITEM && ToLowerCase(con->name) == itemContainer)
			{
				if (!((Item*)con)->closed)
				{
					for (auto it : con->childEntities)
					{
						if (it->type == ITEM && ToLowerCase(it->name) == item)
						{
							cout << "You take " << it->name << " from " << con->name << ".\n";
							it->ChangeParent(this);
							return;						
						}
					}
					cout << "The item " << item << " is not in "<< itemContainer << ".\n";
					return;
				}
				else
				{
					cout << "The item " << itemContainer << " is closed.\n";
					return;
				}
			}
		}
		cout << "You don't have " << itemContainer << " in your inventory.\n";
		return;
	}
	cout << "You can't take " << item << " from " << itemContainer << ".\n";
}

void Player::Drop(string itemDropped, string itemContainer)
{
	if (!itemContainer.size())
	{
		for (auto var : this->childEntities)
		{
			if (var->type == ITEM)
			{
				//Item* it = (Item*)var;

				if (ToLowerCase(var->name) == itemDropped)
				{
					cout << "You drop " << var->name << ".\n";
					var->ChangeParent(parent);
					return;
				}
			}
		}
		cout << "You don't have that item in your inventory.\n";
		return;
	}
	else if (itemDropped != itemContainer)
	{
		for (auto var : this->childEntities)
		{
			if (var->type == ITEM && ToLowerCase(var->name) == itemDropped)
			{
				for (auto con : this->childEntities)
				{
					if (con->type == ITEM && ToLowerCase(con->name) == itemContainer)
					{
						if (((Item*)con)->item_type == GENERIC)
						{
							cout << "You drop " << var->name << " into " << con->name << ".\n";
							var->ChangeParent(con);
							return;
						}
						else
						{
							cout << "You can't put " << var->name << " into " << con->name << ".\n";
							return;
						}
					}
				}
				cout << "You don't have " << itemContainer << " in your inventory.\n";
				return;
			}
		}
		cout << "You don't have " << itemDropped << " in your inventory.\n";
		return;
	}
	cout << "You can't put " << itemDropped << " into " << itemContainer << ".\n";
}

void Player::Use(string usableO, string destinationO)
{
	//Player deberá tener los dos objetos en el inventario
	for (auto invenUsa : this->childEntities)
	{
		if (ToLowerCase(invenUsa->name) == usableO && invenUsa->type == ITEM)
		{
			for (auto invenDest : this->childEntities)
			{
				if (ToLowerCase(invenDest->name) == destinationO)
				{
					if (((Item*)invenDest)->usable == invenUsa) 
					{
						if (((Item*)invenDest)->closed)
						{
							cout << "You use " << usableO << " in " << destinationO << "...\n";
							((Item*)invenDest)->closed = false;
							invenDest->Look();
							return;
						}
						else
						{
							cout << "The " << usableO << " can not be used in " << destinationO << "...\n";
							return;
						}
					}
					else
					{
						cout << "The " << usableO << " can not be used in " << destinationO << "...\n";
						return;
					}
				}
			}
			cout << "The " << destinationO << " can not be found in your inventory...\n";
			return;
		}
	}

	cout << "The " << usableO << " can not be found in your inventory...\n";
	return;
	//Player deberá tener el objeto usable en el inventario pero el destinatario debe estar en la misma sala
	/*for (auto var : parent->childEntities)
	{
	}*/
}

void Player::Inventory()
{
	if (this->childEntities.size() == 0)
	{
		cout << "You search in your pockets and find nothing.\n";
		return;
	}

	for (auto item : this->childEntities)
	{
		if (((Item*)item)->item_type == WEAPON && this->weapon == ((Item*)item))
			cout << "\n" << item->name << " (as weapon)" << "\n";
		else if (((Item*)item)->item_type == ARMOUR && this->armour == ((Item*)item))
			cout << "\n" << item->name << " (as armour)" << "\n";
		else
			cout << "\n" << item->name << "\n";
	}
}

void Player::Give(string item, string destinationNPC)
{
	for (auto invenItem : this->childEntities)
	{
		if (ToLowerCase(invenItem->name) == item && invenItem->type == ITEM)
		{
			for (auto npc : parent->childEntities)
			{
				if (ToLowerCase(npc->name) == destinationNPC)
				{
					if (ToLowerCase(invenItem->name) == "rum" && ToLowerCase(npc->name) == "fisherman")
					{
						invenItem->ChangeParent(NULL);
						((Creature*)npc)->hit_points = 0;
						cout << "You give '" << invenItem->name << "' to " << npc->name << ".\n";
						cout << "The '" << npc->name << "' starts to drink " << invenItem->name << "...\n";
						cout << "The '" << npc->name << "' chokes and dies.\n";
						return;
					}
					else
					{
						cout << "You can't give '" << item << "' to " << npc->name << ".\n";
						return;
					}
				}
			}
			cout << "'" << destinationNPC << "' is not in this room.\n";
			return;
		}
	}
	cout << "'" << item << "' not found in your inventory.\n";

	return;

}

void Player::Loot(string args)
{
	for (auto npc : parent->childEntities)
	{
		if (npc->type == NPC && ((Creature*)npc)->hit_points <= 0 && ToLowerCase(npc->name) == args)
		{
			for (auto item : npc->childEntities)
			{
				cout << "You loot " << item->name << ".\n";
				item->ChangeParent(this);
			}
			return;
		}
	}
	cout << "You can't loot " << args <<".\n";
}

void Player::Equip(string item)
{
	for (auto invenItem : this->childEntities)
	{
		if (ToLowerCase(invenItem->name) == item && invenItem->type == ITEM)
		{
			if (((Item*)invenItem)->item_type == WEAPON)
			{
				this->weapon = ((Item*)invenItem);
				cout << "You equip " << item << " as your weapon.\n";
				return;
			}
			else if (((Item*)invenItem)->item_type == ARMOUR)
			{
				this->armour = ((Item*)invenItem);
				cout << "You equip " << item << " as your armour.\n";
				return;
			}
			cout << "You cannot equip " << item << ".\n";
			return;
		}
	}
	cout << "The " << item << " is not in your inventory.\n";
}

bool Player::Attack(string enemy) 
{
	if (!this->weapon) 
	{
		cout << "You can't attack without a weapon equipped.\n";
		return false;
	}

	((Creature*)this)->Attack(enemy);
	((Creature*)this)->ReceiveAttack(enemy);
	if (((Creature*)this)->hit_points <= 0)
	{
		cout << "Your life ends here!! BAD ENDING\n";
		return true;
	}
	return false;
}

void Player::Unlock(string exit, string item)
{
	for (auto i : this->childEntities)
	{
		if (ToLowerCase(i->name) == item && i->type == ITEM)
		{
			for (auto e : parent->childEntities)
			{
				if (ToLowerCase(e->name) == exit)
				{
					if (((Exit*)e)->key == i)
					{
						if (((Exit*)e)->locked)
						{
							cout << "You unlock " << exit << " with " << item << "...\n";
							((Exit*)e)->locked = false;
							return;
						}
						else
						{
							cout << "The exit " << exit << " is already open.\n";
							return;
						}
					}
					else
					{
						cout << "The " << item << " can not unlock exit " << exit << "...\n";
						return;
					}
				}
			}
			cout << "The " << exit << " can not be found in this room...\n";
			return;
		}
	}
	cout << "The " << item << " can not be found in your inventory...\n";
}

bool Player::Drink(string strong0)
{
	for (auto i : this->childEntities)
	{
		if (ToLowerCase(i->name) == strong0 && i->type == ITEM)
		{
			if (i->name == "Potion")
			{
				cout << "Congratulations!! You win!!\n";
				return true;
			}
			else if (i->name == "Rum")
			{
				cout << "Oh no, you got drunk!! That wasn't the eternal life potion!! BAD ENDING\n";
				return true;
			}
			cout << "\nYou can't drink '" << i->name << "'.\n";
		}
	}
	cout << "The " << strong0 << " can not be found in your inventory...\n";
}