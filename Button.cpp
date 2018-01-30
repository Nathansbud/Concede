//
//  Button.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/24/18.
//
//



#include "Button.hpp"

//Button::Button(Entity &en, void (Entity::*function)(), string text, float x, float y, float w, float h) {

//Button(string text, float x, float y, float w, float h) {
//////	SetParent(en);
//////	toCall(value);
//////	_function = function;
////	
//	_buttonText = text;
//	_buttonPos[0] = x;
//	_buttonPos[1] = y;
//	_buttonSize[0] = w;
//	_buttonSize[1] = h;
//}



Button::Button(string text, float x, float y, float w, float h) {
	_buttonText = text;
	_buttonPos[0] = x;
	_buttonPos[1] = y;
	_buttonSize[0] = w;
	_buttonSize[1] = h;
}

Button::Button(string text, float val, int goldCost, float x, float y, float w, float h) {
	_buttonText = text;
	_val = val;
	_goldCost = goldCost;
	_buttonPos[0] = x;
	_buttonPos[1] = y;
	_buttonSize[0] = w;
	_buttonSize[1] = h;
}

Button::~Button() {

}

//
//void Button::SetParent(Entity &en) {
//	*parent = en;
//}

void Button::Draw() {
	
	ofFill();
	ofSetColor(255, 255, 255); //Interior

	ofDrawRectangle(_buttonPos[0], _buttonPos[1], _buttonSize[0], _buttonSize[1]);
	ofNoFill();
	if(isSelected) {
		ofSetColor(0, 100, 0); //Exterior
	} else {
		ofSetColor(0, 0, 0);
	}
	ofDrawRectangle(_buttonPos[0], _buttonPos[1], _buttonSize[0], _buttonSize[1]);
	ofDrawBitmapString(_buttonText, GetX() + (GetW()/4), GetY() + GetH()/2);
	
//	cout << to_string(_buttonPos[0]) << ", " << to_string(_buttonPos[1]) << " (X, Y), " << to_string(_buttonSize[0]) <<  ", " << to_string(_buttonSize[1]) << " (W, H)" << endl;
}

void Button::Update() {
	
}
//
//void Button::Use(void (Entity::*function)(), Entity &en) {
//	(en.*function)();
//}

