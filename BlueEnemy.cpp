#include "BlueEnemy.h"

void BlueEnemy::initialVariables()
{
	this->pointCount = rand() % 8 + 3; // is 0->7 : min 3 point, max 10 point
	this->type = 0;
	this->hpmax = static_cast<int>(this->pointCount);
	this->hp = this->hpmax;
	this->damage = 20.f;
	this->points = 15.f;

	this->speed = 6.f;
	this->BlueMove = false;
}

void BlueEnemy::initialTexture()
{
	if (!this->blueTex.loadFromFile("Textures/blueAnim.png"))
	{
		std::cout << "ERROR::Blue Bird::INITIAL TEXTURE::could not load." << "\n";
	}
}

void BlueEnemy::initialSprite()
{
	this->blueSprite.setTexture(this->blueTex);
	this->bluecurrentFrame = sf::IntRect(0, 0, 1143, 90);

	this->blueSprite.setTextureRect(this->bluecurrentFrame);

	this->blueSprite.scale(1.2f, 1.2f);
}

void BlueEnemy::initialAnimations()
{
	this->BanimationTimer.restart();
}

void BlueEnemy::initialShape()
{
	/*
	this->shape.setRadius(this->pointCount * 5);
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 300 + 1, rand() % 30 + 1, 400)); //R, G, B color
	*/;
}

BlueEnemy::BlueEnemy(float posX, float posY)
{

	this->initialVariables();
	this->initialTexture();
	this->initialSprite();
	this->initialAnimations();

	//this->initialShape();
	this->blueSprite.setPosition(posX, posY);
}

BlueEnemy::~BlueEnemy()
{

}

const sf::FloatRect BlueEnemy::getBounds() const
{
	return this->blueSprite.getGlobalBounds();
}

const int& BlueEnemy::getPoints() const
{
	return this->points;
}

const int& BlueEnemy::getDamage() const
{
	return this->damage;
}



// function
void BlueEnemy::update()
{
	this->updateAnimations();
	this->updateMovement();
}


void BlueEnemy::updateAnimations()
{
	if (this->BanimationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (this->BlueMove == true) // IDLE Anim
		{
			this->bluecurrentFrame.top = 0.f;
			this->bluecurrentFrame.width = 127.f;
			this->bluecurrentFrame.left += 127.f;
			if (this->bluecurrentFrame.left >= 1143.f)
				this->bluecurrentFrame.left = 0;
		}

		this->BanimationTimer.restart();
		this->blueSprite.setTextureRect(this->bluecurrentFrame);
	}
}

void BlueEnemy::updateMovement()
{
	this->BlueMove = false;
	if (!this->BlueMove)
	{
		this->blueSprite.move(-this->speed, 0.f);
		this->BlueMove = true;
	}

}

void BlueEnemy::render(sf::RenderTarget& target)
{
	target.draw(this->blueSprite);
}

