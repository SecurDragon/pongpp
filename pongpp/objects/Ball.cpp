#include "Ball.hpp"

Ball::Ball(float x, float y, float width, float height, float velocity, Vec2f const& direction) :
	GameObject(x, y, width, height, velocity, direction) {}

void Ball::update() {
	this->_shape.x += this->_direction.x * _velocity;
	this->_shape.y += this->_direction.y * _velocity;
}
