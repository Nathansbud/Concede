//
//  Player.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Player.hpp"

Player::Player(CharacterName c, ofImage &sprite, float stats[8], float x, float y) : super(sprite, stats, x, y) {
	_c = c;
}

//Player::~Player() {
//
//}
