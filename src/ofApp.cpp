#include "ofApp.h"


void ofApp::setup(){
	g = Game();

	g.CreateEntity(PLAYER, 100, 100, 10, 1, 250, 300);
	g.CreateEntity(ENEMY, 100, 100, 10, 4, 750, 300);
}

void ofApp::update(){

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
	if(x > g.GetButton(0).GetX() && x < g.GetButton(0).GetX() + g.GetButton(0).GetW() && y > g.GetButton(0).GetY() && y < g.GetButton(0).GetY() + g.GetButton(0).GetH()
		) {
		g.GetPlayer().ChangeHP(-1);
	}
}

void ofApp::mouseReleased(int x, int y, int button){

}
