#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_x, float t_y, float t_speed);
	Paddle() = delete;
	~Paddle() = default;

	float left();
	float right();
	float up();
	float down();

	void changeSpeed(float speed);
	void update();
	Vector2f getPosition();

private:
	RectangleShape shape;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	float paddleVelocity;
	Vector2f velocity = { paddleVelocity, 0.f };
	void draw(RenderTarget& target, RenderStates state) const override;
};

