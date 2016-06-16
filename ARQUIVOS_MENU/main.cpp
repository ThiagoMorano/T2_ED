// Game2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "state_manager.h"
#include "main_menu.h"

state_manager coreState;
bool quitGame = false;

int main()
{
	//creation of the main window

	sf::RenderWindow window(sf::VideoMode(800, 600), "Calouro Inocente");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	
		window.clear();
		coreState.Update();
		coreState.Render();
		window.display();

		if (quitGame) {
			window.close();
		}
		Sleep(3);
	}


    return 0;
}

