#ifndef _AI_CONTROLLER_
#define _AI_CONTROLLER_

#include "../controllers/Controller.hpp"

class AIController :
		public Controller {
private:
	float _min_x;
	float _max_x;
	float _height;

public:
	AIController(float height, float minX, float maxX) : _min_x(minX), _max_x(maxX), _height(height) {}
	void update(Paddle& paddle, Ball const& ball) override;
};

#endif //_AI_CONTROLLER_
