#pragma once
#include "Sphere.h"
class Controller
{
public:
	Controller();
	Controller(Sphere s_val);
	virtual ~Controller();
	void ActionPerformed(double r_val);
private:
	Sphere sphere;//�ÿ��������Ƶ�Sphere����
};

