#pragma once
#include "SFML/Graphics.hpp"
#include "player.h"
#include"const.h"
#include"river.h"
#include"barier.h"
class Game {
public:
	enum GameState { INTRO, PLAY, GAME_OVER };
	Game();
	void play();
	void check_events();
	void update();
	void draw();
	void check_collisions();

private:
	sf::RenderWindow window;
	GameState game_state = PLAY;
	Player player;
	std::vector<Barier*> bariers;
	River river1, river2;
	

	
};