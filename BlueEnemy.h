#ifndef BLUEENEMIES_H
#define BLUEENEMIES_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>



class BlueEnemy
{
private:

	unsigned pointCount;
	sf::CircleShape shape; // sprite

	// Red Bird
	sf::Texture blueTex;
	sf::Sprite  blueSprite;
	bool BlueMove;

	// Animations
	sf::IntRect bluecurrentFrame;
	// time of animations
	sf::Clock BanimationTimer;

	int type;
	int hp;
	int hpmax;
	int damage;
	float points;
	float speed;

	float posX;
	float posY;
	int ability;

	void initialVariables();
	void initialTexture();
	void initialSprite();
	void initialAnimations();
	void initialShape();

public:
	BlueEnemy(float posX, float posY);

	virtual ~BlueEnemy();

	// access
	const sf::FloatRect getBounds() const;


	const int& getPoints() const;

	const int& getDamage() const;

	// functions

	void updateAnimations();
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !BLUEENEMIES_H