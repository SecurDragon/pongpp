#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "../objects/Ball.hpp"
#include "../objects/Paddle.hpp"
#include "../controllers/Controller.hpp"

class Level {
private:
	Ball* _ball;
	Paddle* _paddles[2];
	Controller* _controllers[2];
	float _width, _height;
	float _paddle_height;
	float _paddle_part_height;

	size_t _score[2] = {0};

	static constexpr float cBallSize = 10.f;
	static constexpr float cBallInitialVelocity = 3.f;
	static constexpr float cPaddleWidth = 20.f;
	static constexpr float cMaxAngle = 60.f;
	static constexpr float cPaddleVelocity = 5.f;
	static constexpr float cColVelocityMultiplier = 0.25f;
	static constexpr size_t cWinPoints = 10;
	static constexpr size_t cPaddleParts = 51;
	static constexpr float cPaddleAnglePerPart = cMaxAngle / (cPaddleParts - 1);
	static constexpr int cPaddleCentralPart = cPaddleParts / 2;

	size_t _ball_colls = 0;
	void resolveCollisions();
	void fixPaddle(Paddle* paddle);
	void resetPaddles();

public:
	Level(float width, float height);
	void setupControllers(Controller* player1_controller, Controller* player2_controller);
	~Level();
	void draw(Renderer& renderer) const;
	int getWonPlayer();
	const size_t (& getScores() const)[2];
	void update();
};

#endif //_LEVEL_H_
