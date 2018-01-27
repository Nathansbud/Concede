//
//  Player.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Player.hpp"

Player::Player(CharacterName c, int health, int maxHealth, int currency, ofImage &sprite, float x, float y) : super(health, maxHealth, currency, sprite, x, y) {
	 _c = c;
}

//Player::~Player() {
//
//}
