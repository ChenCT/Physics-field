#pragma once

#include "ofMain.h"
#include"field.h"
class Charge  //电荷
{
public:
	Charge(
		ofVec2f _ctr,  //电荷圆心
		ofVec2f _vel,  //电荷初速度
		ofVec2f _acceleratedvel, //电荷加速度
		float _quantity, //电荷带电量
		float _radius,  //电荷半径
		bool _pm  //电荷正负性
	);//构造函数

	void update(float deltaTime);  //刷新电荷位置
	void updatevel(float deltaTime); //刷新电荷速度
	void bepower(Charge &srcCharge, Charge &userCharge); //试探电荷受源电荷的库仑力
	void bepower2(Field &field, Charge &userCharge);  //试探电荷受磁场的洛伦兹力
	void bepower3(Field &srcfield, Charge &userCharge); //试探电荷受匀强电场的电场力
	void powereach(Charge &userCharge, Charge &otherCharge); //试探电荷间的相互作用力
	void draw();
	int getpm(); //获取电荷的正负
	ofVec2f getCenter(); //获取电荷的位置
	void clearAcc(); //清除试探电荷的加速度


protected:
	ofVec2f _Center;
	ofVec2f _Velocity;  //速度
	ofVec2f _AcceleratedVel; //加速度
	float _Quantity;//电荷量
	float _Radius;
	bool _PM;//正负电荷

};

