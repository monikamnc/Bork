// BorkMoni.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
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
bool notFinished;
Sekai sekaiDeHichiban;

void ChangeState(StateTypeGame _state)
{
	state = _state;
}


//Maquina de Estados
void updateStateMachine()
{
	//timer += Time.deltaTime;

	switch (state) {
	case startGame:

		cout << "\nType something: \n";

		ChangeState(waitingInput);


		break;
	case waitingInput:

		cin >> words;
		

		ChangeState(response);

		break;

	case response:

		if (words == "quit") { ChangeState(finish); break; }
		
		sekaiDeHichiban.GameLogic(words);
		ChangeState(waitingInput);

		break;


	case finish:
		notFinished = false;
		cout << "\nThanks for playing, See ya!\n";
		system("pause");

		break;
	default:
		//Debug.LogError("updateStateMachine: Unvalid state");
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




// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
