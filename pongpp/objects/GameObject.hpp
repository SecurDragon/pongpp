#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "../graphics/Rectangle.hpp"
#include "../graphics/Renderer.hpp"
#include "../graphics/Vec2f.hpp"

class GameObject {
protected:
	Rectangle _shape;
	Vec2f _direction;
	float _velocity;

public:
	GameObject(float x, float y, float width, float height, float velocity, Vec2f const& direction = {0.f, 0.f});
	void draw(Renderer& renderer) const;
	virtual void update() = 0;

	void setDirection(Vec2f const& new_direction);
	void setPosition(float x, float y);
	Vec2f getDirection() const;
	void setVelocity(float velocity);
	float getVelocity() const;
	Rectangle getRect() const;

	virtual ~GameObject() = default;
};

#endif //_GAME_OBJECT_H_
