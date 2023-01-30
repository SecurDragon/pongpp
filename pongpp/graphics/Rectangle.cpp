#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height)
	: x(x), y(y), width(width), height(height) {}

bool Rectangle::collidesWith(Rectangle& other) const {
	bool collisionX = this->x + this->width >= other.x && other.x + other.width >= this->x;
	bool collisionY = this->y + this->height >= other.y && other.y + other.height >= this->y;
	return collisionX && collisionY;
}
