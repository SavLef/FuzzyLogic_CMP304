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

		if (Stage != 1 && Stage!= 2)
		{
			std::cout << "Welcome to my FuzzyLogic car developed using SFML and the Fuzzylite libraries." << std::endl;
			std::cout << "Choose which stage would you like to use. Restart the application to choose the other one later." << std::endl;
			std::cout << "1. Stage 1 - CMD Window that takes inputs for DISTANCE and VELOCITY and outputs STEERING. (In that order)" << std::endl;
			std::cout << "2. Stage 2 - SFML Implementation that has a car chasing a line that is movable using fuzzylogic." << std::endl;

			cin >> Stage;

			system("CLS");
		}
		
		if (Stage == 1)
		{
			game.stage1();
		}
		if (Stage  == 2)
		{
			game.gameloop();
		}
	}

}