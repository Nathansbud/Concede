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
		Enemy();
		~Enemy();
	
		void Draw();
		void Update();
	
	private:
		//
};

#endif /* Enemy_hpp */
