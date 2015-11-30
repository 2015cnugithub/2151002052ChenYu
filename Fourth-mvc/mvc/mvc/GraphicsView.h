#pragma once
#include "Observer.h"
class GraphicsView :
	public Observer
{
public:
	GraphicsView();
	~GraphicsView();
	void Update(Observable* o_val);
};

