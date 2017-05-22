#pragma once

#include "ofMain.h"
#include"field.h"

Field::Field(ofVec2f leftuppoint,
	float width,
	float height,
	float fieldpower,
	bool dir) ://构造函数

	Leftuppoint(leftuppoint),
	Width(width),
	Height(height),
	Fieldpower(fieldpower),
	dir(dir)
{}


void Field::drawmfield()  //画磁场
{
	ofPushStyle();
	ofSetColor(80);
	ofNoFill();
    ofDrawRectangle(Leftuppoint, Width,Height);
	ofPopStyle();
	//隔一定距离画×
	ofPushStyle();
	ofSetColor(120);
	for (float i = Leftuppoint.x+10; i < Leftuppoint.x + Width; i += 50)
		for (int j = Leftuppoint.y+10; j < Leftuppoint.y + Height; j +=  50)
		{
			if (dir)  //方向垂直平面向里
			{
				ofDrawLine(i - 4, j - 4, i + 4, j + 4);
				ofDrawLine(i - 4, j + 4, i + 4, j - 4);
			}
			else if (!dir)  //方向垂直平面向外
			{
				ofFill();
				ofDrawCircle(i, j, 2);
			}
		}
	ofPopStyle();
}

void Field::drawsrcfield()  //画电场
{
	ofPushStyle();
	ofSetColor(80);
	ofNoFill();
	ofDrawRectangle(Leftuppoint, Width, Height);
	
	for (int i = Leftuppoint.x + 20; i < Leftuppoint.x + Width - 20; i += 40)
	{
		if(dir)
			ofDrawArrow(ofVec2f(i, Leftuppoint.y + 10), ofVec2f(i, Leftuppoint.y + Height - 10), 5); 
		else if (!dir)
			ofDrawArrow(ofVec2f(i, Leftuppoint.y + Height - 10), ofVec2f(i, Leftuppoint.y +10), 5);			
	}
	ofPopStyle();
}
