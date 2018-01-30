//
//  Entity.hpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <map>
#include <vector>

#include "ofImage.h"
#include "ofGraphics.h"

#include "Names.h"

enum ActionType {
	ATTACK,
	DEFEND,
	HEAL,
	STATUS,
	BUFF
};

class Entity {
	public:
		Entity(){};
	
		Entity(ofImage &sprite, float stats[7], int x, int y);
	
		Entity(ofImage sprite, int x, int y); //For use for potraits; character select screen
		~Entity();
	
		virtual void Draw();
		virtual void Update();
	
		void SetPos(float x, float y);
	
	
	
		int GetDef() {return _def;}
		
		
		int GetHP() {return _stats[0];}
		int GetMaxHP() {return _stats[1];}
		int GetCurrency() {return _stats[2];}
	
		EntityType GetType() {return _t;}
	
		void ChangeHP(int amount) {_stats[0] += amount;}
		void ChangeCurrency(int amount) {_stats[2] += amount;}
		void ChangeDef(int amount) {_def += amount;}
	
		void TakeDamage(int amount);


	
		static const int SPRITE_W = 350;
		static const int SPRITE_H = 350;
	
		float GetX() {return _spritePos[0];}
		float GetY() {return _spritePos[1];}
	
		float GetW() {return SPRITE_W;}
		float GetH() {return SPRITE_H;}
		
		float GetWX() {return _spritePos[0] + 350;}
		float GetHY() {return _spritePos[1] + 350;}
	
	protected:
		void SetType(EntityType t) { _t = t;}
		void SetHP(int value) {_stats[0] = value;}
		void SetCurrency(int value) {_stats[2] = value;}
		void SetSprite(ofImage &sprite) {_sprite = sprite;}
	
	private:
		float _stats[7];
	
	
	
		int _def = 0;
		int _health[2];
		int _currency;
		EntityType _t;
		string _entityName;
		
		void LoadSprites();
		ofImage _sprite;
		float _spritePos[2];

};

#endif /* Entity_hpp */
