#include "Game.hpp"

#include <chrono>
#include <thread>

#include "../controllers/AIController.hpp"
#include "../controllers/PlayerController.hpp"
#include "../graphics/ScreenFactory.hpp"

Game::Game() {
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG");

	_font = new sf::Font();
	bool loading_result = _font->loadFromFile("resources\\Minecraft.ttf");
	_renderer = new Renderer(*_window, *_font);
	auto view = sf::View({cWindowWidth / 2, cWindowHeight / 2}, {cWindowWidth, -cWindowHeight});
	_window->setView(view);
	_state = GameStates::STATE_MENU;
	_current_screen = ScreenFactory::getMainMenuScreen(*_font, {cWindowWidth, cWindowHeight});
}

void Game::loop() {
	std::string scores_str = " ";

	sf::Clock clock;
	sf::Int32 start = clock.getElapsedTime().asMilliseconds();
	while (_window->isOpen()) {
		sf::Event event;
		while (_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				_window->close();
		}

		if (clock.getElapsedTime().asMilliseconds() - start > 1000.0 / cMaxFps) {
			if (_state == GameStates::STATE_PLAY) {
				_level->update();
				auto scores = _level->getScores();
				scores_str.erase();
				scores_str.append(1, static_cast<char>('0' + scores[1]));
				scores_str.append(2, ' ');
				scores_str.append(1, static_cast<char>('0' + scores[0]));
				int won = _level->getWonPlayer();
				if (won != -1) {
					delete _current_screen;
					_current_screen = nullptr;
					_current_screen = ScreenFactory::getWinMenuScreen(*_font, {cWindowWidth, cWindowHeight}, won);
					_state = GameStates::STATE_RESULTS;
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
				}
			}

			if (_state == GameStates::STATE_MENU) {
				Controller* player2_controller = new PlayerController(cDefaultKeys[0], cDefaultKeys[1]);
				Controller* player1_controller = nullptr;
				bool chosen = false;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
					chosen = true;
					player1_controller = new AIController(cWindowHeight, 0, cWindowWidth / 2);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
					chosen = true;
					player1_controller = new PlayerController(cDefaultKeys[2], cDefaultKeys[3]);
				}
				if (chosen) {
					delete _current_screen;
					_current_screen = nullptr;
					_current_screen = ScreenFactory::getInGameMenu(*_font, {cWindowWidth, cWindowHeight});
					_level = new Level(cWindowWidth, cWindowHeight);
					_level->setupControllers(player1_controller, player2_controller);
					this->_state = GameStates::STATE_PLAY;
				}
			}

			if (_state == GameStates::STATE_RESULTS) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					delete _level;
					delete _current_screen;
					_current_screen = nullptr;
					this->_state = GameStates::STATE_MENU;
					this->_current_screen = ScreenFactory::getMainMenuScreen(*_font, {cWindowWidth, cWindowHeight});
				}
			}

			start = clock.getElapsedTime().asMilliseconds();
		}

		_window->clear();

		if (_current_screen != nullptr)
			_current_screen->draw(*_renderer);

		if (_state == GameStates::STATE_PLAY) {
			_level->draw(*_renderer);
			_renderer->drawText(scores_str, 48, {cWindowWidth / 2, cWindowHeight});
		}

		_window->display();
	}
}

Game::~Game() {
	delete _renderer;
	delete _window;
	delete _level;
	delete _current_screen;
	_current_screen = nullptr;
	delete _font;
}
