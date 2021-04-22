#include "Shield.h"

void Shield::initialVariables()
{
	this->pointCount = rand() % 8 + 3; // is 0->7 : min 3 point, max 10 point
	this->type = 0;
	this->hpmax = static_cast<int>(this->pointCount);
	this->hp = this->hpmax;
	this->damage = 0;
	this->points = 10;

	this->speed = 4.f;
	this->ShieldMove = false;
}

void Shield::initialTexture()
{
	if (!this->shieldTex.loadFromFile("Textures/shieldAnim.png"))
	{
		std::cout << "ERROR::Shield::INITIAL TEXTURE::could not load." << "\n";
	}
}

void Shield::initialSprite()
{
	this->shieldSprite.setTexture(this->shieldTex);
	this->shieldcurrentFrame = sf::IntRect(0, 0, 1750, 115);

	this->shieldSprite.setTextureRect(this->shieldcurrentFrame);

	this->shieldSprite.scale(1.0f, 1.0f);
}

void Shield::initialAnimations()
{
	this->animationTimer.restart();
}

void Shield::initialShape()
{
	// NO NEED
}

Shield::Shield(float posX, float posY)
{
	this->initialVariables();
	this->initialTexture();
	this->initialSprite();
	this->initialAnimations();

	//this->initialShape();
	this->shieldSprite.setPosition(posX, posY);
}

Shield::~Shield()
{

}

const sf::FloatRect Shield::getBounds() const
{
	return this->shieldSprite.getGlobalBounds();
}

const int& Shield::getPoints() const
{
	return this->points;
}

const int& Shield::getDamage() const
{
	return this->damage;
}

// function;
void Shield::update()
{
	this->updateAnimations();
	this->updateMovement();
}

void Shield::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (this->ShieldMove == true) // IDLE Anim
		{
			this->shieldcurrentFrame.top = 0.f;
			this->shieldcurrentFrame.width = 125.f;
			this->shieldcurrentFrame.left += 125.f;
			if (this->shieldcurrentFrame.left >= 1750.f)
				this->shieldcurrentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->shieldSprite.setTextureRect(this->shieldcurrentFrame);
	}
}

void Shield::updateMovement()
{
	this->ShieldMove = false;
	if (!this->ShieldMove)
	{
		this->shieldSprite.move(-this->speed, 0.f);
		this->ShieldMove = true;
	}
}

void Shield::render(sf::RenderTarget& target)
{
	target.draw(this->shieldSprite);
}
