#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>

#include "Level.hpp"
#include "../graphics/Screen.hpp"

class Game {
private:
	Level* _level;
	sf::RenderWindow* _window;
	Renderer* _renderer;
	sf::Font* _font;

	enum class GameStates {
		STATE_MENU,
		STATE_PLAY,
		STATE_RESULTS
	};

	GameStates _state;
	Screen* _current_screen = nullptr;

	static constexpr int cMaxFps = 120;
	static constexpr float cWindowWidth = 800.f;
	static constexpr float cWindowHeight = 600.f;


	static constexpr sf::Keyboard::Key cDefaultKeys[4] = {
		sf::Keyboard::Key::Up,   //Paddle1 keyUp
		sf::Keyboard::Key::Down, //Paddle1 keyDown

		sf::Keyboard::Key::W, //Paddle0 keyUp
		sf::Keyboard::Key::S, //Paddle0 keyDown
	};

public:
	Game();
	void loop();
	~Game();
};


#endif //_GAME_H_
