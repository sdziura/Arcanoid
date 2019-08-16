#include "pch.h"
#include "Paddle.h"


Paddle::Paddle(float t_x, float t_y, float t_speed)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ this->paddleWidth , this->paddleHeight });
	shape.setFillColor(Color::Blue);
	shape.setOrigin(this->paddleWidth/2, this->paddleHeight/2);
	this->paddleVelocity = t_speed;
}

void Paddle::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Paddle::update()
{
	shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
	{
		velocity.x = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
	{
		velocity.x = paddleVelocity;
	}
	else
	{
		velocity.x = 0;
	}

}

float Paddle::left()
{
	return this->shape.getPosition().x - shape.getSize().x/2.f;
}

float Paddle::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Paddle::up()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Paddle::down()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Paddle::getPosition()
{
	return shape.getPosition();
}