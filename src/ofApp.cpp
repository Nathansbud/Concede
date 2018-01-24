#include "ofApp.h"


void ofApp::setup(){
	g = Game();
	g.CreateEntity(OTHER, 10, 10, 0, 500, 500);
//	g.CreateEntity(10, 10, 2, 1000, 500);
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

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}
