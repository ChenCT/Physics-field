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

	ofParameter<bool> emField;//�л��ų��糡
	ofParameter<bool> chargeSU;//Դ��ɣ���̽���
	ofParameter<bool> chargePN;//�������
	ofParameter<bool> mdir;//�ų�����
	ofParameter<bool> edir;//�糡����
	ofParameter<int> mFieldStr;//�ų���С
	ofParameter<int> eFieldStr;//�ų���С
	ofParameter<float> sChargeQua;//Դ��ɴ�С
	ofParameter<float> uChargeQua;//��̽��ɴ�С
	ofxPanel gui;
	ofParameterGroup Mfield;
	ofParameterGroup Efield;
	ofParameterGroup chargeGroup;
	//ofxLabel information;
};
