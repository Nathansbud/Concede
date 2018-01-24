#include "ofApp.h"


void ofApp::setup(){
	g = Game();
//	g.CreateEntity(PLAYER, 10, 10, 0, 500, 500);
//	g.CreateEntity(ENEMY, 10, 10, 2, 1000, 500);
	g.CreateEntity(PLAYER, 100, 100, 10, 0, 250, 500);
	g.CreateEntity(ENEMY, 100, 100, 10, 1, 750, 500);
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

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}
