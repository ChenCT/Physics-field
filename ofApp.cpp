#include "ofApp.h"
#include "charge.h"
#include "field.h"
//--------------------------------------------------------------
void ofApp::setup() {
	Mfield.setName("Magnetic Field");
	Mfield.add(mdir.set(" direction", true));
	Mfield.add(mFieldStr.set("strength", 8, 1, 20));

	Efield.setName("Electric Field");
	Efield.add(edir.set("direction", true));
	Efield.add(eFieldStr.set("strength", 50, 10, 100));

	chargeGroup.setName("Charge");
	chargeGroup.add(chargeSU.set("Source-User", true));
	chargeGroup.add(chargePN.set("Positive-Negative", true));
	chargeGroup.add(sChargeQua.set("sCharge quantity", 80, 10, 200));
	chargeGroup.add(uChargeQua.set("uCharge quantity", 8, 1, 40));

	gui.setup();
	gui.setName("Physical Field");
	gui.add(emField.set("EM_Field", true));
	gui.add(Efield);
	gui.add(Mfield);
	gui.add(chargeGroup);
}

//--------------------------------------------------------------
void ofApp::update() {
	float dt = ofGetLastFrameTime();
	  
	for each(ofPtr<Charge> usercharge in userCharges)
	{
		for each(ofPtr<Charge>srccharge in srcCharges)
		{
			usercharge->bepower(*srccharge, *usercharge);
		}
		for each(ofPtr<Field>  mField in MField)
		{
			usercharge->bepower2(*mField, *usercharge);
		}
		for each(ofPtr<Field>srcfield in srcField)
		{
			usercharge->bepower3(*srcfield, *usercharge);
		}
		usercharge->updatevel(dt);
		usercharge->update(dt);
		
		usercharge->clearAcc();
	}
	for (int i = 0; i < userCharges.size(); i++)
	{
		Traceliness[i].push_back(userCharges.at(i)->getCenter());
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	for each(ofPtr<Field>  mField in MField)
	{
		mField->drawmfield();
	}
	for each(ofPtr<Field>srcfield in srcField)
	{
		srcfield->drawsrcfield();
	}
	for each(ofPtr<Charge> usercharge in userCharges)
	{
		ofPushStyle();
		ofNoFill();
		usercharge->draw();
		ofPopStyle();
	}
	for each(ofPtr<Charge>srccharge in srcCharges)
	{
		ofPushStyle();
		ofFill();
		srccharge->draw();
		ofPopStyle();
	}
	for (int i = 0; i < userCharges.size(); i++)
	{
		ofSetColor(ofRandom(0,255), ofRandom(0, 255), ofRandom(0, 255));
		drawtraceV(Traceliness[i],i);
	}
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'c')
	{
		srcCharges.clear();
		userCharges.clear();
		Tracelines.clear();
		MField.clear();
		srcField.clear();
		for(int i=0;i<20;i++)
			Traceliness[i].clear();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	ofPtr<Charge> usercharge;
	ofPtr<Charge> srccharge;
	if (button == 0) //左键生成电荷
	{
		if (chargeSU)
		{
			srccharge.reset(new Charge(ofVec2f(x, y), ofVec2f(0, 0), ofVec2f(0, 0), sChargeQua, 20, chargePN));
			srcCharges.push_back(srccharge);
		}
		else if (!chargeSU)
		{
			usercharge.reset(new Charge(ofVec2f(x, y), ofVec2f(0, 0), ofVec2f(0, 0), 0.16, 20, chargePN));
			userCharges.push_back(usercharge);			
		}
	}
	if (button == 2)
	{
		leftuppoint = ofVec2f(x, y);
	}
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	ofPtr<Field> srcfield;
	ofPtr<Field> mfield;
	if (button == 2)
	{
		if (emField)/*生成电场  */
		{
			srcfield.reset(new Field(leftuppoint, x - leftuppoint.x, y - leftuppoint.y, 30, edir));
			srcField.push_back(srcfield);
		}
		else if (!emField)/*生成磁场  */
		{
			mfield.reset(new Field(leftuppoint, x - leftuppoint.x, y - leftuppoint.y, mFieldStr, mdir));
			MField.push_back(mfield);
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::drawtraceV(vector<ofVec2f> tracelines,int num)
{
	for (int i = 1; i < tracelines.size(); i++)
	{
		ofSetColor(255 / 7 * num, 0, 255 / 7 * num);
		ofDrawLine(tracelines.at(i-1), tracelines.at(i));
	}
}