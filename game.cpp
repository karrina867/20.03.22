#include "game.h"
#include "const.h"
#include <iostream>

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close),
	river1(0.f, 0.f),
	river2(0.f, -WINDOW_HEIGHT)
	
{
	window.setVerticalSyncEnabled(true);
	for (size_t i = 0; i < BARIER_QTY; i++) {
		Barier* barier= new Barier();
		bariers.push_back(barier);
	}
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
	}
}

void Game::update() {
	switch (game_state) {
	case INTRO:
		break;

	case PLAY:
		river1.update();
		river2.update();
		player.update();
		for (size_t i = 0; i < BARIER_QTY; i++) {
			bariers[i]->update();
		}
		break;

	case GAME_OVER:
		break;

	}

}
	void Game::draw() {
		window.clear(sf::Color::Black);
		switch (game_state) {
		case INTRO:
			break;
		case PLAY:
			river2.draw(window);
			river1.draw(window);
			player.draw(window);
			for (size_t i = 0; i < BARIER_QTY; i++) {
				bariers[i]->draw(window);
			}
			break;

		}
		window.display();

	}
	void Game::check_collisions() {}