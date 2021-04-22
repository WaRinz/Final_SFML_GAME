#include "Game.h"
void Game::initialWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1700, 900), "63010849 Worawich Tangpojthaweeporn", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
	

	// ICON
	if (!this->icon.loadFromFile("Textures/icon.png"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD GAME ICON" << "\n";
	}
	this->window->setIcon(this->icon.getSize().x, this->icon.getSize().y, this->icon.getPixelsPtr());
}
void Game::initialTextures()
{
	// Bullet
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");

	// Menu
	this->menuSprite.setTexture(&this->menuTexture);


}

void Game::initialGUI()  // text health bar
{
	// load font
	if (!this->font.loadFromFile("Text/rockeb.ttf"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD FONT TEXT" << "\n";
	}
	
	// initial point text
	this->pointText.setPosition(sf::Vector2f(50.f, 5.f));
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(50);
	this->pointText.setFillColor(sf::Color::Black);
	this->pointText.setString("");
	this->pointText.setStyle(sf::Text::Regular);
	this->pointText.setStyle(sf::Text::Underlined);

	// gameOver Text
	this->gameOverText.setPosition(sf::Vector2f(600.f, 330.f));
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(90);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("!!! GAME OVER !!!");
	this->gameOverText.setStyle(sf::Text::Bold);

	// Show results ---> SCORE
	this->results.setPosition(sf::Vector2f(540.f, 260.f));
	this->results.setFont(this->font);
	this->results.setCharacterSize(70);
	this->results.setFillColor(sf::Color::Black);
	this->results.setString(" score ");
	this->results.setStyle(sf::Text::Regular);

	// Show played score ---> SCORE
	this->NowScore.setPosition(sf::Vector2f(150.f, 770.f));
	this->NowScore.setFont(this->font);
	this->NowScore.setCharacterSize(70);
	this->NowScore.setFillColor(sf::Color::Black);
	this->NowScore.setString(" NowScore ");
	this->NowScore.setStyle(sf::Text::Regular);



	// initial HP
	this->playerHpBar.setSize(sf::Vector2f(500.f, 30.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(1150.f, 20.f));
	this->playerHpBar.setOutlineColor(sf::Color::Yellow);
	this->playerHpBar.setOutlineThickness(2.f);

	this, playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	// player text
	this->playerText.setPosition(sf::Vector2f(500.f, 275.f));
	this->playerText.setFont(this->font);
	this->playerText.setCharacterSize(100);
	this->playerText.setFillColor(sf::Color::Black);
	this->playerText.setString("");
	this->playerText.setStyle(sf::Text::Bold);




	// score board style text

			/*this->KhaNaen[0][0].setPosition(sf::Vector2f(800.f, 100.f));
			this->KhaNaen[0][0].setFont(this->font);
			this->KhaNaen[0][0].setCharacterSize(100);
			this->KhaNaen[0][0].setFillColor(sf::Color::Black);
			this->KhaNaen[0][0].setString(this->GaebKhaNaen[0][0]);
			this->KhaNaen[0][0].setStyle(sf::Text::Regular);

			

			this->KhaNaen[0][1].setPosition(sf::Vector2f(800.f, 100.f));
			this->KhaNaen[1][0].setPosition(sf::Vector2f(400.f, 100.f));
			this->KhaNaen[1][1].setPosition(sf::Vector2f(400.f, 100.f));
			this->KhaNaen[2][0].setPosition(sf::Vector2f(1200.f, 100.f));
			this->KhaNaen[2][1].setPosition(sf::Vector2f(1200.f, 100.f));
			this->KhaNaen[3][0].setPosition(sf::Vector2f(400.f, 100.f));
			this->KhaNaen[3][1].setPosition(sf::Vector2f(400.f, 100.f));
			this->KhaNaen[4][0].setPosition(sf::Vector2f(1200.f, 100.f));
			this->KhaNaen[4][1].setPosition(sf::Vector2f(1200.f, 100.f));*/

	    
	// text = 0 / score = 1;


	/*for (int rank = 0; rank < 5; rank++)
	{
		for (int scoree = 0; scoree < 2; scoree++)
		{
			this->KhaNaen[rank][scoree].setFont(this->font);
			this->KhaNaen[rank][scoree].setCharacterSize(20);
			this->KhaNaen[rank][scoree].setFillColor(sf::Color::Black);
			this->KhaNaen[rank][scoree].setString(this->GaebKhaNaen[0][1]);
			this->KhaNaen[rank][scoree].setStyle(sf::Text::Regular);
		}
	}*/


}

void Game::initialBG()
{
	if (!this->bgTexture.loadFromFile("Textures/Rsky6800.png"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD BG TEXTURES" << "\n";
	}
	this->background.setTexture(&bgTexture);
	this->background.setSize(sf::Vector2f(6802.f, 900.f));
	this->background.setPosition(sf::Vector2f(0.f, 0.f));

	
}


void Game::initialBG1()
{
	if (!this->bgTexture1.loadFromFile("Textures/Rsky6800.png"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD BG-1 TEXTURES" << "\n";
	}
	this->background1.setTexture(&bgTexture1);
	this->background1.setSize(sf::Vector2f(6802.f, 900.f));
	this->background1.setPosition(sf::Vector2f(6800.f, 0.f));


}

void Game::initialBGSound()
{
	if (!this->music.openFromFile("Textures/cuphead.ogg"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - cuphead - SOUND" << "\n";
	}
	// initial bg sound
	this->music.play();
	this->music.setVolume(50.f);
	this->music.setLoop(true);
	
}

void Game::initialBGMenuSound()
{
	if (!this->menuMusic.openFromFile("Textures/start.OGG"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - start game song - SOUND" << "\n";
	}
	// initial bg sound
	this->menuMusic.play();
	this->menuMusic.setVolume(100.f);
	this->menuMusic.setLoop(true);
}

// Board State
void Game::initialBGMenu()
{
	if (!this->menuTexture.loadFromFile("Textures/menuART.png"))
	{
		std::cout << "ERROR::Menu Background ::could not load." << "\n";
	}

	//this->menuSprite.setTexture(&menuTexture);
	this->menuSprite.setSize(sf::Vector2f (
								static_cast<float>(this->window->getSize().x), 
								static_cast<float>(this->window->getSize().y)
								)
								);
}

void Game::initialBGtype()
{
	if (!this->BGtypeTex.loadFromFile("Textures/typeName.png"))
	{
		std::cout << "ERROR::Type Name Background ::could not load." << "\n";
	}

	this->BGtypeRecShape.setTexture(&BGtypeTex);
	this->BGtypeRecShape.setSize(sf::Vector2f(
								static_cast<float>(this->window->getSize().x),
								static_cast<float>(this->window->getSize().y)
								)
								);
}

void Game::initialScoreboard()
{
	if (!this->ScoreTex.loadFromFile("Textures/boardA.png"))
	{
		std::cout << "ERROR:: -- Scoreboard Background ::could not load." << "\n";
	}

	this->ScoreRecShape.setTexture(&ScoreTex);
	this->ScoreRecShape.setSize(sf::Vector2f(
								static_cast<float>(this->window->getSize().x),
								static_cast<float>(this->window->getSize().y)
							)
							);

}

void Game::initialHowTo()
{
	if (!this->HowTex.loadFromFile("Textures/howtoP.png"))
	{
		std::cout << "ERROR:: --How To Play ::could not load." << "\n";
	}

	this->HowRecShape.setTexture(&HowTex);
	this->HowRecShape.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
	)
	);
}

void Game::initialCredit()
{
	if (!this->CreTex.loadFromFile("Textures/creditA.png"))
	{
		std::cout << "ERROR:: --How To Play ::could not load." << "\n";
	}

	this->CreRecShape.setTexture(&CreTex);
	this->CreRecShape.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
	)
	);
}
/* --- PILOT --- */
void Game::initialPlayer()
{
	this->player = new Player();

}

void Game::initialEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initialRedEnemy()
{
	this->RedspawnTimerMax = 8.f;
	this->RedspawnTimer = this->RedspawnTimerMax;
}

void Game::initialBlueEnemy()
{
	this->BluespawnTimerMax = 10.f;
	this->BluespawnTimer = this->BluespawnTimerMax;
}

void Game::initialPotion()
{
	this->PospawnTimerMax = 200.f;
	this->PospawnTimer = this->PospawnTimerMax;
}

void Game::initialShield()
{
	this->ShspawnTimerMax = 400.f;
	this->ShspawnTimer= this->ShspawnTimerMax;

}

void Game::initialSound()
{
	if (!this->buffer.loadFromFile("Textures/pop.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - pop - SOUND" << "\n";
	}
	// initial pew sound
	this->sound.setBuffer(this->buffer);

	this->sound.play();
	this->sound.setVolume(80.f);
}

void Game::initialHaha()
{
	if (!this->bufflol.loadFromFile("Textures/lol.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - gam over haha - SOUND" << "\n";
	}
	// initial HAHA
	this->haha.setBuffer(this->bufflol);

	this->haha.play();
	this->haha.setVolume(100.f);
}

void Game::initialHPsound()
{
	if (!this->buffHP.loadFromFile("Textures/glass.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - potion break - SOUND" << "\n";
	}
	// initial HAHA
	this->soundHP.setBuffer(this->buffHP);

	this->soundHP.play();
	this->soundHP.setVolume(100.f);
}

void Game::initialShieldSound()
{
	if (!this->buffShield.loadFromFile("Textures/hitShield.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - soudShield - SOUND" << "\n";
	}
	// initial HAHA
	this->soundShield.setBuffer(this->buffShield);

	this->soundShield.play();
	this->soundShield.setVolume(100.f);
}

void Game::initialHealSound()
{
	if (!this->buffHeal.loadFromFile("Textures/healing.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - healing - SOUND" << "\n";
	}
	// initial HAHA
	this->soundHeal.setBuffer(this->buffHeal);

	this->soundHeal.play();
	this->soundHeal.setVolume(75.f);

}

void Game::initialHurtSound()
{
	if (!this->buffHurt.loadFromFile("Textures/oof.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - oof - SOUND" << "\n";
	}
	// initial HAHA
	this->soundHurt.setBuffer(this->buffHurt);

	this->soundHurt.play();
	this->soundHurt.setVolume(100.f);

}
void Game::initialFlappySound()
{
	if (!this->buffFlappy.loadFromFile("Textures/flappysong.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - flappy die - SOUND" << "\n";
	}
	// initial HAHA
	this->soundFlappy.setBuffer(this->buffFlappy);

	this->soundFlappy.play();
	this->soundFlappy.setVolume(100.f);
}

void Game::initialBlueSound()
{
	if (!this->buffBlue.loadFromFile("Textures/bluesong.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - blue bird die - SOUND" << "\n";
	}
	// initial HAHA
	this->soundBlue.setBuffer(this->buffBlue);

	this->soundBlue.play();
	this->soundBlue.setVolume(100.f);
}

void Game::initialRedSound()
{
	if (!this->buffRed.loadFromFile("Textures/redsong.wav"))
	{
		std::cout << "ERROR::GAME::COLD NOT LOAD - blue bird die - SOUND" << "\n";
	}
	// initial HAHA
	this->soundRed.setBuffer(this->buffRed);

	this->soundRed.play();
	this->soundRed.setVolume(50.f);
}


void Game::LobThangMod()
{
	// yellow flappy
	for (auto& enem : this->enemies)
	{
		// delete enemies
		delete enem;

	}
	this->enemies.clear();		// flappy
	
	// red bird
	for (auto& redene : this->redenemy)
	{
		// delete red enemies
		delete redene;

	}
	this->redenemy.clear();		// red bird

	// blue bird
	for (auto* blueene : this->blueenemy)
	{
		// delete blue enemies
		delete blueene;
	}
	this->blueenemy.clear();	// blue bird

	// potion
	for (auto& po : this->potion)
	{
		// delete potion
		delete po;
	}
	this->potion.clear();		// potion
	
								
	// shield
	for (auto& sh : this->shield)
	{
		// delete shield
		delete sh;
	}
	this->shield.clear();		// shield


	// player HP start set to 100
	this->player->setHP(100);
	// point begin = 0
	this->points = 0;

	// bullet
	for (auto& bull : this->bullets)
	{
		// delete enemies
		delete bull;

	}
	this->bullets.clear();		// bullet
	
}

void Game::initialSystem()
{
	this->points = 0;

}

void Game::writeFileScore()
{
	std::ofstream writer;

	writer.open("Score.txt", std::fstream::app);
	if (writer.is_open())
	{

		writer << this->playerName << "\t" << this->points << std::endl;

		std::cout << "Open File Success!";

	}
	else
	{
		std::cout << "Cannot Open File!";
	}
}

void Game::registername()
{
	// initial point text --- rectangle box

	this->nameTTT.setSize(sf::Vector2f(805.f, 80.f));
	this->nameTTT.setOutlineColor(sf::Color::Black);
	this->nameTTT.setPosition(sf::Vector2f(450.f, 300.f));
	
}

void Game::readFileScore()
{
	std::stringstream zz;
	std::ifstream reader;
	//char a;
	int i;
	reader.open("Score.txt", std::fstream::app);
	


	if (reader.is_open())
	{
		for (i = 0; i < 5; i++)
		{
		//reader >> a;
		//reader >> this->playerName >> this->points;
			std::vector<std::string> temp;
			temp.push_back("NULL");
			temp.push_back("NULL");

			reader >> temp[0] >> temp[1];
			GaebKhaNaen.push_back(temp);
		std::cout << "Read File Success!" << std::endl;
		//std::cout << this->playerName << " " << this->points << std::endl;
		
		}
		for(int j = 0; j < 5; j++)
		{
			std::cout << this->GaebKhaNaen[j][0] ;
			std::cout << this->GaebKhaNaen[j][1] << std::endl;
		}
		// test what player's score should display on game
		zz << this->GaebKhaNaen[0][0] + "\t" + "\t" + "\t" + "\t";
		zz << this->GaebKhaNaen[0][1] << std::endl;

		zz << this->GaebKhaNaen[1][0] + "\t" + "\t" + "\t" + "\t";
		zz << this->GaebKhaNaen[1][1] << std::endl;

		zz << this->GaebKhaNaen[2][0] + "\t" + "\t" + "\t" + "\t";
		zz << this->GaebKhaNaen[2][1] << std::endl;

		zz << this->GaebKhaNaen[3][0] + "\t" + "\t" + "\t" + "\t";
		zz << this->GaebKhaNaen[3][1] << std::endl;

		zz << this->GaebKhaNaen[4][0] + "\t" + "\t" + "\t" + "\t";
		zz << this->GaebKhaNaen[4][1] << std::endl;


		
		
		this->results.setString(zz.str());

			//sc << this->playerName << " : " << this->points;
		
	}
	else
	{
		std::cout << "Cannot Read File!";
	}
	reader.close();
}


/*GAME WINDOW*/
Game::Game()
{
	// DISPLAY WINDOW;
	this->initialWindow();

	// MENU; Game Menu;
	this->initialBGMenu();
	this->initialHowTo();
	this->initialCredit();

	this->initialScoreboard();
	this->initialBGtype();

	this->initialTextures();

	// FONT & SCORE;
	this->initialGUI();
	//this->registername();

	// BACKGROUND;
	this->initialBG();
	this->initialBG1();
	this->initialBGSound();
	this->initialBGMenuSound();


	this->initialSystem();

	// PLAYER;
	this->initialPlayer();

	// ENEMIES;
	this->initialEnemies();
	this->initialRedEnemy();
	this->initialBlueEnemy();

	// ITEM;
	this->initialPotion();
	this->initialShield();

	
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	
	//delete textures;
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//delete bullets;
	for (auto* i : this->bullets)
	{
		delete i;
	}
	//delete enemies yellow flappy;
	for (auto* i : this->enemies)
	{
		delete i;
	}
	//delete red bird;
	for (auto* i : this->redenemy)
	{
		delete i;
	}
	//delete blue bird;
	for (auto* i : this->blueenemy)
	{
		delete i;
	}
	//delete potion;
	for (auto* i : this->potion)
	{
		delete i;
	}
	//delete shield;
	for (auto* i : this->shield)
	{
		delete i;
	}
}

void Game::checkStart()
{
	this->isGameStart = false; // Game hasn't start yet!


}

/*FUNCTIONS*/
void Game::run()
{
	while (this->window->isOpen()) // Game run;
	{
		this->updatePollEvents();
		if (this->player->getHp() > 0) // If player hp > 0;
		{
			this->updateDt();
			this->update();
			this->render();
		}
	}
}




void Game::updatePollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.Event::type == sf::Event::Closed)
			this->window->close();
		if (this->event.Event::KeyPressed&& this->event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();

		if (this->event.Event::KeyPressed && this->event.Event::key.code == sf::Keyboard::F2 || this->clickK)
		{
			this->clickK = true;
			this->blockMenu = true;
			if (this->clickK == true && this->event.type == sf::Event::TextEntered && this->event.text.unicode < 128)
			{
				std::cout << "" << this->event.key.code << std::endl;
				switch (this->event.key.code)
				{
				case 8: // backspace delete name
				
					if (this->playerName.size() == 0)
					{
						break;
					}
					this->playerName.pop_back();
					this->playerText.setString(this->playerName);
				
					break;

				case 13: // press enter button

					if (this->playerName.size() > 0)
					{

					this->clickK = false;
					this->isGameStart = true;  // check game --- start;
					this->music.play();
					this->menuMusic.stop();
					}
				break;
					
				default:
					if (this->playerName.size() > 5)
					{
						break;
					}
					this->playerName += this->event.text.unicode;
					this->playerText.setString(this->playerName);
				}
				
			}

		}
		if (this->event.Event::KeyPressed && this->event.Event::key.code == sf::Keyboard::F1)
		{
			this->KhamSang = 1;
			this->blockMenu = true;
			this->isGameStart = false; // check game --- close;
			this->player->gotShield = false;
			this->LobThangMod();
			this->player->setPosition(0.f, 450.f);
			this->menuMusic.play();


		}

		if (this->isGameStart == false)
		{
			if (this->event.Event::KeyPressed && this->event.Event::key.code == sf::Keyboard::F2)
			{
				this->blockMenu = true;
				this->KhamSang = 5;
			}
				
			if (this->blockMenu == true)
			{
				if (this->event.Event::KeyPressed && this->event.Event::key.code == sf::Keyboard::F3)	// How To Play
				{
					this->KhamSang = 2;
					this->isGameStart = false;
				}
				if (this->event.Event::KeyPressed && this->event.Event::key.code == sf::Keyboard::F4)	// Credit
				{
					this->KhamSang = 3;
					this->isGameStart = false;
				}
				if (this->event.Event::KeyPressed && this->event.Event::key.code == sf::Keyboard::C)
				{
					this->KhamSang = 4;
					this->isGameStart = false;
				}
			}

		}


		
	}
}

void Game::updateInput() // COMMAND BUTTON;
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->player->canAttack()) //press J = attack;
	{
		this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"],
			this->player->getPos().x + this->player->getBounds().height / 2.f,
			this->player->getPos().y+ this->player->getBounds().height/2.f, 1.f, 0.f, 7.f)
			);
		this->initialSound();
		
	}
	
}

void Game::updateGUI() // text or can change
{
	// TEXT
		std::stringstream ss;
		std::stringstream sc;

		ss << this->playerName << "  Points: " << this->points;
		this->pointText.setString(ss.str());

		sc << this->playerName << " : " << this->points;
		this->NowScore.setString(sc.str());


	// HP
		float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
		this->playerHpBar.setSize(sf::Vector2f(500.f * hpPercent, this->playerHpBar.getSize().y));
	
}


void Game::updateBG() // no need to update
{

}

void Game::updateBGSound()
{

}


/*void Game::updateMousePos()
{
	this->mouseScreen = sf::Mouse::getPosition();
	this->mouseWindow = sf::Mouse::getPosition(*this->window);
	this->mouseView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}*/

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bulet culling (top screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateEnemies() // yellow flappy
{
	// enemies spawning
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemies(1700.f, rand() % this->window->getSize().y + 100.f));
		this->spawnTimer = 0.f;
		
	}

	// update
	unsigned Fcounter = 0;
	for (auto* enemie : this->enemies)
	{
		enemie->update();

		// enemies culling (top screen)
		if (enemie->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->enemies.at(Fcounter);
			this->enemies.erase(this->enemies.begin() + Fcounter);

		}

		// Enemies & Player colission
		else if (enemie->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			if (this->haveShield == false)
			{
				this->initialHurtSound();
				this->player->loseHP(this->enemies.at(Fcounter)->getDamage());
				delete this->enemies.at(Fcounter);
				this->enemies.erase(this->enemies.begin() + Fcounter);
			}

			else if (this->haveShield == true)
			{
				this->initialShieldSound();
				this->numShield -= 1;
				delete this->enemies.at(Fcounter);
				this->enemies.erase(this->enemies.begin() + Fcounter);
			}
		}

		++Fcounter;
	}

}

void Game::updateRedEnemy() // red bird
{
	// redenemy spawning
	this->RedspawnTimer += 0.1f;
	if (this->RedspawnTimer >= this->RedspawnTimerMax)
	{
		this->redenemy.push_back(new RedEnemy(1700.f, rand() % this->window->getSize().y + 100.f));
		this->RedspawnTimer = 0.f;

	}

	// update
	unsigned Rcounter = 0;
	for (auto* redenem : this->redenemy)
	{
		redenem->update();

		// enemies culling (top screen)
		if (redenem->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->redenemy.at(Rcounter);
			this->redenemy.erase(this->redenemy.begin() + Rcounter);

		}

		// Enemies & Player colission
		else if (redenem->getBounds().intersects(this->player->getBounds()))
		{
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			if (this->haveShield == false)
			{
				this->initialHurtSound();
				this->player->loseHP(this->redenemy.at(Rcounter)->getDamage());
				delete this->redenemy.at(Rcounter);
				this->redenemy.erase(this->redenemy.begin() + Rcounter);
			}

			else if (this->haveShield == true)
			{
				this->initialShieldSound();
				this->numShield -= 1;
				delete this->redenemy.at(Rcounter);
				this->redenemy.erase(this->redenemy.begin() + Rcounter);
			}
		}

		++Rcounter;
	}
}

void Game::updateBlueEnemy()
{
	// blueenemy spawning
	this->BluespawnTimer += 0.1f;
	if (this->BluespawnTimer >= this->BluespawnTimerMax)
	{
		this->blueenemy.push_back(new BlueEnemy(1700.f, rand() % this->window->getSize().y + 100.f));
		this->BluespawnTimer = 0.f;

	}

	// update
	unsigned Bcounter = 0;
	for (auto* blueenem : this->blueenemy)
	{
		blueenem->update();

		// enemies culling (top screen)
		if (blueenem->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->blueenemy.at(Bcounter);
			this->blueenemy.erase(this->blueenemy.begin() + Bcounter);

		}

		// Enemies & Player colission
		else if (blueenem->getBounds().intersects(this->player->getBounds()))
		{
			this->initialHurtSound();
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			if (this->haveShield == false)
			{
				this->player->loseHP(this->blueenemy.at(Bcounter)->getDamage());
				delete this->blueenemy.at(Bcounter);
				this->blueenemy.erase(this->blueenemy.begin() + Bcounter);
			}
			
			else if (this->haveShield == true)
			{
				this->initialShieldSound();
				this->numShield -=1;
				delete this->blueenemy.at(Bcounter);
				this->blueenemy.erase(this->blueenemy.begin() + Bcounter);
			}
		}

		++Bcounter;
	}
}

void Game::updatePotion() // potion
{
	// potion spawning
	if (this->points < 1000)
	{
		this->PospawnTimer += 0.1f;
		if (this->PospawnTimer >= this->PospawnTimerMax)
		{
			this->potion.push_back(new Potion(1700.f, rand() % this->window->getSize().y + 100.f));
			this->PospawnTimer = 0.f;

		}
	}


	// update
	unsigned Pcounter = 0;
	for (auto* pot : this->potion)
	{
		pot->update();

		// enemies culling (top screen)
		if (pot->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete enemies
			delete this->potion.at(Pcounter);
			this->potion.erase(this->potion.begin() + Pcounter);

		}

		// Enemies & Player colission
		else if (pot->getBounds().intersects(this->player->getBounds()))
		{
			this->initialHealSound();
			// delete enemy W H I L E   H I T   T H E   P L A Y E R 
			this->player->loseHP(this->potion.at(Pcounter)->getDamage());
			delete this->potion.at(Pcounter);
			this->potion.erase(this->potion.begin() + Pcounter);

		}

		++Pcounter;
	}
}

void Game::updateShield()
{
	// shield spawning
	this->ShspawnTimer += 0.1f;
	if (this->ShspawnTimer >= this->ShspawnTimerMax)
	{
		this->shield.push_back(new Shield(1700.f, rand() % this->window->getSize().y + 100.f));
		this->ShspawnTimer = 0.f;

	}

	// update
	unsigned Scounter = 0;
	for (auto* shi : this->shield)
	{
		shi->update();

		// Item culling (top screen)
		if (shi->getBounds().left < this->window->getSize().y - 1700.f)
		{
			// delete shield
			delete this->shield.at(Scounter);
			this->shield.erase(this->shield.begin() + Scounter);

		}

		// Item & Player colission
		else if (shi->getBounds().intersects(this->player->getBounds()))
		{
			this->haveShield = true;
			this->numShield = 3;
			// delete shield W H I L E   H I T   T H E   P L A Y E R 
			this->player->loseHP(this->shield.at(Scounter)->getDamage());
			this->player->getShield(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);

			delete this->shield.at(Scounter);
			this->shield.erase(this->shield.begin() + Scounter);

		}

		++Scounter;
	}
}

void Game::checkShield()
{
	if (this->numShield <= 0)
	{
		// return
		this->numShield = 3;

		this->player->getShield(false, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
		this->haveShield = false;
	}
}

void Game::updateCombat() // Shooting & Get Points ----- After shooting diaapear
{
	// Yellow Flappy
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();

		for (size_t k = 0; k < this->bullets.size() && !enemy_removed; k++) // has been shot
		{

			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) // IF bullet touch the enemies
			{
				this->initialFlappySound();
				this->points += this->enemies[i]->getPoints();

				this->bullets.erase(this->bullets.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);

				enemy_removed = true;
			}
		}
	}

	// Red Bird
	for (int Ri = 0; Ri < this->redenemy.size(); ++Ri)
	{
		bool Renemy_removed = false;
		this->redenemy[Ri]->update();

		for (size_t Rk = 0; Rk < this->bullets.size() && !Renemy_removed; Rk++) // has been shot
		{

			if (this->bullets[Rk]->getBounds().intersects(this->redenemy[Ri]->getBounds())) // IF bullet touch the enemies
			{
				this->initialRedSound();
				this->points += this->redenemy[Ri]->getPoints();

				this->bullets.erase(this->bullets.begin() + Rk);
				this->redenemy.erase(this->redenemy.begin() + Ri);

				Renemy_removed = true;
			}
		}
	}

	// Blue Bird
	for (int Bi = 0; Bi < this->blueenemy.size(); ++Bi)
	{
		bool Benemy_removed = false;
		this->blueenemy[Bi]->update();

		for (size_t Bk = 0; Bk < this->bullets.size() && !Benemy_removed; Bk++) // has been shot
		{

			if (this->bullets[Bk]->getBounds().intersects(this->blueenemy[Bi]->getBounds())) // IF bullet touch the enemies
			{
				this->initialBlueSound();
				this->points += this->blueenemy[Bi]->getPoints();

				this->bullets.erase(this->bullets.begin() + Bk);
				this->blueenemy.erase(this->blueenemy.begin() + Bi);

				Benemy_removed = true;
			}
		}
	}

	// Potion
	for (int Pi = 0; Pi < this->potion.size(); ++Pi)
	{
		bool Penemy_removed = false;
		this->potion[Pi]->update();

		for (size_t Pk = 0; Pk < this->bullets.size() && !Penemy_removed; Pk++) // has been shot
		{

			if (this->bullets[Pk]->getBounds().intersects(this->potion[Pi]->getBounds())) // IF bullet touch the enemies
			{
				this->initialHPsound();
				this->points += this->potion[Pi]->getPoints();

				this->bullets.erase(this->bullets.begin() + Pk);
				this->potion.erase(this->potion.begin() + Pi);

				Penemy_removed = true;
			}
		}
	}
	// Shield
	/*for (int Si = 0; Si < this->shield.size(); ++Si)
	{
		bool Senemy_removed = false;
		this->shield[Si]->update();

		for (size_t Sk = 0; Sk < this->bullets.size() && !Senemy_removed; Sk++) // has been shot
		{

			if (this->bullets[Sk]->getBounds().intersects(this->shield[Si]->getBounds())) // IF bullet touch the enemies
			{
				this->points += this->shield[Si]->getPoints();

				this->bullets.erase(this->bullets.begin() + Sk);
				this->shield.erase(this->shield.begin() + Si);

				Senemy_removed = true;
			}
		}
	}*/

}


void Game::updateCollision()
{
	// left
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
		this->player->updateShield(+70.f, this->player->getBounds().top);
	}
	// right
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
		this->player->updateShield(this->window->getSize().x - this->player->getBounds().width +70.f, this->player->getBounds().top);
	}
	// top
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
		this->player->updateShield(this->player->getBounds().left +75.f, 0.f);
	}
	// down
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
		this->player->updateShield(this->player->getBounds().left +75.f, this->window->getSize().y - this->player->getBounds().height);
	}
}



