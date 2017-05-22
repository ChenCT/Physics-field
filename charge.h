#pragma once

#include "ofMain.h"
#include"field.h"
class Charge  //���
{
public:
	Charge(
		ofVec2f _ctr,  //���Բ��
		ofVec2f _vel,  //��ɳ��ٶ�
		ofVec2f _acceleratedvel, //��ɼ��ٶ�
		float _quantity, //��ɴ�����
		float _radius,  //��ɰ뾶
		bool _pm  //���������
	);//���캯��

	void update(float deltaTime);  //ˢ�µ��λ��
	void updatevel(float deltaTime); //ˢ�µ���ٶ�
	void bepower(Charge &srcCharge, Charge &userCharge); //��̽�����Դ��ɵĿ�����
	void bepower2(Field &field, Charge &userCharge);  //��̽����ܴų�����������
	void bepower3(Field &srcfield, Charge &userCharge); //��̽�������ǿ�糡�ĵ糡��
	void powereach(Charge &userCharge, Charge &otherCharge); //��̽��ɼ���໥������
	void draw();
	int getpm(); //��ȡ��ɵ�����
	ofVec2f getCenter(); //��ȡ��ɵ�λ��
	void clearAcc(); //�����̽��ɵļ��ٶ�


protected:
	ofVec2f _Center;
	ofVec2f _Velocity;  //�ٶ�
	ofVec2f _AcceleratedVel; //���ٶ�
	float _Quantity;//�����
	float _Radius;
	bool _PM;//�������

};

