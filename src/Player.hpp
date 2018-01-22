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
	
		Player(int health, int currency);
		~Player();
	
		void Draw();
		void Update();
	
	private:
		ofImage _sprite;
		
		
};

#endif /* Player_hpp */
