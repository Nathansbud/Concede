//
//  Game.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Game.hpp"

Game::Game() {
	_state = BATTLE;
	LoadData();
	SetMusic();
	CreateButtons();
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
	CreateUI();
	
	switch(_state) {
		case TITLE:
			break;
		case OVERWORLD:
			break;
		case BATTLE:
			
			p->Draw();
			e->Draw();
			
			for(Button b : _playerButtons) {
				b.Draw();
			}
			
			_submitButton.Draw();
			
			break;
		case BATTLE_WIN:
			break;
		case DEATH:
			ofSetColor(255, 255, 255);
			ofDrawBitmapString("You died. Restart?", ofGetWidth()/2, ofGetHeight()/2);
			
			
			break;
			
	}
}

void Game::Update() {
	if(_state == BATTLE) {
		if(e->GetHP() <= 0 || e->GetCurrency() <= 0) {
			p->ChangeCurrency(e->GetCurrency());
			SetState(BATTLE_WIN);
		}
	}
	
	if(_state == BATTLE_WIN) {
		_turn = 1;
		
	}
}


void Game::LoadData() {
	for(int i = 0; i < CHAR_NUM; i++) {
		_characterSprites[i].load("characters/c" + to_string(i) + ".png");
	}
	
	for(int i = 0; i < ENEMY_NUM; i++) {
		_enemySprites[i].load("enemies/e" + to_string(i) + ".png");
	}
	
	for(int i = 0; i < UI_NUM; i++) {
		_uiSprites[i].load("ui/u" + to_string(i) + ".png");
	}
	
	
	for(int i = 0; i < MUSIC_NUM; i++) {
		_music[i].load("music/m" + to_string(i) + ".mp3");
		_music[i].setLoop(true);
	}
}

void Game::CreateEntity(EntityType t, int health, int maxHealth, int currency, int sprite, float x, float y) {
	switch(t) {
		case EntityType::PLAYER:
			p = new Player((CharacterName)sprite, health, maxHealth, currency, _characterSprites[sprite], x, y);
			break;
		case EntityType::ENEMY:
			e = new Enemy((EnemyName)sprite, health, maxHealth, currency, _enemySprites[sprite], x, y);
			break;
		case EntityType::ENTITY:
			o = new Entity();
			break;
	}
}

void Game::CreateButtons() {
	switch(_state) {
		case BATTLE:
			_playerButtons[0] = Button("Attack!", 12, -1, 200, 700, 100, 50); //Hit for {x}
			_playerButtons[1] = Button("Defend!", 8, -3, 350, 700, 100, 50); //Block {x}
			_playerButtons[2] = Button("Thieve!", -5, 5, 500, 700, 100, 50); //Steal {x}, gain {x}
			_submitButton = Button("Submit", 350, 825, 100, 50); //Submit action for the turn
			break;
		default:
			break;
			
	}
}

