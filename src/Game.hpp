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
#include <map>

#include "ofMain.h"

#include "Names.h"

#include "Player.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "Button.hpp"



/*

Names & Such:

PLAYER NAMES (PlayerName : String)

- JIM : Jim
- KRATE : Krate
- GEOFF : Geoff

ENEMY NAMES (EnemyName : String)

- CORPSE : Corpse
- WALKING_CORPSE : Walking Corpse
- PANTS : Regular Pants
- SHIRT : Regular Shirt
- HAT : Regular Hat
- EYES : Maneyes
- ALPHABET_A : Alphabet (Variant A)
- ALPHABET_B : Alphabet (Variant B)

*/


enum GameState {
    TITLE,
    OVERWORLD,
	BATTLE,
    BATTLE_WIN,
    DEATH
};

enum UISprite {
	HEALTH,
	GOLD,
	VERSUS
};

class Game {
	public:
		Game();
		~Game();
	
        void Update();
		void Draw();
    
        void SetMusic();
        void CreateUI();
	
	

        static const int ENTITY_NUM = 1;
		static const int CHAR_NUM = 3;
		static const int ENEMY_NUM = 8;
        static const int UI_NUM = 3;
        static const int MUSIC_NUM = 2;
	
        void CreateEntity(EntityType t, int health, int maxHealth, int currency, int sprite, float x, float y);
	
	
		void SetState(GameState state) {_state = state;}
		GameState GetState() {return _state;}
	
		Player& GetPlayer() {return *p;}
		Enemy& GetEnemy() {return *e;}
		Button& GetButton(int index) {return _playerButtons[index];}

		static const int UI_ELEM_SIZE = 30;
	
	
	private:
		void CreateButtons();
		void LoadData();
		
		Player *p;
        Enemy *e;
		Entity *o;
	
        Button _playerButtons[2];
	
        GameState _state;
	
		void DrawUIElement(UISprite sprite, float x, float y, bool selfShift = false, float xscl = 0, float yscl = 0);
	
		ofImage _characterSprites[CHAR_NUM];
		ofImage _enemySprites[ENEMY_NUM];
        ofImage _uiSprites[UI_NUM];
        ofSoundPlayer _music[MUSIC_NUM];

        string _userName;
    
        string _entityNames[ENTITY_NUM] = {
            "Merchant"
        };
    
        string _characterNames[CHAR_NUM] = {
            "Jim",
            "Krate",
            "Geoff"
        };


        string _enemyNames[ENEMY_NUM] = {
            "Corpse",
            "Walking Corpse",
            "Regular Pair of Pants",
            "Regular Shirt",
            "Regular Hat",
            "All-Eyes",
            "Alphabet (Variant A)",
            "Alphabet (Variant B)"
        };    
};

#endif /* Game_hpp */
