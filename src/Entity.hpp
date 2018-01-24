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
#include "ofImage.h"

enum EntityType {
	PLAYER,
	ENEMY,
	OTHER
};


class Entity {
	public:
		Entity(){};
	
	
		Entity(int health, int currency, ofImage& sprite, int x, int y);
		Entity(ofImage sprite, int x, int y); //For use for potraits; character select screen
		~Entity();
	
		virtual void Draw();
		virtual void Update();
	
		void SetPos(float x, float y);
	
	
		int GetHP() {return _health;}
		int GetCurrency() {return _currency;}
		EntityType GetType() {return _t;}
	
		static const int SPRITE_W = 350;
		static const int SPRITE_H = 350;
	
		void GetPos() {return _spritePos;}
	
	protected:
		void SetType(EntityType t) {_t = t;}
		
		void SetHP(int value) {_health = value;}
		void ChangeHP(int amount) {_health += amount;}
	
		void SetCurrency(int value) {_currency = value;}
		void ChangeCurrency(int amount) {_currency += amount;}
	
//		void SetSprite(ofImage &sprite) {*_sprite = sprite;}
		void SetSprite(ofImage& sprite) {_sprite = sprite;}
	
	private:
		
		int _health;
		int _currency;
		EntityType _t;
		
//		ofImage *_sprite;
		ofImage _sprite;
		float _spritePos[2];
			


		
	
};

#endif /* Entity_hpp */
