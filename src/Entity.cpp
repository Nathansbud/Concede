//
//  Entity.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Entity.hpp"
#include <vector>




Entity::Entity(int health, int currency, ofImage& sprite, int x, int y) {
	_health = health;
	_currency = currency;
	SetSprite(sprite);
	SetPos(x, y);
}

Entity::~Entity() {
//	delete _sprite;
//	_sprite = 0;
}

void Entity::SetPos(float x, float y) {
	_spritePos[0] = x;
	_spritePos[1] = y;
	
}

void Entity::Draw() {
	_sprite.draw(_spritePos[0], _spritePos[1]);
}

void Entity::Update() {

}
