#ifndef _SCREEN_FACTORY_H_
#define _SCREEN_FACTORY_H_

#include "Screen.hpp"

class ScreenFactory {
public:
	static Screen* getMainMenuScreen(sf::Font const& font, sf::Vector2f const& screen_size);
	static Screen* getWinMenuScreen(sf::Font const& font, sf::Vector2f const& screen_size, int playerID);
	static Screen* getInGameMenu(sf::Font const& font, sf::Vector2f const& screen_size);
};

#endif //_SCREEN_FACTORY_H_
