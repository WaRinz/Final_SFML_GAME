#include "Player.h"


	//---- PRIVATE ( CAN'T INCLUDE ) ----

void Player::initialVariables()
{
	this->animationState = PLAYER_ANIMATION_STATES::IDLE;

	// attack per time
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	// HP
	this->hpMax = 100;
	this->hp = this->hpMax;
	
}

void Player::initialTexture()// picture
{
	/*load texture pilot picture file*/
	if (!this->texture.loadFromFile("Textures/meows.png"))
	{
		std::cout << "ERROR::PILOT::INITIALTEXTURE::could not load." << "\n";
	}
}

void Player::initialSprite()// box to put picture
{
	/*set texture to sprite*/
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(40.f, 350.f));

	/* crop frame -> animations */
	this->currentFrame = sf::IntRect(0, 0, 157, 164);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.0f, 1.0f);


	/* size */
	this->sprite.scale(1.f, 1.f);
}

void Player::initialAnimations()
{
	this->animationTimer.restart();
}

void Player::initialPhysics()
{
	this->velocityMax = 6.f;
	this->velocityMin = 1.f;
	this->acceleration = 2.f;
	this->deceleration = 0.93f;
}


	//---- PUBLIC ( CAN INCLUDE ) ----

Player::Player()
{
	this->initialVariables();
	
	this->initialTexture();
	this->initialSprite();
	
	this->initialAnimations();
	this->initialPhysics();
}

Player:: ~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHP(const int hp)
{
	this->hp = hp;
}

void Player::loseHP(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}

	if (this->hp > 100)
	{
		this->hp = 100;
	}
}

void Player::move(const float dirX, const float dirY)
{

	// aceleration
	this->velocity.x += dirX * this->acceleration;
	
	this->velocity.y += dirY * this->acceleration;

	// limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
	if (std::abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}



void Player::updatePhysics()
{
	// deceleration
	this->velocity *= this->deceleration;

	// limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
	if (gotShield == true)
	{
		this->SHsprite.move(this->velocity);
	}
}

void Player::updateMovement()
{
	/*MOVE PILOT*/
	this->animationState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // up

	{
		this->move(0.f, -1.f); this->animationState = PLAYER_ANIMATION_STATES::MOVING_UP;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // left

	{
		this->move(-1.f, 0.f); this->animationState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // down

	{
		this->move(0.f, 1.f); this->animationState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // right

	{
		this->move(1.f, 0.f); this->animationState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
		
}

void Player::updateAnimations()
{
	if (this->animationState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
				this->currentFrame.top = 0.f;
				this->currentFrame.left += 157.f;
				if (this->currentFrame.left >= 628.f)
					this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_UP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 157.f;
			if (this->currentFrame.left >= 628.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 157.f;
			if (this->currentFrame.left >= 628.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_DOWN)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 157.f;
			if (this->currentFrame.left >= 628.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animationState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 157.f;
			if (this->currentFrame.left >= 628.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.25f;
	}
		
}

void Player::getShield(bool ON, float sx, float sy)
{
	this->SHx = sx;
	this->SHy = sy;
	this->gotShield = ON;

	/*load texture shield file*/
	if (!this->SHtexture.loadFromFile("Textures/shield.png"))
	{
		std::cout << "ERROR::SHIELD::INITIALTEXTURE::could not load." << "\n";
	}
	this->SHsprite.setTexture(this->SHtexture);
	this->SHsprite.setPosition(sx - 130.f, sy - 40.f);
	this->SHsprite.setScale(0.5f, 0.5f);
}

void Player::updateShield(float sx, float sy)
{
	this->SHsprite.setPosition(sx - 130.f, sy - 40.f);
}

/* FUNCTIONs */
void Player::update()
{
	this->updateMovement();
	this->updateAttack();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	if (gotShield == true)
	{
		target.draw(this->SHsprite);
	}
}
