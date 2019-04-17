#include "main.h"



//Main function
void main(int argc, char** argv[])
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "FSM - Racing Car - Lefkos Savvides - 1602544");
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
			std::cout << "Welcome to my FSM car application developed using SFML - THIS IS A METHOD TO COMPARE TO THE FUZZYLOGIC CAR" << std::endl;
			std::cout << "Choose which stage would you like to use. Press 3 or input 3 on manual value 1 to toggle between the two." << std::endl;
			std::cout << "1. Stage 1 - CMD Window that takes inputs for DISTANCE and outputs the velocity the car will get until it reaches the line." << std::endl;
			std::cout << "2. Stage 2 - SFML Implementation that has a car chasing a line that is movable using IF STATEMENTS" << std::endl;

			cin >> Stage;
			game.setStage(Stage);
			system("CLS");
		}

		
		
		if (game.getStage() == 1)
		{
			game.stage1();
		}

		else if (game.getStage() == 2)
		{
			game.gameloop();
		}
	}

}