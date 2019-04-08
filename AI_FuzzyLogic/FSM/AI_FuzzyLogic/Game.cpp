#include "Game.h"

Game::Game(sf::RenderWindow* hwnd, Input* inpt)
{
	window = hwnd;
	input = inpt;



	//Import MatLab Data
	//engine = fl::FisImporter().fromFile("1.fis");

	//Textures
	t_Car.loadFromFile("gfx/bullet.png");
	t_RacingLine.loadFromFile("gfx/Player1.png");
	
	t_Background.loadFromFile("gfx/BG.jpg");
;

	//Sprites
				//Player 1
	Car.setSize(sf::Vector2f(80, 100));
	Car.setOrigin(Car.getSize().x / 2, Car.getSize().y / 2);
	Car.setFillColor(sf::Color::Red);
	Car.setTexture(&t_Car);
	Car.setPosition(400, 300);


	//Player 2
	RacingLine.setSize(sf::Vector2f(10, 10000));
	RacingLine.setOrigin(RacingLine.getSize().x / 2, RacingLine.getSize().y / 2);
	RacingLine.setFillColor(sf::Color::Black);
	RacingLine.setTexture(&t_RacingLine);
	RacingLine.setPosition(400, 100);

	
	s_Background.setSize(sf::Vector2f(800,600));
	s_Background.setTexture(&t_Background);
	s_Background.setPosition(0, 0);



	elapsed1 = updateTimer.getElapsedTime();

	font.loadFromFile("Font/arial.ttf");

	//VALUES SETUP
	Distance.setFont(font);
	Steering.setFont(font);
	Velocity.setFont(font);

	Distance.setPosition(0,50);
	Velocity.setPosition(330, 50);
	Steering.setPosition(660, 50);

	Distance.setFillColor(sf::Color::Black);
	Velocity.setFillColor(sf::Color::Blue);
	Steering.setFillColor(sf::Color::Red);

	//VALUE NAMES SETUP
	n_Distance.setFont(font);
	n_Steering.setFont(font);
	n_Velocity.setFont(font);

	n_Distance.setPosition(0, 0);
	n_Velocity.setPosition(330, 0);
	n_Steering.setPosition(660, 0);

	n_Distance.setFillColor(sf::Color::Black);
	n_Velocity.setFillColor(sf::Color::Blue);
	n_Steering.setFillColor(sf::Color::Red);


	std::cout << "Use left and right arrows to move line." << std::endl;
	std::cout << "Hold 1 or 2 while moving to increase speed." << std::endl;
	std::cout << std::endl << std::endl;
	

}
Game::~Game()
{
}



void Game::handleInput()
{

	
	
	
}



void Game::update(float dt)
{
	////VELOCITY
	//if (input->isKeyDown(sf::Keyboard::Up))
	//{
	//	f_velocity += 0.5*dt;
	//}

	//if (input->isKeyDown(sf::Keyboard::Down))
	//{
	//	f_velocity -= 0.5*dt;
	//}

	

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


	//VELOCITY
	if (input->isKeyDown(sf::Keyboard::Num3))
	{
		toggleStage();
	}
	
	f_distance = (RacingLine.getPosition().x - Car.getPosition().x) / 800;
	
	

	//STATE TRANSITIONS

	//if distance is not that big, give it a small velocity

	

	if (f_distance > -0.015 && f_distance < 0.015)
	{
		f_velocity = f_velocity - f_velocity;
	}

	else if (f_distance > 0.0 && f_distance <= 0.5)
	{
		f_velocity = f_velocity +lowvel;
	}
	else if (f_distance < 0.0 && f_distance >= -0.5)
	{
		f_velocity = f_velocity -lowvel;
	}

	else if (f_distance > 0.5)
	{
		f_velocity = f_velocity + highvel;
	}
	else if (f_distance < -0.5)
	{
		f_velocity = f_velocity -highvel;
	}


	



	Car.move((f_velocity)*dt * 1000, 0);
	
	

	//UPDATE TEXT
	Distance.setString(std::to_string(f_distance));
	Velocity.setString(std::to_string(f_velocity));
	//Steering.setString(std::to_string(output->getValue()));

	n_Distance.setString("Distance:");
	n_Velocity.setString("Velocity:");
	n_Steering.setString("Steering:");
}

void Game :: setStage(int stg)
{
	Stage = stg;
}

int Game::getStage()
{
	return Stage;
}

void Game::toggleStage()
{
	if (Stage == 1)
	{
		Stage = 2;
	}

	else if (Stage == 2)
	{
		Stage = 1;
	}
}
void Game::stage1()
{


	std::cout << "Enter Value for DISTANCE from line: (Between -1 and 1) OR ENTER 3 to toggle back to SFML." << std::endl;
	std::cin >> in1;

	if (in1 == 3)
	{
		toggleStage();
	}





	while (in1 < -1 || in1 > 1)
	{
		std::cout << "Re-Enter Value for DISTANCE from line: (Between -1 and 1)" << std::endl;
		std::cin >> in1;
	}



	f_velocity = 0;
	f_distance = in1;

	if (f_distance > -0.015 && f_distance < 0.015)
	{
		f_velocity = f_velocity - f_velocity;
	}

	else if (f_distance > 0.0 && f_distance <= 0.5)
	{
		f_velocity = f_velocity + lowvel;
	}
	else if (f_distance < 0.0 && f_distance >= -0.5)
	{
		f_velocity = f_velocity - lowvel;
	}

	else if (f_distance > 0.5)
	{
		f_velocity = f_velocity + highvel;
	}
	else if (f_distance < -0.5)
	{
		f_velocity = f_velocity - highvel;
	}

	std::cout << " The velocity that the car will keep increasing by until it reaches the line is: " << f_velocity << std::endl;

}
	
	

void Game::render()
{
	beginDraw();
	
	//window->draw(s_Background);
	window->draw(RacingLine);
	window->draw(Car);

	window->draw(n_Distance);
	window->draw(n_Velocity);


	window->draw(Distance);
	window->draw(Velocity);



	
	endDraw();
}
void Game::beginDraw()
{
	window->clear(sf::Color::White);
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