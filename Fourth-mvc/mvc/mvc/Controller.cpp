#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
}


Controller::~Controller()
{
}

Controller::Controller(Sphere s_val)
{
	this->sphere = s_val;
}

void Controller::ActionPerformed(double r_val)
{
	sphere.SetRadius(r_val);
}