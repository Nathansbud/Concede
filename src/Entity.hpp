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


class Entity {
	public:
		Entity(){};
	
	
		Entity(int health, int maxHealth, int currency, ofImage &sprite, int x, int y);
		Entity(ofImage sprite, int x, int y); //For use for potraits; character select screen
		~Entity();
	
		virtual void Draw();
		virtual void Update();
	
		void SetPos(float x, float y);
	
	
		int GetHP() {return _health[0];}
		int GetMaxHP() {return _health[1];}
		int GetCurrency() {return _currency;}
		EntityType GetType() {return _t;}
	
		void ChangeHP(int amount) {_health[0] += amount;}

	
		static const int SPRITE_W = 350;
		static const int SPRITE_H = 350;
	
		//Player Pos = {500 (+ 350), }

	
	protected:
		void SetType(EntityType t) { _t = t;}
		
		void SetHP(int value) {_health[0] = value;}
	
		void SetCurrency(int value) {_currency = value;}
		void ChangeCurrency(int amount) {_currency += amount;}
	
		void SetSprite(ofImage &sprite) {_sprite = sprite;}
	
	
	private:
		int _health[2];
		int _currency;
		EntityType _t;
		string _entityName;
		
		void LoadSprites();
		ofImage _sprite;
		float _spritePos[2];

};

#endif /* Entity_hpp */
