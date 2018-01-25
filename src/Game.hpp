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
#include "Button.hpp"

#include "ofMain.h"

using namespace std::placeholders;

enum GameState {
    TITLE,
    OVERWORLD,
	BATTLE,
    DEATH
};

class Game {
	public:
		Game();
		~Game();
	
        void Update();
		void Draw();
	
        void CreateUI();

	
		static const int CHAR_NUM = 3;
		static const int ENEMY_NUM = 3;
    
        void CreateEntity(EntityType t, int health, int maxHealth, int currency, int sprite, float x, float y);
    
		Entity& GetPlayer() {return *p;}

	private:
		void CreateButton();
		void LoadSprites();
	
//		Player p;
	
		Entity *p;
        Entity *e;
		Entity *o;
	
        Button _playerButtons[2];

        GameState state;
    
		ofImage _characterSprites[CHAR_NUM];
		ofImage _enemySprites[ENEMY_NUM];
		
};

#endif /* Game_hpp */
