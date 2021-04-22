#ifndef SHIELD_H
#define SHIELD_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>



class Shield
{
private:

	unsigned pointCount;
	sf::CircleShape shape; // sprite

	// Shield
	sf::Texture shieldTex;
	sf::Sprite  shieldSprite;
	bool ShieldMove;

	// Animations
	sf::IntRect shieldcurrentFrame;
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
	Shield(float posX, float posY);

	virtual ~Shield();

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

#endif // !SHIELD_H