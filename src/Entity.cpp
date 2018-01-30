//
//  Entity.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Entity.hpp"

Entity::Entity(ofImage &sprite, float stats[7], int x, int y) {
	SetSprite(sprite);
	SetPos(x, y);
	for(int i = 0; i < 7; i++) {
		_stats[i] = stats[i];
	}
}

Entity::~Entity() {
	
}

void Entity::SetPos(float x, float y) {
	_spritePos[0] = x;
	_spritePos[1] = y;
	
}

void Entity::Draw() {
	ofSetColor(255, 255, 255);
	ofNoFill();
	
	_sprite.draw(_spritePos[0], _spritePos[1]);
}

void Entity::TakeDamage(int amount) {
	int dmg = GetDef() - amount;
	
	if(dmg < 0) {
		ChangeHP(dmg);
	} else {
		cout << "Attack was blocked!" << endl;
	}
}

void Entity::Update() {
	
}
