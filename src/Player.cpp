//
//  Player.cpp
//  ConcedeGame
//
//  Created by Zack Amiton on 1/22/18.
//
//

#include "Player.hpp"

Player::Player(int hp, int currency) {
	SetHP(hp);
	SetCurrency(currency);
	_sprite.load("characters/c0.png");
}

Player::~Player() {

}

void Player::Draw() {
	_sprite.draw(500, 500);
}

void Player::Update() {

}
