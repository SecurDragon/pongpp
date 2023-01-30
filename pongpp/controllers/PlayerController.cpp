#include "PlayerController.hpp"

PlayerController::PlayerController(sf::Keyboard::Key up, sf::Keyboard::Key down)
	: _key_up(up), _key_down(down) {}

void PlayerController::update(Paddle& paddle, Ball const& ball) {
	Vec2f new_direction = {0.f, 0.f};
	if (sf::Keyboard::isKeyPressed(_key_up))
		new_direction.y = 1.f;
	if (sf::Keyboard::isKeyPressed(_key_down))
		new_direction.y = -1.f;

	paddle.setDirection(new_direction);
}
