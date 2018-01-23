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
#include "Entity.hpp"

#include "ofMain.h"

enum class GameState {
    TITLE,
    GAME,
    DEATH
};

class Game {
	public:
		Game();
		~Game();
	
        void Update();
		void Draw();
	
		static const int CHAR_NUM = 3;
		static const int ENEMY_NUM = 3;
    
        void CreateEntity(EntityType t, int health, int currency, int sprite, float x, float y);
        
	private:
		void LoadSprites();
	
		Player p;
		Enemy e;
	
        GameState state;
    
		ofImage _characterSprites[CHAR_NUM];
		ofImage _enemySprites[ENEMY_NUM];
		
};

#endif /* Game_hpp */
