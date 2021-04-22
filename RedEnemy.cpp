#include "RedEnemy.h"

void RedEnemy::initialVariables()
{
	this->pointCount = rand() % 8 + 3; // is 0->7 : min 3 point, max 10 point
	this->type = 0;
	this->hpmax = static_cast<int>(this->pointCount);
	this->hp = this->hpmax;
	this->damage = 10;
	this->points = 5;

	this->speed = 4.f;
	this->RedMove = false;
}

void RedEnemy::initialTexture()
{
	if (!this->redTex.loadFromFile("Textures/redAnim.png"))
	{
		std::cout << "ERROR::Red Bird::INITIAL TEXTURE::could not load." << "\n";
	}
}

void RedEnemy::initialSprite()
{
	this->redSprite.setTexture(this->redTex);
	this->redcurrentFrame = sf::IntRect(0, 0, 1260, 70);

	this->redSprite.setTextureRect(this->redcurrentFrame);

	this->redSprite.scale(0.9f, 0.9f);
}

void RedEnemy::initialAnimations()
{
	this->animationTimer.restart();
}

void RedEnemy::initialShape()
{
	/*
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 300 + 1, rand() % 30 + 1, 400)); //R, G, B color
	*/;
}

RedEnemy::RedEnemy(float posX, float posY)
{

	this->initialVariables();
	this->initialTexture();
	this->initialSprite();
	this->initialAnimations();

	//this->initialShape();
	this->redSprite.setPosition(posX, posY);
}

RedEnemy::~RedEnemy()
{

}

const sf::FloatRect RedEnemy::getBounds() const
{
	return this->redSprite.getGlobalBounds();
}

const int& RedEnemy::getPoints() const
{
	return this->points;
}

const int& RedEnemy::getDamage() const
{
	return this->damage;
}



// function;
void RedEnemy::update()
{
	this->updateAnimations();
	this->updateMovement();
}


void RedEnemy::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (this->RedMove == true) // IDLE Anim
		{
			this->redcurrentFrame.top = 0.f;
			this->redcurrentFrame.width = 90.f;
			this->redcurrentFrame.left += 90.f;
			if (this->redcurrentFrame.left >= 1260.f)
				this->redcurrentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->redSprite.setTextureRect(this->redcurrentFrame);
	}
}

void RedEnemy::updateMovement()
{
	this->RedMove = false;
	if (!this->RedMove)
	{
		this->redSprite.move(-this->speed, 0.f);
		this->RedMove = true;
	}

}

void RedEnemy::render(sf::RenderTarget& target)
{
	target.draw(this->redSprite);
}

