#include "Level.hpp"

static constexpr int cMaxRndAngleDeg = 30;
static constexpr float cPI = 3.1415926f;

float deg_to_rad(float deg) {
	return deg * cPI / 180.f;
}

float random_angle() {
	float rndAngle = static_cast<float>(rand() % cMaxRndAngleDeg);
	if (rand() % 2)
		rndAngle = -rndAngle;

	return deg_to_rad(rndAngle);
}

int sgn(float x) { return x < 0 ? -1 : 1; }

Level::Level(float width, float height): _controllers{nullptr} {
	_width = width;
	_height = height;

	_paddle_height = height / 6;
	_paddle_part_height = _paddle_height / cPaddleParts;

	float angle = random_angle();

	_ball = new Ball(width / 2, height / 2, cBallSize, cBallSize, cBallInitialVelocity, {cos(angle), sin(angle)});
	_paddles[0] = new Paddle(0, height / 2 - _paddle_height / 2, cPaddleWidth, _paddle_height, cPaddleVelocity);
	_paddles[1] = new Paddle(width - cPaddleWidth, height / 2 - _paddle_height / 2, cPaddleWidth, _paddle_height,
	                         cPaddleVelocity);
}

void Level::setupControllers(Controller* player1_controller, Controller* player2_controller) {
	_controllers[0] = player1_controller;
	_controllers[1] = player2_controller;
}

Level::~Level() {
	delete _ball;
	for (int i = 0; i < 2; ++i) {
		delete _paddles[i];
		delete _controllers[i];
	}
}

void Level::draw(Renderer& renderer) const {
	_ball->draw(renderer);
	_paddles[0]->draw(renderer);
	_paddles[1]->draw(renderer);
}

int Level::getWonPlayer() {
	if (_score[0] == cWinPoints)
		return 1;
	if (_score[1] == cWinPoints)
		return 0;
	return -1;
}

const size_t (& Level::getScores() const)[2] { return this->_score; }

void Level::update() {
	for (size_t i = 0; i < 2; ++i) {
		_controllers[i]->update(*_paddles[i], *_ball);
		_paddles[i]->update();
	}
	_ball->update();

	this->resolveCollisions();
}

void Level::resolveCollisions() {
	this->fixPaddle(_paddles[0]);
	this->fixPaddle(_paddles[1]);

	Rectangle ball = _ball->getRect();
	Rectangle paddle0 = _paddles[0]->getRect();
	Rectangle paddle1 = _paddles[1]->getRect();

	Vec2f new_direction = _ball->getDirection();

	if (ball.x <= 0 || ball.x + ball.width >= _width) {
		_ball_colls = 0;
		_ball->setPosition(_width / 2, _height / 2);
		this->resetPaddles();
		float angle = random_angle();

		new_direction = {cos(angle), sin(angle)};
		if (ball.x <= 0)
			++_score[0];
		else
			++_score[1];
	}
	if (ball.y <= 0 || ball.y + ball.height >= _height) {
		new_direction.y *= -1;
		++_ball_colls;
	}

	if (ball.collidesWith(paddle0)) {
		_ball->setPosition(cPaddleWidth * 3 / 2, ball.y);

		float collision_origin = paddle0.y + paddle0.height;
		float collision_point = collision_origin - ball.y;
		int collided_part = static_cast<int>(collision_point / _paddle_part_height);
		int sign = collided_part < cPaddleCentralPart ? 1 : -1;
		float result_angle = deg_to_rad(cPaddleAnglePerPart * (cPaddleCentralPart - collided_part));

		new_direction = {cos(result_angle), sin(result_angle)};
		++_ball_colls;
	}
	if (ball.collidesWith(paddle1)) {
		_ball->setPosition(_width - cPaddleWidth * 3 / 2, ball.y);

		float collision_origin = paddle1.y + paddle1.height;
		float collision_point = collision_origin - ball.y;
		int collided_part = static_cast<int>(collision_point / _paddle_part_height);
		int sign = collided_part < cPaddleCentralPart ? 1 : -1;
		float result_angle = deg_to_rad((180.f - cPaddleAnglePerPart * (cPaddleCentralPart - collided_part)));

		new_direction = {cos(result_angle), sin(result_angle)};

		++_ball_colls;
	}
	_ball->setDirection(new_direction);
	_ball->setVelocity(cBallInitialVelocity + _ball_colls * cColVelocityMultiplier);
}

void Level::fixPaddle(Paddle* paddle) {
	Rectangle rect = paddle->getRect();
	if (rect.y < 0.f)
		paddle->setPosition(rect.x, 0.f);
	if (rect.y > _height - rect.height)
		paddle->setPosition(rect.x, _height - rect.height);
}

void Level::resetPaddles() {
	_paddles[0]->setPosition(0, _height / 2 - _paddle_height / 2);
	_paddles[1]->setPosition(_width - cPaddleWidth, _height / 2 - _paddle_height / 2);
}
