//
//  Enemy.hpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "Player.hpp"

/*Moves:
	- 0, 1: Attack
	- 2, 8: Steal,
	- 3, 4: Defend
*/

class Enemy : public Entity {
	public:
		Enemy(){};
		
		Enemy(EnemyName e, ofImage &sprite, float stats[9], float x, float y);
	
		~Enemy();
	
		EnemyName GetName() {return _e;}
	
		
		void GenerateMove();
		void SetMove(int val) {_move = val;}
		void MakeMove();
		void SetTarget(Player *target) {_target = target;}
	
		int GetMove() {return _move;}
	
	

//		void Draw();
//		void Update();
	
	private:
		typedef Entity super;
		EnemyName _e;
		int _move;
		Player* _target;
};

#endif /* Enemy_hpp */
