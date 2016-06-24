#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "state_manager.h"

class main_menu : public aux_state {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text* quit;
	int selected;
	bool upKey, downKey;
};
#endif // !MAIN_MENU_H
