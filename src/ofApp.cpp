#include "ofApp.h"


void ofApp::setup(){
	g = Game();
	
	g.CreateEntity(EntityType::PLAYER, 0, 250, 300);
	g.CreateEntity(EntityType::ENEMY, 1, 750, 300);
	
//
//	g.CreateEntity(EntityType::PLAYER, 100, 100, 10, CharacterName::JIM, 250, 300);
//	g.CreateEntity(EntityType::ENEMY, 100, 100, 10, EnemyName::CORPSE, 750, 300);
}

void ofApp::update(){
	g.Update();
	int hovered = CheckMousePos(mouseX, mouseY);
	if(hovered >= 0 && hovered < 100) {
		switch(g.GetState()) {
			case GameState::BATTLE:
				g.GetButton(hovered).SetHover(true);
				
				break;
			default:
				break;
		}
	} else {
		for(int i = 0; i < g.GetButtonAmount(); i++) {
			g.GetButton(i).SetHover(false);
		}
	}
}

void ofApp::draw(){
	g.Draw();
}

void ofApp::keyPressed(int key){
	
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y) {
	
}

void ofApp::mouseDragged(int x, int y, int button){
	
}

void ofApp::mousePressed(int x, int y, int button) {
	int selected = CheckMousePos(x, y);
	if(selected >= 0) {
		switch(g.GetState()) {
			case GameState::BATTLE:
				if(selected < 100) {
					for(int i = 0; i < g.GetButtonAmount(); i++) {
						if(g.GetButton(i).isSelected) {
							g.GetButton(i).SwitchSelection();
						}
					}
					
					g.GetButton(selected).SwitchSelection();
				} else if(selected == 100) {
					int action = -1;
					for(int i = 0; i < g.GetButtonAmount(); i++) {
						if(g.GetButton(i).isSelected) {
							if(g.GetPlayer().GetCurrency() + g.GetButton(i).GetCost() < 0) {
								action = -2;
								break;
							} else {
								action = i;
								g.GetButton(i).SwitchSelection();
								g.ChangeTurn();
							}
						}
					}
					
					switch(action) {
						case 0:
							g.GetEnemy().TakeDamage(g.GetButton(0).GetVal());
							g.GetPlayer().ChangeCurrency(g.GetButton(0).GetCost());
							break;
						case 1:
							g.GetPlayer().ChangeDef(g.GetButton(1).GetVal());
							g.GetPlayer().ChangeCurrency(g.GetButton(1).GetCost());
							break;
						case 2:
							g.GetEnemy().ChangeCurrency(g.GetButton(2).GetVal());
							g.GetPlayer().ChangeCurrency(g.GetButton(2).GetCost());
							break;
						case -2:
							cout << "Insufficient Funds!" << endl;
							break;
						default:
							cout << "Nothing selected." << endl;
							break;
					}
				}
				break;
			default:
				break;
		}
	}
}



int ofApp::CheckMousePos(int x, int y) {
	int b = -1;
	
	for(int i = 0; i < g.GetButtonAmount(); i++) {
		if(x > g.GetButton(i).GetX() && x < g.GetButton(i).GetX() + g.GetButton(i).GetW() && y > g.GetButton(i).GetY() && y < g.GetButton(i).GetY() + g.GetButton(i).GetH()) {
			b = i;
		}
	}
	
	if(x > g.GetSubmit().GetX() && x < g.GetSubmit().GetX() + g.GetSubmit().GetW() && y > g.GetSubmit().GetY() && y < g.GetSubmit().GetY() + g.GetSubmit().GetH()) {
		
		b = 100;
	}
	
	return b;
}

void ofApp::mouseReleased(int x, int y, int button) {

}
