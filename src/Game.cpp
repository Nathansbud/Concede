//
//  Game.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Game.hpp"




Game::Game() {
	LoadSprites();
	state = GameState::GAME;
	
}

Game::~Game() {
	
}

void Game::Draw() {
	if(state == GameState::GAME) {
		ofBackground(255, 255, 255);
		p.Draw();
		e.Draw();
	}
}



void Game::Update() {
	cout << p.GetCurrency() << endl;
}



void Game::LoadSprites() {
	for(int i = 0; i < CHAR_NUM; i++) {
		_characterSprites[i].load("characters/c" + to_string(i) + ".png");
	}
	
	for(int i = 0; i < ENEMY_NUM; i++) {
		_enemySprites[i].load("enemies/e" + to_string(i) + ".png");
	}
}

void Game::CreateEntity(EntityType t, int health, int currency, int sprite, float x, float y) {
	
	if(t == ENEMY) {
		e = Enemy(health, currency, _enemySprites[sprite], x, y);
	} else {
		p = Player(health, currency, _characterSprites[sprite], x, y);
	}
}
