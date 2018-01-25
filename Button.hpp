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
		Button(string text, float x, float y, float w, float h);
	
	
	
//		Button(Entity &en, void (Entity::*function)(), string text, float x, float y, float w, float h);
	
//		Button(std::function<void(int)> toCall, int value, string text, float x, float y, float w, float h);
		~Button();
	
		void Draw();
		void Update();
	
		float GetX() {return _buttonPos[0];}
		float GetY() {return _buttonPos[1];}
	
		float GetW() {return _buttonSize[0];}
		float GetH() {return _buttonSize[1];}
//		void Use(void (Entity::*function)(), Entity &en);
	
//		void SetParent(Entity &en);
	
//		Entity *parent;
//		void (Entity::*_function)();

	private:
		float _buttonPos[2];
		float _buttonSize[2];
	
		string _buttonText;
};

#endif /* Button_hpp */
