#pragma once

#include "ofMain.h"

class Field  //��
{
public:
	Field(ofVec2f leftuppoint,
		float width,
		float height,
		float Fieldpower,
		bool dir
	);//���캯��

	ofVec2f Leftuppoint; //�������Ͻ�
	float Width;
	float Height;
	float Fieldpower;//��ǿ
	bool dir = true; //���ķ���

	void drawmfield();
	void drawsrcfield();
};