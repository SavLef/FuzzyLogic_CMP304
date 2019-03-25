#pragma once
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include <string>
#include <iostream>
#include "fl/Headers.h"
#include <iomanip>   

class Game {
public:
	Game(sf::RenderWindow* hwnd, Input* inpt);
	~Game();
	//Functions - Public
	void handleInput();
	void update(float dt);
	void gameloop();
	void render();



private:
	sf::RenderWindow* window;
	//Functions - Private
	void beginDraw();
	void endDraw();

	//Class declarations

	Input* input;

	sf::Font font;
	sf::Text Distance;
	sf::Text Steering;
	sf::Text Velocity;

	sf::Text n_Distance;
	sf::Text n_Steering;
	sf::Text n_Velocity;

	AnimatedSprite Car;
	AnimatedSprite RacingLine;

	sf::Texture t_Car;
	sf::Texture t_RacingLine;

	sf::Texture t_Background;
	AnimatedSprite s_Background;

	sf::Clock updateTimer;
	sf::Time elapsed1;

	fl::OutputVariable* output;
	fl::Engine* engine;

	//Clock for Delta time and Clock for Timer.
	sf::Clock clock;
	float deltaTime;

	float f_velocity;
	float f_distance;
	float speed;
};
