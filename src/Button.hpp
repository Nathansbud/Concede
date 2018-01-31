//
//  Button.hpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/24/18.
//
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "ofMain.h"
#include <functional>
#include "Entity.hpp"

class Button {
	public:
		Button(){};
		Button(string text, int goldCost, float x, float y, float w, float h); //User buttons
		Button(string text, float x, float y, float w, float h); //Non-user buttons (inventory, shop)
	
		~Button();
	
		void Draw();
		void Update();
	
		int GetCost() {return _goldCost;}
//		float GetVal() {return _val;}
	
		float GetX() {return _buttonPos[0];}
		float GetY() {return _buttonPos[1];}
	
		float GetW() {return _buttonSize[0];}
		float GetH() {return _buttonSize[1];}
	
		bool isSelected = false;
		bool isHovered = false;
	
		void SwitchHover() {isHovered = !isHovered;}
		void SetHover(bool b) {isHovered = b;}
		void SwitchSelection() {isSelected = !isSelected;}
		
	private:
		float _buttonPos[2];
		float _buttonSize[2];
//		float _val;
		int _goldCost; //Used for "amount" of affect. This is a multiplier if status effect (ie "1.5x damage"), an amount of Def/Block if used on Defense, and an amount of Damage if used on offense.
		string _buttonText;
};

#endif /* Button_hpp */
