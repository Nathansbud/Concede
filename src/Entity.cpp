//
//  Entity.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Entity.hpp"
#include <vector>




Entity::Entity(int health, int currency, ofImage sprite, int x, int y) {
	_sprite = sprite;
	_health = health;
	_currency = currency;
	SetPos(x, y);
}

Entity::~Entity() {
	
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

//void Entity::SetSprite(ofImage sprite) {
//
//}
