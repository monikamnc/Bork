#include "Sekai.h"

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

	// Player ----
	player = new Player("Hero", "You are an awesome adventurer!", seashore);
	player->hit_points = 25;

	entities.push_back(player);

}

// ----------------------------------------------------
Sekai::~Sekai()
{

	entities.clear();
}

string Sekai::ToLowerCase(string s) 
{
	for (auto& c : s)
	{
		c = tolower(c);
	}
	return s;
}

// ----------------------------------------------------
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
		}else if (args[0] == "north"){
			player->Move(args[0]);
		}else if (args[0] == "south"){
			player->Move(args[0]);
		}else if (args[0] == "east") {
			player->Move(args[0]);
		}else if (args[0] == "west") {
			player->Move(args[0]);
		}
	}
	if (args.size() == 2)
	{
		if (args[0] == "take") {
			player->Take(args[1]);
		}
	}

	return ret;
}
