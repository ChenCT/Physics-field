#pragma once

#include "ofMain.h"
#include"charge.h"

Charge::Charge(ofVec2f _ctr,
	ofVec2f _vel,
	ofVec2f _acceleratedvel,
	float _quantity,
	float _radius,
	bool _pm) :

	_Center(_ctr),
	_Velocity(_vel),
	_Quantity(_quantity),
	_Radius(_radius),
	_AcceleratedVel(_acceleratedvel),
	_PM(_pm)
{}   //���캯������

void Charge::update(float deltaTime)
{
	_Center += _Velocity * deltaTime;
}

void Charge::updatevel(float deltaTime)
{
	_Velocity += _AcceleratedVel * deltaTime;
}

void Charge::bepower(Charge &srcCharge, Charge &userCharge) //������
{
	int dir = 1;
	if (srcCharge._PM == userCharge._PM) // ͬ�ֵ�� ����
	{
		dir = -1;
	}
	ofVec2f offset = srcCharge._Center - userCharge._Center;
	float len = offset.length();
	float power = srcCharge._Quantity * userCharge._Quantity / len / len;
	userCharge._AcceleratedVel += 100 * dir*offset*power / len;
}

void Charge::bepower2(Field &field, Charge &userCharge) //��������
{
	ofRectangle MRect(field.Leftuppoint, field.Width, field.Height);
	if (MRect.inside(userCharge._Center))
	{ 
		ofVec2f Force = userCharge._Quantity *userCharge._Velocity * field.Fieldpower;//F=qvB
		if (userCharge.getpm() == field.dir)  //�ų�����ͬ ��������ͬ
			userCharge._AcceleratedVel += Force.rotate(-90);
		else if (!userCharge.getpm() == field.dir)
			userCharge._AcceleratedVel += Force.rotate(90);	
	}	
}

void Charge::bepower3(Field &field, Charge &userCharge) //�糡��
{
	ofRectangle Rect(field.Leftuppoint, field.Width, field.Height);
	if (Rect.inside(userCharge._Center))  //�ڵ糡��
	{
		float power = field.Fieldpower*userCharge._Quantity;
		if (userCharge.getpm()==field.dir)
		{
			userCharge._AcceleratedVel += ofVec2f(0, power);
		}
		else if(!userCharge.getpm() == field.dir)
		{
			userCharge._AcceleratedVel += ofVec2f(0, -power);
		}
	}
}

void Charge::powereach(Charge &userCharge, Charge &otherCharge)//�໥ʩ��
{
	int dir = 1;
	if (otherCharge._PM == userCharge._PM) // ͬ�ֵ�� ����
	{
		dir = -1;
	}
	ofVec2f offset = otherCharge._Center - userCharge._Center;
	float len = offset.length();
	float power = otherCharge._Quantity * userCharge._Quantity / len / len;
	userCharge._AcceleratedVel = 100 * dir*offset*power / len;
	otherCharge._AcceleratedVel = -1 * 100 * dir*offset*power / len;
}

void Charge::draw()
{	
		ofPushStyle();
		ofSetColor(ofColor::black);
		ofSetLineWidth(0);
		ofDrawCircle(_Center, _Radius);
		ofPopStyle();

		ofPushStyle();
		ofSetColor(ofColor::white);
		ofSetLineWidth(0);
		if (!_PM ) //���Ӽ�
		{ofDrawLine(_Center.x - _Radius / 2, _Center.y, _Center.x + _Radius / 2, _Center.y);	}
		else if (_PM)
		{
		ofDrawLine(_Center.x - _Radius / 2, _Center.y, _Center.x + _Radius / 2, _Center.y);
		ofDrawLine(_Center.x, _Center.y - _Radius / 2, _Center.x, _Center.y + _Radius  / 2);
		}
		ofPopStyle();

}

int Charge::getpm()
{
	return _PM;
}

ofVec2f Charge::getCenter()
{
	return _Center;
}

void Charge::clearAcc()
{
	_AcceleratedVel = ofVec2f(0,0);
}