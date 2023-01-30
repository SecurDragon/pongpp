#include "Paddle.hpp"

Paddle::Paddle(float x, float y, float width, float height, float velocity, Vec2f const& direction) :
	GameObject(x, y, width, height, velocity, direction) {}

void Paddle::update() {
	this->_shape.y += this->_direction.y * _velocity;
}
