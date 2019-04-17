#pragma once
#include "Sprite.h"
class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(const sf::Vector2f &size = sf::Vector2f(0, 0));
	~AnimatedSprite();
	virtual void update(float dt);
	void setFrameSize(int width, int height);
	int getFrameWidth() { return frame.width; };
	int getFrameHeight() { return frame.height; };
	void setAnimationSpeed(float aspeed);
	void setAlive(bool liv);
	bool getAlive();
	int getHP();
	void setHP(int health);
	void getsetAlive(int palive);
	void calcpercent();


	bool alive;
	int hp = 5000;
	int hppercent = 100;
protected:
	// variable for controlling animation
	float elapsedTime;
	float animationSpeed;
	sf::IntRect frame;
};