void Game::renderBG()
{
	this->window->draw(this->background);
}


void Game::renderBG1()
{
	this->window->draw(this->background1);
}

void Game::renderHowTo()
{
	this->window->draw(this->HowRecShape);
}

void Game::renderCredit()
{
	this->window->draw(this->CreRecShape);
}


void Game::renderGUI()
{
	// TEXT
	this->window->draw(this->pointText);

	//HP
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	

}

void Game::renderBGMenu()
{
	this->window->draw(this->menuSprite);
}

void Game::updateAndSaveScore()
{
	typedef struct NameWithScore {
		std::string name;
		int score;
	} NameWithScore;

	auto compareScores = [](NameWithScore p_1, NameWithScore p_2) {
		return p_1.score > p_2.score;
	};

	std::vector<NameWithScore> namesWithScore;

	NameWithScore currentPlayer;
	currentPlayer.name = this->playerName;
	currentPlayer.score = this->points;

	namesWithScore.push_back(currentPlayer);

	std::ifstream ifs("Score.txt");

	if (ifs.is_open())
	{
		
		std::string playerName1 = "";
		std::string playerScore = "";

		while (ifs >> playerName1 >> playerScore)
		{
			//std::cout << "name0 ---> " << playerName1 << std::endl;
			//std::cout << "score0 ---> " << playerScore << std::endl;
			NameWithScore temp;
			temp.name = playerName1;
			temp.score = std::stoi(playerScore);
			namesWithScore.push_back(temp);
		
			
		}
		
		




	}

	ifs.close();

	std::sort(namesWithScore.begin(), namesWithScore.end(), compareScores);

	std::fstream ofs;

	ofs.open("Score.txt", std::ios::out | std::ios::trunc);

	for (auto nameWithScore : namesWithScore) {
		//std::cout << "name ---> " << nameWithScore.name << std::endl;
		//std::cout << "score ---> " << nameWithScore.score << std::endl;

		ofs << nameWithScore.name + "\t" + std::to_string(nameWithScore.score) + "\n";
	}

	ofs.close();
}