void Game::CreateUI() {
	
	switch(_state) {
		case TITLE:
			break;
		case OVERWORLD:
			break;
		case BATTLE:
			ofBackground(255, 255, 255);
			ofSetColor(0, 0, 0);

			ofDrawBitmapString("Hit Points: " + to_string(p->GetHP()) + "/" + to_string(p->GetMaxHP()), 100, 100);
			ofDrawBitmapString("Gold: " + to_string(p->GetCurrency()), 100, 125);
			ofDrawBitmapString(_characterNames[p->GetName()], p->GetX() + p->GetW()/2.75, p->GetY() - p->GetH()/10); //Player Name
			
			ofDrawBitmapString("Hit Points: " + to_string(e->GetHP()) + "/" + to_string(e->GetMaxHP()), 1000, 100);
			ofDrawBitmapString("Gold: " + to_string(e->GetCurrency()), 1000, 125);
			ofDrawBitmapString(_enemyNames[e->GetName()], e->GetX() + e->GetW()/2.75, e->GetY() - e->GetH()/10);
			
			ofDrawBitmapString("Turn " + to_string(GetTurn()), p->GetWX() + (e->GetX() - p->GetWX()), p->GetHY() + 100);
			
			DrawUIElement(HEALTH, 100, 100, true, -1, -0.57);
			DrawUIElement(GOLD, 100, 125, true, -1, -0.57);
			DrawUIElement(VERSUS, 450, 225, true, 0.25, -1);
			
			ofSetColor(0, 0, 0);
			
			if(_playerButtons[0].isSelected) {
			
				ofDrawBitmapString("- Deal " + to_string((int)_playerButtons[0].GetVal()) + " Damage", _playerButtons[0].GetX(), _playerButtons[0].GetY() + _playerButtons[0].GetH() + 25);
				
				ofDrawBitmapString("- Spend " + to_string(_playerButtons[0].GetCost()*-1) + " Gold", _playerButtons[0].GetX(), _playerButtons[0].GetY() + _playerButtons[0].GetH() + 50);
				
			}else if(_playerButtons[1].isSelected) {
			
				ofDrawBitmapString("- Block " + to_string((int)_playerButtons[1].GetVal()) + " Damage", _playerButtons[1].GetX(), _playerButtons[1].GetY() + _playerButtons[1].GetH() + 25);
				
				ofDrawBitmapString("- Spend " + to_string(_playerButtons[1].GetCost() * -1) + " Gold", _playerButtons[1].GetX(), _playerButtons[1].GetY() + _playerButtons[1].GetH() + 50);
				
			} else if(_playerButtons[2].isSelected) {
				
				ofDrawBitmapString("- Enemy Loses " + to_string((int)_playerButtons[2].GetVal() * -1) + " Gold", _playerButtons[2].GetX(), _playerButtons[2].GetY() + _playerButtons[2].GetH() + 25);
				
				ofDrawBitmapString("- Gain " + to_string(_playerButtons[2].GetCost()) + " Gold", _playerButtons[2].GetX(), _playerButtons[2].GetY() + _playerButtons[2].GetH() + 50);
			}
			
			
			ofSetColor(255, 255, 255);
			break;
		case BATTLE_WIN:
			ofBackground(0, 0, 0);
			ofSetColor(255, 255, 255);
			if(e->GetHP() <= 0) {
				ofDrawBitmapString("Victory! " + _enemyNames[e->GetName()] + " was defeated, and you gained...", ofGetWidth()/3, ofGetHeight()/2);
				ofDrawBitmapString(" - " +to_string(e->GetCurrency()) + " Gold", ofGetWidth()/3, ofGetHeight()/2 + 50);
				
				ofDrawBitmapString("Your gold total is now " + to_string(p->GetCurrency()) + " Gold!", ofGetWidth()/3, ofGetHeight()/2 + 150);
			} else if(e->GetCurrency() <= 0) {
				ofDrawBitmapString("Victory! " + _enemyNames[e->GetName()] + " ran out of Gold, and was unable to continue!", ofGetWidth()/3, ofGetHeight()/2);
			}
			break;
		case DEATH:
			ofBackground(0, 0, 0);
			ofDrawBitmapString("You died. Restart?", ofGetWidth()/2, ofGetHeight()/2);
			break;
	}
}

void Game::DrawUIElement(UISprite sprite, float x, float y, bool selfShift, float xscl, float yscl) {
	ofSetColor(255, 255, 255);
	if(selfShift) {
		_uiSprites[sprite].draw(x + _uiSprites[sprite].getWidth()*xscl, y + _uiSprites[sprite].getHeight()*yscl);
	} else {
		_uiSprites[sprite].draw(x, y);
	}
}

void Game::SetMusic() {
	switch(_state) {
		case TITLE:
			break;
		
		case OVERWORLD:
			break;
	
		case BATTLE:
//			_music[1].play(); //Commented out because oml I can't deal with it while developing
			break;
		case BATTLE_WIN:
			break;
			
		case DEATH:
			break;
	}
}
