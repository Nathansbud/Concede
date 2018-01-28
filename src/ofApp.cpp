#include "ofApp.h"


void ofApp::setup(){
	g = Game();

	g.CreateEntity(EntityType::PLAYER, 100, 100, 10, CharacterName::JIM, 250, 300);
	g.CreateEntity(EntityType::ENEMY, 100, 100, 10, EnemyName::PANTS, 750, 300);
}

void ofApp::update(){
	g.Update();
}

void ofApp::draw(){
	g.Draw();
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){
	
}

void ofApp::mousePressed(int x, int y, int button) {
	switch(g.GetState()) {
		case GameState::BATTLE:
			if(x > g.GetButton(0).GetX() && x < g.GetButton(0).GetX() + g.GetButton(0).GetW() && y > g.GetButton(0).GetY() && y < g.GetButton(0).GetY() + g.GetButton(0).GetH()
				) {
				g.GetEnemy().ChangeHP(-50);
			}
			break;
		case GameState::BATTLE_WIN:
			break;
		default:
			break;
	}
}

void ofApp::mouseReleased(int x, int y, int button){

}
