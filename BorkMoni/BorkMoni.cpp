#include <iostream>
#include <string>
#include "Globals.h"
#include "Sekai.h"

using namespace std;

enum StateTypeGame {
	startGame,
	waitingInput,
	response,
	finish
};

//StateMachine variables:
StateTypeGame state;

string words;
vector<string> frase;
bool notFinished;
Sekai sekaiDeIchiban;

void ChangeState(StateTypeGame _state)
{
	state = _state;
}


//Maquina de Estados
void updateStateMachine()
{
	string word;
	size_t pos = 0;

	switch (state) {
	case startGame:

		cout << "Welcome to Bork!\n";
		cout << "You have to find and drink the eternal life potion to escape from this universe.\n";
		cout << "--------------------------------------------------------------------------------\n";

		ChangeState(waitingInput);


		break;
	case waitingInput:

		getline(cin, words);

		if (!words.empty()) {
			while ((pos = words.find(" ")) != string::npos) {
				word = words.substr(0, pos);
				frase.push_back(word);
				words.erase(0, pos + 1);
			}

			if (!words.empty())
				frase.push_back(words);
		}

		ChangeState(response);

		break;

	case response:

		if (words == "quit") { ChangeState(finish); break; }
		
		sekaiDeIchiban.GameLogic(frase);
		if(sekaiDeIchiban.youWin) { ChangeState(finish); break; }
		ChangeState(waitingInput);
		frase.clear();
		cout << "\n";
		break;


	case finish:
		notFinished = false;
		cout << "\nThanks for playing, See ya!\n";
		system("pause");

		break;
	default:
		break;
	}
}

int main()
{
	ChangeState(startGame);
	notFinished = true;


	while(notFinished)
	{

		updateStateMachine();

	}

	
}


