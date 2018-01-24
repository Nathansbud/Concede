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
//	Settings();

	state = GameState::GAME;
	
}

Game::~Game() {
	
}

void Game::Draw() {
	if(state == GameState::GAME) {
		CreateUI();
		ofBackground(255, 255, 255);
		p.Draw();
		e.Draw();
	}
}



void Game::Update() {
//	p.Update();
//	e.Update();
//	cout << p.GetCurrency() << endl;
}

void Game::Settings() {
	ofSetBackgroundColor(255, 255, 255);
	ofSetColor(0, 0, 0);
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
	
	switch(t) {
		case ENEMY:
			e = Enemy(health, currency, _enemySprites[sprite], x, y);
			break;

		case PLAYER:
			p = Player(health, currency, _characterSprites[sprite], x, y);
			break;

		default:
//			en = Entity(health, currency, _characterSprites[sprite], x, y);
			break;
			
	}
}

void Game::CreateUI() {
	ofDrawBitmapString("Work pls", 100, 100);
//	ofDrawBitmapString(to_string(p.GetCurrency()), 100, 100);
}
