#include "pch.h"
#include "Block.h"


Block::Block(float t_x, float t_y, float t_width, float t_height)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ t_width, t_height });
	shape.setFillColor(Color::Magenta);
	shape.setOrigin(t_width/2, t_height/2);
}

void Block::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Block::up()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Block::down()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Block::getPosition()
{
	return shape.getPosition();
}

bool Block::isDestroyed()
{
	return destroyed;
}

void Block::destroy()
{
	this->destroyed = true;
}

void Block::undestroy()
{
	this->destroyed = false;
}

Vector2f Block::getSize()
{
	return shape.getSize();
}

void Block::update()
{
	
}
