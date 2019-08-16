#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public sf::Drawable
{
public:
	Ball(float t_x, float t_y, float t_speed);
	Ball() ;
	~Ball() = default;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	float left();
	float right();
	float up();
	float down();

	void changeSpeed(float speed);
	void changePosition(float x, float y);
	bool update();
	Vector2f getPosition();

private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	float ballVelocity;
	Vector2f velocity ;
	void draw(RenderTarget& target, RenderStates state) const override;

};

