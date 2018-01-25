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
	
	e = 0;
	delete e;
	
	
	o = 0;
	delete o;
	
	
	p = 0;
	delete p;
}



void Game::Draw() {
	ofBackground(255, 255, 255);
	CreateUI();
	if(state == BATTLE) {
		p->Draw();
		e->Draw();
		_playerButtons[0].Draw();
	}
}

void Game::Update() {
//	cout << e.GetCurrency() << endl;
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
			p = new Entity(health, maxHealth, currency, _characterSprites[sprite], x, y);
			break;
		case ENEMY:
			e = new Entity(health, maxHealth, currency, _enemySprites[sprite], x, y);
			break;
		case ENTITY:
			o = new Entity();
			break;
	}
}

void Game::CreateButton() {
//	auto buttonCall = std::bind(&Entity::ChangeHP, p, _1);
	
	
//	_b = Button(p, p.Draw(), "Test", 100, 100, 100, 100);

//	_b = Button(p, p.Draw(), "Hi", 100, 100, 100, 100);
//	void Button::Use(void (Entity::*function)(), Entity &en) {
//	(en.*function)();
	_playerButtons[0] = Button("Test", 350, 700, 100, 50);
	
}

void Game::CreateUI() {
	ofSetColor(0, 0, 0);
	
	switch(state) {
		case TITLE:
			break;
		case OVERWORLD:
			break;
		case BATTLE:
			
			ofDrawBitmapString("Hit Points: " + to_string(p->GetHP()) + "/" + to_string(p->GetMaxHP()), 100, 100);
			ofDrawBitmapString("Gold: " + to_string(p->GetCurrency()), 100, 150);
			CreateButton();
			
			//
			
			ofDrawBitmapString("Enemy Hit Points: " + to_string(e->GetHP()) + "/" + to_string(e->GetMaxHP()), 1000, 100);
			ofDrawBitmapString("Gold: " + to_string(e->GetCurrency()), 1000, 150);
			
			break;
		case DEATH:
			break;
	}
	
	
	
}
