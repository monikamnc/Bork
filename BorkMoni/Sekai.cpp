#include "Sekai.h"
#include "Globals.h"

// ----------------------------------------------------
Sekai::Sekai()
{

	youWin = false;

	// Rooms ----
	Room* seashore = new Room ("Seashore", "Lovely sun rises and touch your skin.");
	Room* fisherH = new Room("Fisherman's House", "Oldie house that smells musty and salt.");
	Room* river = new Room("River", "The sound of the running water relaxes you.");
	//Room* sea = new Room("Sea", "It seems someone is watching you under the water.");
	Room* ship = new Room("Ship - Main Deck", "It seems it was an abandoned ship.");
	Room* gunDeck = new Room("Ship - Gun Deck", "Plenty of guns and cansons are surrounded.");
	Room* orlopDeck = new Room("Ship - Orlop Deck", "It seems someone is watching you under the water.");


	Exit* seashoreToFisherH = new Exit("north", "south", "Promenade", seashore, fisherH);
	Exit* fisherHToRiver = new Exit("west", "east", "Grass Path", fisherH, river);
	//Exit* seashoreToSea = new Exit("south", "north", "Let's Swim", seashore, sea);
	Exit* seashoreToShip = new Exit("east", "west", "Wellcome on Board", seashore, ship);
	Exit* shipToGun = new Exit("down", "up", "Wellcome on Board", ship, gunDeck);
	Exit* gunToOrlop = new Exit("down", "up", "Wellcome on Board", gunDeck, orlopDeck);

	//seashoreToSea->locked = true;
	seashoreToShip->locked = true;

	entities.push_back(seashore);
	entities.push_back(fisherH);
	entities.push_back(river);


	entities.push_back(seashoreToFisherH);
	entities.push_back(fisherHToRiver);
	//entities.push_back(seashoreToSea);
	entities.push_back(seashoreToShip);
	entities.push_back(shipToGun);
	entities.push_back(gunToOrlop);


	// Creatures ----
	Creature* fisherman = new Creature("Fisherman", "It's Tim, the alcoholic fisherman.", river);
	Creature* trees = new Creature("Trees", "It seems that are alive, probably.", river);
	Creature* skeleton = new Creature("Skeleton", "Doesn't look good.", orlopDeck);
	fisherman->hit_points = 50;
	trees->hit_points = 10;
	skeleton->hit_points = 30;

	entities.push_back(fisherman);
	entities.push_back(trees);
	entities.push_back(skeleton);

	// Items -----
	Item* box = new Item("Box", "Can contain something useful. It has a tiny hole...", fisherH, true);
	Item* ladder = new Item("Ladder", "Now you can reach new heighs.", trees, false);
	Item* tiny = new Item("Key", "Tiny key, may enter small holes.", fisherman, false);
	Item* potion = new Item("Potion", "Crystal glass full of a strange liquid.", skeleton, false);
	Item* rum = new Item("Rum", "A glass bottle. You can read in a ugly sticker the word 'Rum'.", seashore, false);
	box->usable = tiny;
	seashoreToShip->key = ladder;

	Item* axe = new Item("Axe", "A simple axe, looks sharp.", box, false, WEAPON);
	axe->min_value = 1;
	axe->max_value = 3;

	Item* rod = new Item("Rod", "A fishing rod, looks worn out.", fisherman, false, WEAPON);
	rod->min_value = 1;
	rod->max_value = 3;
	//fisherman->AutoEquip();

	Item* bone = new Item("Bone", "A bone from the leg of the skeleton.", skeleton, false, WEAPON);
	bone->min_value = 4;
	bone->max_value = 7;
	//skeleton->AutoEquip();

	Item* gun = new Item("Gun", "A rusty gun that still has some ammunition.", gunDeck, false, WEAPON);
	gun->min_value = 4;
	gun->max_value = 7;

	Item* shield = new Item("Shield", "An old wooden shield.", ship, false, ARMOUR);
	shield->min_value = 5;
	shield->max_value = 7;

	entities.push_back(ladder);
	entities.push_back(axe);
	entities.push_back(rod);
	entities.push_back(bone);
	entities.push_back(gun);
	entities.push_back(shield);


	// Player ----
	player = new Player("Hero", "You are an awesome adventurer!", seashore);
	player->hit_points = 25;

	entities.push_back(player);

}

Sekai::~Sekai()
{

	entities.clear();
}

bool Sekai::GameLogic(vector<string> args)
{
	bool ret = true;

	for (auto& f : args)
	{

		f = ToLowerCase(f);
	}

	if (args.size() == 1)
	{
		if (args[0] == "look")
		{
			player->Look(args[0]);
		}
		else if (args[0] == "north")
		{
			player->Move(args[0]);
		}
		else if (args[0] == "south")
		{
			player->Move(args[0]);
		}
		else if (args[0] == "east")
		{
			player->Move(args[0]);
		}
		else if (args[0] == "west")
		{
			player->Move(args[0]);
		}
	}
	else if (args.size() == 2)
	{
		if (args[0] == "take")
		{
			player->Take(args[1]);
		}
		else if (args[0] == "drop")
		{
			player->Drop(args[1]);
		}
	}

	return ret;
}
