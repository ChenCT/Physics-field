#pragma once

#include "ofMain.h"
#include "ofxGui.h"
class Charge;
class Field;

class ofApp : public ofBaseApp {
private:
	vector<ofPtr<Charge> > srcCharges;
	vector<ofPtr<Charge> > userCharges;
	vector<ofVec2f> Tracelines;
	vector<ofVec2f> Traceliness[20];
	vector<ofPtr<Field> > MField;
	vector<ofPtr<Field> > srcField;

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	void drawtraceV(vector<ofVec2f> tracelines,int num);
	
	ofVec2f leftuppoint;

	ofParameter<bool> emField;//切换磁场电场
	ofParameter<bool> chargeSU;//源电荷，试探电荷
	ofParameter<bool> chargePN;//电荷正负
	ofParameter<bool> mdir;//磁场方向
	ofParameter<bool> edir;//电场方向
	ofParameter<int> mFieldStr;//磁场大小
	ofParameter<int> eFieldStr;//磁场大小
	ofParameter<float> sChargeQua;//源电荷大小
	ofParameter<float> uChargeQua;//试探电荷大小
	ofxPanel gui;
	ofParameterGroup Mfield;
	ofParameterGroup Efield;
	ofParameterGroup chargeGroup;
	//ofxLabel information;
};
