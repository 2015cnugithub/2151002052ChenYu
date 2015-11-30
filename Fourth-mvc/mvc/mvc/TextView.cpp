#include "stdafx.h"
#include "TextView.h"


TextView::TextView()
{
}


TextView::~TextView()
{
}

void TextView::Update(Observable* o_val)
{
	Sphere *sphere = (Sphere*)o_val;
	cout << "The radius of the sphere is " << sphere->GetRadius() << endl;
	cout << "The area of the sphere is " << sphere->GetArea() << endl;
	cout << "The volume of the sphere is " << sphere->GetVolume() << endl;
}