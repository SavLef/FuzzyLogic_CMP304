#include "main.h"



//Main function
void main(int argc, char** argv[])
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Fuzzy Logic - Racing Car - Lefkos Savvides - 1602544");
	Game game(&window, &input);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0, 0,
					event.size.width, event.size.height)));
				break;
				//------------------------------------------------
				//Keyboard Inputs
			case sf::Event::KeyPressed:
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				input.setKeyUp(event.key.code);
				break;
				//------------------------------------------------
			default:
				
				break;
			}

	
		}
		game.gameloop();
	}
}