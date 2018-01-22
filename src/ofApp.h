#pragma once

#include "ofMain.h"
#include "Game.hpp"
//#include "Entity.hpp"
//#include "Player.hpp"
//#include "Enemy.hpp"

class ofApp : public ofBaseApp{

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

	private:
		Game g;
		Player p;
};
