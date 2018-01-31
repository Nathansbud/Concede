//
//  Enemy.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Enemy.hpp"

Enemy::Enemy(EnemyName e, ofImage &sprite, float stats[9], float x, float y) : super(sprite, stats, x, y) {
	
	SetType(EntityType::ENEMY);
	_e = e;
	GenerateMove();
}

Enemy::~Enemy() {
	_target = 0;
	delete _target;
}

void Enemy::GenerateMove() {
	_move = rand() % 9;
}



void Enemy::MakeMove() {
	switch(_move) {
		case 0:
		case 1:
			_target->TakeDamage(GetDamage());
			ChangeCurrency(-2);
			cout << "Dealt Damage: " << to_string(GetDamage()) << endl;

			break;
		case 2:
		case 8: //Steal
			_target->ChangeCurrency(GetSteal());
			ChangeCurrency(GetSteal());
			cout << "Stole Gold: " << to_string(GetSteal()) << endl;
			break;
		case 3:
		case 4:
			SetShielded(true);
			break;
		case 5:
			break;
			
		default:
			cout << "Generated move with unimplemented behavior" << endl;
			break;
	
	}
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
