#ifndef ENEMIES_H
#define ENEMIES_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>



class Enemies
{
private :

	unsigned pointCount;
	sf::CircleShape shape; // sprite

	// ADD NEW TEXTURE & SPRITE --> Yellow Flappy
	sf::Texture enemyTex;
	sf::Sprite  enemySprite;


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
	
public :
	Enemies(float posX, float posY);

	virtual ~Enemies();

	// access
	const sf::FloatRect getBounds() const;


	const int& getPoints() const;

	const int& getDamage() const;

	// functions


	void update();
	void render(sf::RenderTarget& target);
};

#endif // !ENEMIES_H