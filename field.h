#pragma once

#include "ofMain.h"

class Field  //场
{
public:
	Field(ofVec2f leftuppoint,
		float width,
		float height,
		float Fieldpower,
		bool dir
	);//构造函数

	ofVec2f Leftuppoint; //场的左上角
	float Width;
	float Height;
	float Fieldpower;//场强
	bool dir = true; //场的方向

	void drawmfield();
	void drawsrcfield();
};