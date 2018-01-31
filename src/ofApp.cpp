#include "ofApp.h"


void ofApp::setup(){
	g = Game();
	
	g.CreateEntity(EntityType::PLAYER, 0, 250, 300);
	g.CreateEntity(EntityType::ENEMY, 1, 750, 300);
	g.GetPlayer().Update();
	g.GetEnemy().Update();
	g.GetEnemy().GenerateMove();
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
					
					if(action >= 0) {
						if(g.GetEnemy().GetMove() == 3 || g.GetEnemy().GetMove() == 4) {
							g.GetEnemy().SetShielded(true);
						}
					}
			
					
					switch(action) {
						case 0:
							g.GetEnemy().TakeDamage(g.GetPlayer().GetDamage());
							g.GetPlayer().ChangeCurrency(g.GetButton(0).GetCost());
							break;
						case 1:
							g.GetPlayer().SetShielded(true);
							g.GetPlayer().ChangeCurrency(g.GetButton(1).GetCost());
							break;
						case 2:
							g.GetEnemy().ChangeCurrency(-g.GetPlayer().GetSteal());
							g.GetPlayer().ChangeCurrency(g.GetPlayer().GetSteal());
							break;
						case -2:
							cout << "Insufficient Funds!" << endl;
							break;
						default:
							cout << "Nothing selected." << endl;
							break;
					}
					
					if(action >= 0) {
						g.GetEnemy().MakeMove();						
					}
					
					if(action >= 0) {
						g.GetPlayer().Update();
						g.GetEnemy().Update();
						g.GetEnemy().GenerateMove();
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
