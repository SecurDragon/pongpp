#include "GameObject.hpp"

GameObject::GameObject(float x, float y, float width, float height, float velocity, Vec2f const& direction) :
	_shape(x, y, width, height), _direction(direction), _velocity(velocity) {}

void GameObject::draw(Renderer& rdr) const {
	rdr.draw(_shape);
}

void GameObject::setDirection(Vec2f const& new_direction) {
	_direction = new_direction;
}

void GameObject::setVelocity(float new_velocity) {
	_velocity = new_velocity;
}

float GameObject::getVelocity() const {
	return _velocity;
}

Vec2f GameObject::getDirection() const {
	return _direction;
}

Rectangle GameObject::getRect() const {
	return _shape;
}

void GameObject::setPosition(float x, float y) {
	_shape.x = x;
	_shape.y = y;
}
