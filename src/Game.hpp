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

	
		static const int CHAR_NUM = 3;
		static const int ENEMY_NUM = 8;
        static const int UI_NUM = 3;
        static const int MUSIC_NUM = 2;
	
        void CreateEntity(EntityType t, int health, int maxHealth, int currency, int sprite, float x, float y);
    
		Entity& GetPlayer() {return *p;}
		Button& GetButton(int index) {return _playerButtons[index];}

		static const int UI_ELEM_SIZE = 30;
	
	
//        const std::map<CharacterName, string> _enemyNameToString {
////			{CORPSE, "Corpse"},
////			{WALKING_CORPSE, "Walking Corpse"},
////			{PANTS, "Ordinary Pants"},
////			{SHIRT, "Ordinary Shirt"},
////			{HAT, "Ordinary Hat"},
////			{EYES, "Maneyes"},
////			{ALPHABET_A, "Alphabet (Variant A)"},
////			{ALPHABET_B, "Alphabet (Variant B)"},
//		};
//    
//        const std::map<EnemyName, string> _characterNameToString {
////            {JIM, "Jim"},
////            {BOX, "Krate"},
////            {FLOAT, "Geoff"}
//        };

	private:
		void CreateButton();
		void LoadData();
		
		Entity *p;
        Entity *e;
		Entity *o;
	
        Button _playerButtons[2];

        GameState _state;
	
		void DrawUIElement(UISprite sprite, float x, float y, bool selfShift = false, float xscl = 0, float yscl = 0);

	
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
	
		ofImage _characterSprites[CHAR_NUM];
		ofImage _enemySprites[ENEMY_NUM];
        ofImage _uiSprites[UI_NUM];
        ofSoundPlayer _music[MUSIC_NUM];

        string _userName;
    
};

#endif /* Game_hpp */
