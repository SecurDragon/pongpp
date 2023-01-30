#include "Screen.hpp"

Screen::~Screen() {
	for (auto obj : _objects)
		delete obj;
}

void Screen::draw(const Renderer& renderer) const {
	for (const sf::Drawable* obj : _objects)
		renderer.draw(*obj);
}

Screen& Screen::add(sf::Drawable* object) {
	_objects.push_back(object);
	return *this;
}
