#pragma once

#include "ofMain.h"
#include "Game.hpp"
#include "Names.h"
//#include "Entity.hpp"
//#include "Player.hpp"
//#include "Enemy.hpp"

class ofApp : public ofBaseApp { 

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
	
		int CheckMousePos(int x, int y);
	
	private:
		Game g;
	
};
