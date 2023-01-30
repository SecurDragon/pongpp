#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "../objects/GameObject.hpp"
#include "../graphics/Vec2f.hpp"

class Paddle : public GameObject {
public:
	Paddle(float x, float y, float width, float height, float velocity, Vec2f const& direction = {0.f, 0.f});
	void update() override;
};

#endif //_PADDLE_H_
