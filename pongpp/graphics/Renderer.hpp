#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <string>
#include <SFML\Graphics.hpp>

#include "Rectangle.hpp"
#include "Vec2f.hpp"

class Renderer {
private:
	sf::RenderWindow& _window;
	sf::Font _font;

public:
	Renderer(sf::RenderWindow& window, sf::Font& font) : _window(window), _font(font) {}
	void draw(Rectangle const& rectangle) const;
	void draw(sf::Drawable const& object) const;
	void drawText(std::string const& text_string, unsigned font_size, Vec2f const& position) const;
};

#endif //_RENDERER_H_
