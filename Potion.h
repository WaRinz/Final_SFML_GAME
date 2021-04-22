#ifndef POTION_H
#define POTION_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>



class Potion
{
private:

	unsigned pointCount;
	sf::CircleShape shape; // sprite

	// ADD NEW TEXTURE & SPRITE --> POTION
	sf::Texture poTex;
	sf::Sprite  poSprite;


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
	void initialShape();

public:
	Potion(float posX, float posY);

	virtual ~Potion();

	// access
	const sf::FloatRect getBounds() const;


	const int& getPoints() const;

	const int& getDamage() const;

	// functions


	void update();
	void render(sf::RenderTarget& target);
};

#endif // !POTION_H