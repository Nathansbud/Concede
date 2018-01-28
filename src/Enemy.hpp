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
		
		Enemy(int health, int maxHealth, int currency, ofImage &sprite, float x, float y);
	
		~Enemy();
	
//		void Draw();
//		void Update();
	
	private:
		typedef Entity super;
		EnemyName _e;
	
};

#endif /* Enemy_hpp */
