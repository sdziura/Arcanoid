#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(float t_x, float t_y, float t_width, float t_height);
	Block() = delete;
	~Block() = default;

	float left();
	float right();
	float up();
	float down();

	void update();
	Vector2f getPosition();

	bool isDestroyed();
	void destroy();
	Vector2f getSize();
	void undestroy();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	RectangleShape shape;
	bool destroyed{ false };


};
