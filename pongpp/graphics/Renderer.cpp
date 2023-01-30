#include "Renderer.hpp"

void Renderer::draw(Rectangle const& rectangle) const {
	sf::RectangleShape shape;
	shape.setSize({rectangle.width, rectangle.height});
	shape.setPosition(rectangle.x, rectangle.y);
	shape.setFillColor(sf::Color::White);
	_window.draw(shape);
}

void Renderer::draw(sf::Drawable const& object) const { _window.draw(object); }

void Renderer::drawText(std::string const& text_string, unsigned font_size, Vec2f const& position) const {
	sf::Text text(text_string, _font, font_size);
	const auto local_bounds = text.getLocalBounds();
	text.setOrigin(0, text.getLocalBounds().height);
	text.setScale(-1.f, 1.f);
	text.rotate(180.f);
	text.setOrigin(local_bounds.width / 2.f, local_bounds.height / 2.f);
	text.setPosition({position.x, position.y - static_cast<float>(font_size) / 2.f});
	_window.draw(text);
}
