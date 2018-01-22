//
//  Game.hpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Player.hpp"
#include "Enemy.hpp"



class Game {
	public:
		Game();
		~Game();
	
		void Update();
		void Draw();
	
	private:
		Player p;
		
	
};

#endif /* Game_hpp */
