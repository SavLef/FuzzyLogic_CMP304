#include "main.h"


//int main(int argc, char **argv)
//{
//fl::Engine* engine = fl::FisImporter().fromFile("MatL.fis");
//
//	engine->getInputVariable(0)->setValue(2);
//	engine->getInputVariable(1)->setValue(-1);
//
//	engine->process();
//
//	fl::OutputVariable* output = engine->getOutputVariable(0);
//
//	printf("%f\n", output->getValue());
//
//	system("PAUSE");
//}

//Main function
void main(int argc, char** argv[])
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "N3ON - WAR");
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