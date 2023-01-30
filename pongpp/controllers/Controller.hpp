#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "../objects/Ball.hpp"
#include "../objects/Paddle.hpp"

class Controller {
public:
	virtual void update(Paddle& paddle, Ball const& ball) = 0;
	virtual ~Controller() = default;
};

#endif //_CONTROLLER_H_
