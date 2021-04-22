#ifndef REDENEMIES_H
#define REDENEMIES_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>



class RedEnemy
{
private:

	unsigned pointCount;
	sf::CircleShape shape; // sprite

	// Red Bird
	sf::Texture redTex;
	sf::Sprite  redSprite;
	bool RedMove;

	// Animations
	sf::IntRect redcurrentFrame;
	// time of animations
	sf::Clock animationTimer;

	int type;
	int hp;
	int hpmax;
	int damage;
	int points;
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
	RedEnemy(float posX, float posY);

	virtual ~RedEnemy();

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

#endif // !REDENEMIES_H