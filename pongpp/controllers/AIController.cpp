#include "AIController.hpp"

void AIController::update(Paddle& paddle, Ball const& ball) {
	const auto ball_rect = ball.getRect();
	const auto paddle_rect = paddle.getRect();


	if (ball_rect.x > _max_x || ball_rect.x < _min_x) {
		const Vec2f new_direction = {0.f, 0.f};
		/*if (rect.y < _height / 2)
			newDir = { 0.f, 1.f };
		else if (rect.y > _height / 2)
			newDir = { 0.f, -1.f };*/
		paddle.setDirection(new_direction);
		return;
	}

	const float paddle_center = paddle_rect.y + paddle_rect.height / 2;

	if (paddle_center < ball_rect.y)
		paddle.setDirection({0.f, 1.f});
	else if (paddle_center > ball_rect.y)
		paddle.setDirection({0.f, -1.f});
	else
		paddle.setDirection({0.f, 0.f});
}
