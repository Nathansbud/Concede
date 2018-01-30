#include "ofApp.h"


void ofApp::setup(){
	g = Game();
	
	g.CreateEntity(EntityType::PLAYER, 100, 100, 10, CharacterName::JIM, 250, 300);
	g.CreateEntity(EntityType::ENEMY, 100, 100, 10, EnemyName::WALKING_CORPSE, 750, 300);
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

void ofApp::mouseMoved(int x, int y) {
	
}

void ofApp::mouseDragged(int x, int y, int button){
	
}

void ofApp::mousePressed(int x, int y, int button) {
	switch(g.GetState()) {
		
		case GameState::BATTLE:
			if(x > g.GetButton(0).GetX() && x < g.GetButton(0).GetX() + g.GetButton(0).GetW() && y > g.GetButton(0).GetY() && y < g.GetButton(0).GetY() + g.GetButton(0).GetH()) {
				
				for(int i = 0; i < g.GetButtonAmount(); i++) {
					if(g.GetButton(i).isSelected) {
						g.GetButton(i).SwitchSelection();
					}
				}
				
				g.GetButton(0).SwitchSelection();


//				g.GetEnemy().TakeDamage(1);
//				g.GetPlayer().ChangeCurrency(-2);
			}
			
			if(x > g.GetButton(1).GetX() && x < g.GetButton(1).GetX() + g.GetButton(1).GetW() && y > g.GetButton(1).GetY() && y < g.GetButton(1).GetY() + g.GetButton(1).GetH()) {
				
				for(int i = 0; i < g.GetButtonAmount(); i++) {
					if(g.GetButton(i).isSelected) {
						g.GetButton(i).SwitchSelection();
					}
				}
				
				g.GetButton(1).SwitchSelection();
			}
			
			if(x > g.GetButton(2).GetX() && x < g.GetButton(2).GetX() + g.GetButton(2).GetW() && y > g.GetButton(2).GetY() && y < g.GetButton(2).GetY() + g.GetButton(2).GetH()) {
			
				for(int i = 0; i < g.GetButtonAmount(); i++) {
					if(g.GetButton(i).isSelected) {
						g.GetButton(i).SwitchSelection();
					}
				}
				
				g.GetButton(2).SwitchSelection();
			}
		
			
			if(x > g.GetSubmit().GetX() && x < g.GetSubmit().GetX() + g.GetSubmit().GetW() && y > g.GetSubmit().GetY() && y < g.GetSubmit().GetY() + g.GetSubmit().GetH()) {
				
				int temp = -1;
				
				for(int i = 0; i < g.GetButtonAmount(); i++) {
					if(g.GetButton(i).isSelected) {
						if(g.GetPlayer().GetCurrency() + g.GetButton(i).GetCost() < 0) {
							//Todo: Make this show "Insufficient funds! Try regaining Gold!"...implement a unique psuedo-"isSelected()" for Submit button?
							break;
						} else {
							temp = i;
							g.GetButton(i).SwitchSelection();
							g.ChangeTurn();

						}
					}
				}
				
				switch(temp) {
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
					default:
						cout << "Insufficient Funds!" << endl;
						break;
				}
//
				
////				if(g.GetButton(0).isSelected) { //Attack
////					g.GetEnemy().TakeDamage(g.GetButton(0).GetVal());
////					g.GetPlayer().ChangeCurrency(g.GetButton(0).GetCost());
////				}
////				
////				if(g.GetButton(1).isSelected) { //Defend
////					g.GetPlayer().ChangeDef(g.GetButton(1).GetVal());
////					g.GetPlayer().ChangeCurrency(g.GetButton(1).GetCost());
////				}
//////			
////				if(g.GetButton(2).isSelected) {
////					g.GetEnemy().ChangeCurrency(g.GetButton(2).GetVal());
////					g.GetPlayer().ChangeCurrency(g.GetButton(2).GetCost());
////				}
////			
//
//				
//				for(int i = 0; i < g.GetButtonAmount(); i++) {
//					if(g.GetButton(i).isSelected) {
//						g.GetButton(i).SwitchSelection();
//					}
//				}
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
