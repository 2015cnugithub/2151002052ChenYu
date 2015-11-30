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
	//只有在SetFlag()被调用后，NotifyObservers()才会去调用Update()，否则什么都不干。
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
