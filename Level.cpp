#include "pch.h"
#include "Level.h"


Level::Level(int t_levelNumber) : ball(BALLPOSX, BALLPOSY, 6), paddle(PADDLEPOSX, PADDLEPOSY, 8)
{
	lvlNr = t_levelNumber;
	
	for (int i = 0; i < BLOCKSY; i++)
	{
		for (int j = 0; j < BLOCKSX; j++)
		{
			blocks.emplace_back((j + 1)*(BLOCKWIDTH + 10), (i + 2)*(BLOCKHEIGHT + 5), BLOCKWIDTH, BLOCKHEIGHT);
		}
	}
}

void Level::refreshLevel()
{
	for (int i = 0; i < BLOCKSY; i++)
	{
		for (int j = 0; j < BLOCKSX; j++)
		{
			blocks.emplace_back((j + 1)*(BLOCKWIDTH + 10), (i + 2)*(BLOCKHEIGHT + 5), BLOCKWIDTH, BLOCKHEIGHT);
		}
	}
	ball.changePosition(BALLPOSX, BALLPOSY);
	ball.changeSpeed(0);
	while (!(Keyboard::isKeyPressed(Keyboard::Key::Down)))
	{
	//	if (event.type == Event::Closed)
		{
			//window.close();
		//	break;
		}
	}

	ball.changeSpeed(6);

}

void Level::nextLevel()
{
	lvlNr++;
}

void Level::firstLevel()
{
	lvlNr = 1;
}

void Level::update()
{
	if (ball.update()) this->refreshLevel();
	paddle.update();
	auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed(); });
	blocks.erase(iterator, end(blocks));

}

void Level::draw(RenderWindow &window)
{
	window.draw(this->ball);
	window.draw(paddle);
	for (auto& block : blocks)
	{
		if (!block.isDestroyed()) window.draw(block);
	}
}

template<class T1, class T2> bool isIntersecting(T1& a, T2& b)
{
	return a.right() >= b.left() && a.left() <= b.right()
		&& a.up() <= b.down() && a.down() >= b.up();
}


void Level::collisionTest()
{
	for (auto& block : blocks)
	{
		if (isIntersecting(block, ball))
		{
			block.destroy();

			if (ball.getPosition().x < block.getPosition().x)
			{
				ball.moveLeft();
			}
			else
			{
				ball.moveRight();
			}

			if (ball.getPosition().y < block.getPosition().y)
			{
				ball.moveUp();
			}
			else
			{
				ball.moveDown();
			}
		}
	}

	if (isIntersecting(paddle, ball)) 
	{
		ball.moveUp();

		if (ball.getPosition().x < paddle.getPosition().x)
		{
			ball.moveLeft();
		}
		else
		{
			ball.moveRight();
		}
	}
}

bool Level::noBlocks()
{
	return !blocks.size();
}

