#ifndef _PLAYER_CONTROLLER_H_
#define _PLAYER_CONTROLLER_H_

#include "Controller.hpp"

class PlayerController :
		public Controller {
private:
	sf::Keyboard::Key _key_up;
	sf::Keyboard::Key _key_down;

public:
	PlayerController(sf::Keyboard::Key up, sf::Keyboard::Key down);
	void update(Paddle& paddle, Ball const& ball) override;
};

#endif //_PLAYER_CONTROLLER_H_
