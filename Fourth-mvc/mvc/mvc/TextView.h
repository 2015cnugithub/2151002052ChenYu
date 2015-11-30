#pragma once
#include "Observer.h"
#include "Sphere.h"
#include <iostream>
using namespace std;

class TextView :
	public Observer
{
public:
	TextView();
	~TextView();
	void Update(Observable* o_val);
};

