//
//  Player.hpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "ofImage.h"

class Player : public Entity {
	public:
		Player(){};
	
		Player(int health, int currency, ofImage sprite, float x, float y);
		~Player();
////	
////	void Draw();
//		void Update();
	
	private:
		typedef Entity super;
};

#endif /* Player_hpp */
