#include "Potion.h"

void Potion::initialVariables()
{
	this->pointCount = rand() % 8 + 3; // is 0->7 : min 3 point, max 10 point
	this->type = 0;
	this->hpmax = static_cast<int>(this->pointCount);
	this->hp = this->hpmax;
	this->damage = -20;
	this->points = 200;

	this->speed = 4.f;
}

void Potion::initialTexture()
{
	if (!this->poTex.loadFromFile("Textures/HPpo.png"))
	{
		std::cout << "ERROR::Potion::INITIAL TEXTURE::could not load." << "\n";
	}
}

void Potion::initialSprite()
{
	this->poSprite.setTexture(this->poTex);
	this->poSprite.scale(0.25f, 0.25f);
}

void Potion::initialShape()
{
	/*
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 300 + 1, rand() % 30 + 1, 400)); //R, G, B color
	*/;
}

Potion::Potion(float posX, float posY)
{

	this->initialVariables();
	this->initialTexture();
	this->initialSprite();

	//this->initialShape();
	this->poSprite.setPosition(posX, posY);
}

Potion::~Potion()
{

}

const sf::FloatRect Potion::getBounds() const
{
	return this->poSprite.getGlobalBounds();
}

const int& Potion::getPoints() const
{
	return this->points;
}

const int& Potion::getDamage() const
{
	return this->damage;
}



// function
void Potion::update()
{
	this->poSprite.move(-this->speed, 0.f);
}

void Potion::render(sf::RenderTarget& target)
{
	target.draw(this->poSprite);
}
