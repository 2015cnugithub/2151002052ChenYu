#pragma once
#include "Observable.h"
#define PI 3.14

class Sphere :
	public Observable
{
public:
	Sphere();
	~Sphere();
	void SetRadius(double r_val);
	double GetRadius();
	double GetArea();
	double GetVolume();
private:
	double radius;
};

