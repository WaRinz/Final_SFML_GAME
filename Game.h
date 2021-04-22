#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

#include<cstdlib>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<utility>

// PLAYER PART
#include"Player.h"
#include"Bullet.h"

// ENEMIES PART
#include"Enemies.h"
#include"RedEnemy.h"
#include"BlueEnemy.h"

// ITEM PART
#include"Potion.h"
#include"Shield.h"

// SCORE PART
#include<algorithm>
#include<fstream>


class Game
{
private:
	/* WINDOW */
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	sf::Clock dtClock;
	sf::Time time = sf::seconds(1.f);
	float dt;

	// ICON
	sf::Image icon;
	// GUI
	sf::Font font;

	sf::Text pointText;
	

	sf::Text gameOverText;

	// your score :
	sf::Text results;
	sf::Text NowScore;

	// S Y S T E M  -------  SCORE
	int points;
	int save_point;
	int numShield = 3;
	bool haveShield = false;
	bool clickK = false;
	bool blockMenu = false;

	sf::RectangleShape nameTTT;

	std::string playerName = "";
	sf::Text playerText;

	// --- MENU ----
		
	// Menu BG
		sf::Texture menuTexture;
		sf::RectangleShape menuSprite;
		bool isGameStart;
		
		// Typre Text Art
		sf::Texture BGtypeTex;
		sf::RectangleShape BGtypeRecShape;

		// Scoreboard
		sf::Texture ScoreTex;
		sf::RectangleShape ScoreRecShape;

		// How To
		sf::Texture HowTex;
		sf::RectangleShape HowRecShape;

		// Credits
		sf::Texture CreTex;
		sf::RectangleShape CreRecShape;


		
		// Menu Button
		sf::Vector2i mouseScreen;
		sf::Vector2i mouseWindow;
		sf::Vector2f mouseView;





	/* PILOT */
	Player* player;

	sf::RectangleShape playerHpBar;			//MAX
	sf::RectangleShape playerHpBarBack;		//DECREASE

	/* ENEMIES --- FLAPPY */
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemies*> enemies;

	/* ENEMIES --- RED BIRD */
	float RedspawnTimer;
	float RedspawnTimerMax;
	std::vector<RedEnemy*> redenemy;

	/* ENEMIES --- BLUE BIRD */
	float BluespawnTimer;
	float BluespawnTimerMax;
	std::vector<BlueEnemy*> blueenemy;
	
	int KhamSang = 1;
	/* POTION --- HEALTH */
	float PospawnTimer;
	float PospawnTimerMax;
	std::vector<Potion*> potion;

	/* SHIELD --- PROTECT */
	float ShspawnTimer;
	float ShspawnTimerMax;
	std::vector<Shield*> shield;

	/* SLIME --- GREEN SLIME */
	float Slspawntimer;
	float Slspawntimermax;
	//std::vector<Slime*> slime;

	/* Separate text */
	std::vector<std::vector<std::string>> GaebKhaNaen;
	sf::Text KhaNaen[5][5];

	// SOUND hit
	sf::SoundBuffer buffer;
	sf::Sound sound;
	// game over haha
	sf::SoundBuffer bufflol;
	sf::Sound haha;

	// HP Potion break
	sf::SoundBuffer buffHP;
	sf::Sound soundHP;

	// Touch potion
	sf::SoundBuffer buffHeal;
	sf::Sound soundHeal;

	// Take damage
	sf::SoundBuffer buffHurt;
	sf::Sound soundHurt;

	// Shield block
	sf::SoundBuffer buffShield;
	sf::Sound soundShield;

	// Blue Die
	sf::SoundBuffer buffBlue;
	sf::Sound soundBlue;

	// Flappy Die
	sf::SoundBuffer buffFlappy;
	sf::Sound soundFlappy;

	// Red Die
	sf::SoundBuffer buffRed;
	sf::Sound soundRed;

	// BG music
	sf::Music music;
	sf::Music menuMusic;

	// BG
	sf::Texture bgTexture;
	sf::RectangleShape background;
	sf::Texture bgTexture1;
	sf::RectangleShape background1;


	void initialWindow();
	void initialTextures();

	void initialGUI();
	void initialBG();
	void initialBG1();
	void initialBGSound();
	void initialBGMenuSound();
	
	// Board State
	void initialBGMenu();
	void initialBGtype();
	void initialHowTo();
	void initialCredit();
	void initialScoreboard();
	void registername();

	void initialSystem();
	void writeFileScore();
	void readFileScore();

	// OBJECT
	void initialPlayer();
	void initialEnemies();
	void initialRedEnemy();
	void initialBlueEnemy();
	void initialPotion();
	void initialShield();

	void initialSound();
	void initialHaha();
	void initialFlappySound();
	void initialRedSound();
	void initialBlueSound();
	void initialHPsound();
	void initialHealSound();
	void initialHurtSound();
	void initialShieldSound();

	// CLEAN ALL
	void LobThangMod();

	


public:
	sf::Event event;
	Game();
	virtual ~Game();
	
	/*FUNCTIONS*/

	

	void checkStart();

	void run();

	void updatePollEvents();
	void updateInput();

	// UPDATE OBJECT
	void updateBullets();
	void updateEnemies();
	void updateRedEnemy();
	void updateBlueEnemy();
	void updatePotion();
	
	void updateShield();
	void checkShield();

	// UPDATE SCORE AND SAVE SCORE
	void updateAndSaveScore();

	void updateCombat();

	void updateCollision();
	void updateGUI();

	void updateBG();// no need
	void updateBGSound();


	// --- MENU ---
	//void updateMousePos();



	void updateDt();

	// import player
	void renderPlayer();

	// import bg textures
	void renderBG();
	void renderBG1();

	// show score number
	void showSCnum();

	// import font text & health bar
	void renderGUI();

	// import board
	void renderBGMenu();
	void renderBGtype();
	void renderHowTo();
	void renderCredit();
	void renderScoreboard();

	// textNameBox
	void renderNameBoxAndText();


	void update(); // Game update(ME); = update player(You)
	
			/*	this->updatePollEvents();
		this->updateInput();

		this->player->update();// updatePlayer

		this->updateBullets();	*/


	void render();
};