void Game::renderBGtype()
{
	this->window->draw(this->BGtypeRecShape);
}

void Game::renderScoreboard()
{
	this->window->draw(this->ScoreRecShape);
}



/*CLOSE WINDOW*/
void Game::update()
{
	//std::cout << this->mouseView.x << " " << this->mouseView.y << "\n";
	//this->updateMousePos();

	if (this->isGameStart) // yang mai start
	{
		this->updateInput();

		this->player->update();

		// UPDATE OBJECT

		this->updateBullets();
		this->updateEnemies();
		this->updateRedEnemy();
		this->updateBlueEnemy();

		this->updatePotion();
		this->updateShield();
		this->checkShield();


		this->updateCombat();


		this->updateCollision();

		this->updateGUI();

		this->updateBG();

		
		
	}


}

void Game::renderNameBoxAndText()
{
	if (this->clickK) //  == true จริงถึงจะเข้า
	{
		//this->window->draw(this->nameTTT);
		this->window->draw(this->playerText);
	}
}

void Game::updateDt()
{
	// update time to run

	this->dt = this->dtClock.getElapsedTime().asSeconds();
	
	//printf("\n Time : %f", this->dt);


}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::render() //render player
{
	this->window->clear();

	/*draw space*/

	if (!this->isGameStart) // game not start yet
	{
		
		if (this->KhamSang == 1)
		{
			this->playerName.clear();
			this->renderBGMenu();			// BGMenu
			this->music.stop();

		}	
		if (this->KhamSang == 2)			// How To Play
		{
			this->playerName.clear();
			this->renderHowTo();


			this->LobThangMod();
			this->music.stop();

		}
		if (this->KhamSang == 3)			// Credit
		{
			this->playerName.clear();
			this->renderCredit();


			this->LobThangMod();
			this->music.stop();

		}
		if (this->KhamSang == 5)			// Bgtype
		{
			this->renderBGtype();
			this->renderNameBoxAndText();
			this->LobThangMod();
			this->music.stop();

		}

	}
	
	else
	{
		
		this->renderBG();	  // BG
		this->renderBG1();	  // BG1
		this->renderPlayer(); // pilot
		this->renderGUI();	  // text health bar
		this->background.move(-1.5f, 0.f);
		this->background1.move(-1.5f, 0.f);
		if (this->background.getPosition().x < -6800.f)
		{
			this->background.setPosition(6800.f, 0.f);
		}
		if (this->background1.getPosition().x < -6800.f)
		{
			this->background1.setPosition(6800.f, 0.f);
		}
		for (auto* bullet : this->bullets)		// bullets
		{
			bullet->render(this->window);
		}

		for (auto* enemie : this->enemies)		// yellow flappy
		{
			enemie->render(*this->window);
		}
		for (auto* redenem : this->redenemy)	// red bird
		{
			redenem->render(*this->window);
		}
		for (auto* blueenem : this->blueenemy)	// blue bird
		{
			blueenem->render(*this->window);
		}
		for (auto* pot : this->potion)
		{
			pot->render(*this->window);			// potion
		}
		for (auto* shi : this->shield)
		{
			shi->render(*this->window);			// shield
		}

		/*display*/

		//game over
		
		if (this->player->getHp() <= 0)
		{
			this->renderScoreboard();		// Scoreboard
			//this->writeFileScore();
			this->updateAndSaveScore();
			
			this->readFileScore();
			
			//this->window->draw(this->gameOverText);
			this->window->draw(this->results);
			this->window->draw(this->NowScore);
			
			//this->window->draw(this->KhaNaen[0][0]);

			
			this->music.stop();
			this->initialHaha(); 
			
			this->playerName.clear();
			if (this->KhamSang == 2)
			{
				this->window->draw(this->ScoreRecShape);
				this->music.stop();
			}
			/*if (this->KhamSang == 5)
			{
				this->window->draw(this->BGtypeRecShape);
				this->music.stop();
			}*/
		}
		

	}

	
	this->window->display();
}

