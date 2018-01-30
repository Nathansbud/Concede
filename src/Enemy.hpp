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

class Enemy : public Entity {
	public:
		Enemy(){};
		
		Enemy(EnemyName e, int health, int maxHealth, int currency, ofImage &sprite, float x, float y);
	
		~Enemy();
	
		EnemyName GetName() {return _e;}
	
		void GenerateMove();
		int GetMove() {return _move;}
	
		int GetBaseDMG() {return _damage[0];}
		int GetStrength() {return _damage[1];}
	

//		void Draw();
//		void Update();
	
	private:
		typedef Entity super;
	
		int _move;
	
		int _baseHP;
		int _maxHP;
	
		int _baseDMG;
		int _maxDMG;
	
		float _buff;
	
		int _damage[2]; //Base, Strength
	
		EnemyName _e;
};

#endif /* Enemy_hpp */
