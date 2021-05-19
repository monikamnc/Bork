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


	cout << "\n" << this->name << "\n";
	cout << this->description << "\n";
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
					cout << "\nThat exit is locked.\n";
					return;
				}

				//Si encontramos una salida y es la dirección correcta, borramos el child player de roomX
				//Asignar nuevo parent a player
				cout << "\nYou take direction " << et->GetNameFrom((Room*)parent) << "...\n";

				Entity* aux = (et->GetDestinationFrom((Room*)parent));
				ChangeParent(aux);

				return;
			}
			else if (et->opposite_name == args && ((Room*)parent) == et->destination)
			{
				if (et->locked)
				{
					cout << "\nThat exit is locked.\n";
					return;
				}

				//Si encontramos una salida y es la dirección correcta, borramos el child player de roomX
				//Asignar nuevo parent a player
				cout << "\nYou take direction " << et->GetNameFrom((Room*)parent) << "...\n";

				Entity* aux = (et->GetDestinationFrom((Room*)parent));
				ChangeParent(aux);

				return;
			}
		}
	}
	cout << "\nThere is no exit at '" << args << "'.\n";
}

void Player::Take(string args)
{
	for (auto var : parent->childEntities)
	{
		if (var->type == ITEM)
		{
			//Item* it = (Item*)var;
			
			if (ToLowerCase(var->name) == args)
			{
				cout << "\nYou take " << var->name << ".\n";
				var->ChangeParent(this);
				return;
			}
		}
	}
	cout << "\nThere is no item here with that name.\n";
}

void Player::Drop(string args)
{
	for (auto var : this->childEntities)
	{
		if (var->type == ITEM)
		{
			//Item* it = (Item*)var;

			if (ToLowerCase(var->name) == args)
			{
				cout << "\nYou drop " << var->name << ".\n";
				var->ChangeParent(parent);
				return;
			}
		}
	}
	cout << "\nYou don't have that item in your inventory.\n";
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
							cout << "\nYou use " << usableO << " in " << destinationO << "...\n";
							((Item*)invenDest)->closed = false;
							((Item*)invenDest)->Look();
							return;
						}
						else
						{
							cout << "\nThe " << usableO << " can not be used in " << destinationO << "...\n";
							return;
						}
					}
				}
			}
		}
	}

	cout << "\nThe " << usableO << " can not be found in your inventory...\n";
	return;
	//Player deberá tener el objeto usable en el inventario pero el destinatario debe estar en la misma sala
	/*for (auto var : parent->childEntities)
	{
	}*/
}

void Player::Inventory()
{
	for (auto item : this->childEntities)
	{
		if (((Item*)item)->item_type == WEAPON)
			cout << "\n" << item->name << " (as weapon)" << "\n";
		else if (((Item*)item)->item_type == ARMOUR)
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
						cout << "\nYou give '" << invenItem->name << "' to " << npc->name << ".\n";
						cout << "The '" << npc->name << "' starts to drink " << invenItem->name << "...\n";
						cout << "The '" << npc->name << "' chokes and dies.\n";
						return;
					}
					else
					{
						cout << "\nYou can't give '" << item << "' to " << npc->name << ".\n";
						return;
					}
				}
			}
			cout << "\n '" << destinationNPC << "' is not in this room.\n";
			return;
		}
	}
	cout << "\n '" << item << "' not found in your inventory.\n";

	return;

}