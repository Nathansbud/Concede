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

class Entity {
	public:
		Entity(){};
		
		Entity(int health, int currency);
		~Entity();
	
		virtual void Draw();
		virtual void Update();
	
		int GetHP() {return _health;}
		int GetCurrency() {return _currency;}
	
	protected:
		void SetHP(int value) {_health = value;}
		void ChangeHP(int amount) {_health += amount;}
	
		void SetCurrency(int value) {_currency = value;}
		void ChangeCurrency(int amount) {_currency += amount;}
	
	private:
		int _health;
		int _currency;
	
};

#endif /* Entity_hpp */
