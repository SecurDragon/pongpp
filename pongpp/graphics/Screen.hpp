#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <vector>
#include <SFML/Graphics.hpp>

#include "Renderer.hpp"

class Screen {
private:
	std::vector<sf::Drawable*> _objects;

public:
	Screen() = default;
	~Screen();
	void draw(const Renderer& renderer) const;
	Screen& add(sf::Drawable* object);
};

#endif //_SCREEN_H_
