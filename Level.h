#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

using namespace sf;
using namespace std;


class Level
{
public:
	Level(int t_levelNr);
	Level() = delete;
	~Level() = default;

	void refreshLevel(); //vector<Block> *blocks
	void nextLevel();
	void firstLevel();
	
	void update();
	void draw(RenderWindow &window);
	bool noBlocks();

	void collisionTest();


private:
	int lvlNr;
	Paddle paddle;
	Ball ball;
	vector<Block> blocks;

};

