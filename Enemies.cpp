#include "Enemies.h"

void Enemies::initialVariables()
{
	this->pointCount = rand() % 8 + 3; // is 0->7 : min 3 point, max 10 point
	this->type		= 0;
	this->hpmax		= static_cast<int>(this->pointCount);
	this->hp		= this->hpmax;
	this->damage	= 40;
	this->points	= 50;

	this->speed		= 8.f;
}

void Enemies::initialTexture()
{
	if (!this->enemyTex.loadFromFile("Textures/flap.png"))
	{
		std::cout << "ERROR::Flappy::INITIAL TEXTURE::could not load." << "\n";
	}
}

void Enemies::initialSprite()
{
	this->enemySprite.setTexture(this->enemyTex);
	this->enemySprite.scale(0.5f, 0.5f);
}

void Enemies::initialShape()
{
	/*
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 300 + 1, rand() % 30 + 1, 400)); //R, G, B color
	*/;
}

Enemies::Enemies(float posX, float posY)
{
	
	this->initialVariables();
	this->initialTexture();
	this->initialSprite();
	
	//this->initialShape();
	this->enemySprite.setPosition(posX, posY);
}

Enemies::~Enemies()
{

}

const sf::FloatRect Enemies::getBounds() const
{
	return this->enemySprite.getGlobalBounds();
}

const int& Enemies::getPoints() const
{
	return this->points;
}

const int& Enemies::getDamage() const
{
	return this->damage;
}



// function
void Enemies::update()
{
	this->enemySprite.move(-this->speed, 0.f);
}

void Enemies::render(sf::RenderTarget& target)
{
	target.draw(this->enemySprite);
}
