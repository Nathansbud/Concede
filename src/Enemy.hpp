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
	
//		void Draw();
//		void Update();
	
	private:
		typedef Entity super;
		EnemyName _e;
	
};

#endif /* Enemy_hpp */
