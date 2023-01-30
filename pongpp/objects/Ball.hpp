#ifndef _BALL_H_
#define _BALL_H_

#include "GameObject.hpp"
#include "../graphics/Vec2f.hpp"

class Ball : public GameObject {
public:
	Ball(float x, float y, float width, float height, float velocity, Vec2f const& direction = {0.f, 0.f});
	void update() override;
};

#endif //_BALL_H_
