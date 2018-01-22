#include "ofApp.h"

void ofApp::setup(){
//	e = Entity(10, 10);
	p = Player(10, 10);
}

void ofApp::update(){

}

void ofApp::draw(){
	ofBackground(255, 255, 255);
	p.Draw();

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
