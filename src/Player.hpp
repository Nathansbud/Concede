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
#include "Names.h"



class Player : public Entity {
	public:
		Player(){};
		Player(CharacterName c, int health, int maxHealth, int currency, ofImage &sprite, float x, float y);
	
		~Player(){};

	
	private:
		typedef Entity super;
		CharacterName _c;


};

#endif /* Player_hpp */
