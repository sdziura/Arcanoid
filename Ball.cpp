#include "pch.h"
#include "Ball.h"


Ball::Ball(float t_x, float t_y, float t_speed)
{
	shape.setPosition(t_x, t_y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::Black);
	shape.setOrigin(this->ballRadius, this->ballRadius);
	this->ballVelocity = t_speed;
	this->velocity = { ballVelocity, ballVelocity };
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

bool  Ball::update()
{
	shape.move(this->velocity);

	if (this->left() < 0)
	{
		this->velocity.x = ballVelocity;
	}
	else if (this->right() > 800)
	{
		this->velocity.x = -ballVelocity;
	}

	if (this->up() < 0)
	{
		this->velocity.y = ballVelocity;
	}
	else if (this->down() > 600)
	{
		return true;
	}
	return false;
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::up()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::down()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}

void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}

void Ball::moveRight()
{
	this->velocity.x = ballVelocity;
}

void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity;
}

Vector2f Ball::getPosition()
{
	return shape.getPosition();
}

void Ball::changePosition(float x, float y)
{
	shape.setPosition(x, y);
}

void Ball::changeSpeed(float speed)
{
	ballVelocity = speed;
	velocity = { speed, speed };
}