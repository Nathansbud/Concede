//
//  Enemy.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Enemy.hpp"

Enemy::Enemy(int health, int maxHealth, int currency, ofImage &sprite, float x, float y) : super(health, maxHealth, currency, sprite, x, y) {
	
	SetType(EntityType::ENEMY);
}
