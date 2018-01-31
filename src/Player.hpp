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
		Player(CharacterName c, ofImage &sprite, float stats[9], float x, float y);
	
		~Player(){};
	
		CharacterName GetName() {return _c;}

	
	private:
		typedef Entity super;
		CharacterName _c;


};

#endif /* Player_hpp */
