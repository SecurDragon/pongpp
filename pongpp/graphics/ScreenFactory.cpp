#include "ScreenFactory.hpp"

void transform(sf::Text* text, sf::Vector2f const& position) {
	auto local_bounds = text->getLocalBounds();
	text->setOrigin(0, text->getLocalBounds().height);
	text->setScale(-1.f, 1.f);
	text->rotate(180.f);
	text->setOrigin(local_bounds.width / 2.f, local_bounds.height / 2.f);
	text->setPosition(position);
}

void transform(sf::Shape* shape, sf::Vector2f const& position) {
	auto local_bounds = shape->getLocalBounds();
	shape->setOrigin(0, shape->getLocalBounds().height);
	shape->setScale(-1.f, 1.f);
	shape->rotate(180.f);
	shape->setOrigin(local_bounds.width / 2.f, local_bounds.height / 2.f);
	shape->setPosition(position);
}

Screen* ScreenFactory::getMainMenuScreen(sf::Font const& font, sf::Vector2f const& screen_size) {
	Screen* screen = new Screen();
	sf::Text* logo = new sf::Text("PONG!", font, 72);
	transform(logo, {screen_size.x / 2.f, screen_size.y / 3.f * 2});
	sf::Text* single_player_text = new sf::Text("1 Player", font, 48);
	transform(single_player_text, {screen_size.x / 3, screen_size.y / 3});
	sf::Text* multiplayer_text = new sf::Text("2 Player", font, 48);
	transform(multiplayer_text, {screen_size.x / 3 * 2, screen_size.y / 3});
	screen->add(logo).add(single_player_text).add(multiplayer_text);
	return screen;
}

Screen* ScreenFactory::getWinMenuScreen(sf::Font const& font, sf::Vector2f const& screen_size, int playerID) {
	Screen* screen = new Screen();
	std::string won = "Player " + std::to_string(playerID + 1) + " won!";
	sf::Text* won_plater_text = new sf::Text(won, font, 48);
	sf::Text* restart = new sf::Text("Press SPACE to restart", font, 16);
	transform(restart, {screen_size.x / 2.f, screen_size.y / 4.f});
	transform(won_plater_text, screen_size / 2.f);
	screen->add(won_plater_text).add(restart);
	return screen;
}

Screen* ScreenFactory::getInGameMenu(sf::Font const& font, sf::Vector2f const& screen_size) {
	Screen* screen = new Screen();
	sf::RectangleShape* line = new sf::RectangleShape({2.f, screen_size.y});
	transform(line, screen_size / 2.f);
	screen->add(line);
	return screen;
}
