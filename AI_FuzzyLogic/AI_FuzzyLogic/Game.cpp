#include "Game.h"

Game::Game(sf::RenderWindow* hwnd, Input* inpt)
{
	window = hwnd;
	input = inpt;



	//Import MatLab Data
	engine = fl::FisImporter().fromFile("MatL.fis");

	//Textures
	t_Car.loadFromFile("gfx/bullet.png");
	t_RacingLine.loadFromFile("gfx/Player1.png");
	
	t_Background.loadFromFile("gfx/BG.jpg");
;

	//Sprites
				//Player 1
	Car.setSize(sf::Vector2f(180, 100));
	Car.setFillColor(sf::Color::Red);
	Car.setTexture(&t_Car);
	Car.setPosition(400, 300);


	//Player 2
	RacingLine.setSize(sf::Vector2f(180, 1000));
	RacingLine.setFillColor(sf::Color::White);
	RacingLine.setTexture(&t_RacingLine);
	RacingLine.setPosition(400, 100);

	
	s_Background.setSize(sf::Vector2f(800,600));
	s_Background.setTexture(&t_Background);
	s_Background.setPosition(0, 0);



	elapsed1 = updateTimer.getElapsedTime();

	font.loadFromFile("Font/arial.ttf");

	Distance.setFont(font);
	Steering.setFont(font);
	Velocity.setFont(font);


	Distance.setString("Distance from Line:        %" );
	Distance.setString(std::to_string(f_distance));

	Velocity.setString("Velocity:        %");
	Velocity.setString(std::to_string(f_velocity));

	Steering.setString("Steering:        %");
	//Steering.setString(std::to_string(output->getValue()));


	Distance.setPosition(0,0);
	Velocity.setPosition(350, 0);
	Steering.setPosition(750, 0);

	Distance.setFillColor(sf::Color::White);
	Velocity.setFillColor(sf::Color::White);
	Steering.setFillColor(sf::Color::Red);

}
Game::~Game()
{
}



void Game::handleInput()
{

	
	
	
}



void Game::update(float dt)
{
	//VELOCITY
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		f_velocity += 0.5*dt;
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		f_velocity -= 0.5*dt;
	}

	

	if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::Num1))
	{
		RacingLine.move(600 * dt, 0);
	}

	else if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::Num2))
	{
		RacingLine.move(1000 * dt, 0);
	}

	//VELOCITY
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		RacingLine.move(300 * dt, 0);
	}

	

	if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::Num1))
	{
		RacingLine.move(-600 * dt, 0);
	}


	else if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::Num2))
	{
	RacingLine.move(-1000 * dt, 0);
	}

	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		RacingLine.move(-300 * dt, 0);
	}

	
	f_distance = (RacingLine.getPosition().x - Car.getPosition().x) / 160;
	
	

	//VELOCITY
	engine->getInputVariable(0)->setValue(f_distance);

	//DISTANCE
	engine->getInputVariable(1)->setValue(f_velocity);
	
	engine->process();
	
	output = engine->getOutputVariable(0);
	

	if (f_distance > 0 && f_distance < 0.05)
	{
		f_velocity=0;
	}

	
	Car.move(-(output->getValue())*dt * 1000, 0);
	
	

	//UPDATE TEXT
	Distance.setString(std::to_string(f_distance));
	Velocity.setString(std::to_string(f_velocity));
	Steering.setString(std::to_string(output->getValue()));
}

	
	

void Game::render()
{
	beginDraw();
	
	window->draw(s_Background);
	window->draw(Distance);
	window->draw(Velocity);
	window->draw(Steering);

	window->draw(RacingLine);
	window->draw(Car);
	
	
	endDraw();
}
void Game::beginDraw()
{
	window->clear(sf::Color::Black);
}
void Game::endDraw()
{
	window->display();
}

void Game::gameloop()
{
	
	//Delta time calculation (in seconds) to be passed in the update functions.
	deltaTime = clock.restart().asSeconds();
	handleInput();
	update(deltaTime);
	render();

}