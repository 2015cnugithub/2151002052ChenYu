#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

void Sphere::SetRadius(double r_val)
{
	this->radius = r_val;
	SetFlag();
	//ֻ����SetFlag()�����ú�NotifyObservers()�Ż�ȥ����Update()������ʲô�����ɡ�
	NotifyObservers();
}

double Sphere::GetRadius()
{
	return radius;
}

double Sphere::GetArea()
{
	return 4 * PI*radius*radius;
}

double Sphere::GetVolume()
{
	return 4 / 3.0*PI*radius*radius*radius;
}
