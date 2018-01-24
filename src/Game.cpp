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
	state = BATTLE;
	
}

Game::~Game() {
	
}



void Game::Draw() {
	ofBackground(255, 255, 255);
	CreateUI();
	if(state == BATTLE) {
		p.Draw();
		e.Draw();
	}
}

void Game::Update() {
	cout << e.GetCurrency() << endl;
}



void Game::LoadSprites() {
	for(int i = 0; i < CHAR_NUM; i++) {
		_characterSprites[i].load("characters/c" + to_string(i) + ".png");
	}
	
	for(int i = 0; i < ENEMY_NUM; i++) {
		_enemySprites[i].load("enemies/e" + to_string(i) + ".png");
	}
}

void Game::CreateEntity(EntityType t, int health, int maxHealth, int currency, int sprite, float x, float y) {
	
	switch(t) {
		case PLAYER:
			p = Entity(health, maxHealth, currency, _characterSprites[sprite], x, y);
			break;
		case ENEMY:
			e = Entity(health, maxHealth, currency, _enemySprites[sprite], x, y);
			break;
		case ENTITY:
			o = Entity();
			break;
	}
}

void Game::CreateUI() {
	ofSetColor(0, 0, 0);
	
	switch(state) {
		case TITLE:
			break;
		case OVERWORLD:
			break;
		case BATTLE:
			ofDrawBitmapString("Hit Points: " + to_string(p.GetHP()) + "/" + to_string(p.GetMaxHP()), 100, 100);
			ofDrawBitmapString("Gold: " + to_string(p.GetCurrency()), 100, 150);
			break;
		case DEATH:
			break;
	}
}
