#include "stdafx.h"
#include "GraphicsView.h"
#include <iostream>
using namespace std;


GraphicsView::GraphicsView()
{
}


GraphicsView::~GraphicsView()
{
}

void GraphicsView::Update(Observable* o_val)
{
	cout << "The radius of the sphere has been changed." << endl;
}
