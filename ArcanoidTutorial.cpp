// ArcanoidTutorial.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"

#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Level.h"


using namespace sf;
using namespace std;


int main()
{
	
	RenderWindow window{ VideoMode{WINDOWWIDTH, WINDOWHEIGHT}, "Arcanoid Tutorial" };
	window.setFramerateLimit( 60 );
	window.display();
	Level level(1);
	String tekst(L"Kurs SFML, C++ - http://cpp0x.pl");
	Event event;

	while (true)
	{
		//window.draw(tekst);

		window.clear( Color::White );
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		
		level.update();
		level.collisionTest();
		level.draw(window);
	
		if (level.noBlocks())
		{
			level.nextLevel();
			level.refreshLevel();
		}
		
		window.display();

	}

}

