//
//  Enemy.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Enemy.hpp"

Enemy::Enemy(EnemyName e, ofImage &sprite, float stats[8], float x, float y) : super(sprite, stats, x, y) {
	
	SetType(EntityType::ENEMY);
	_e = e;
//	_damage[0] = baseDamage;
//	_damage[1] = maxDamage;
}

Enemy::~Enemy() {

}

//void Enemy::GenerateMove() {
//	int move = rand() % 4; //Attack, Defend, Steal, Buff
//	_move = move;
////	SetMove(move);
//}

//void Enemy::MakeMove() {
//	if(move == )
//}

//Walking Corpse Stats
