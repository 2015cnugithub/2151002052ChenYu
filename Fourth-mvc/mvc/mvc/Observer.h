#pragma once
class Observable;

class Observer
{
public:
	Observer();
	~Observer();
	virtual void Update(Observable* o_val) {}
protected:
	Observable* observable;
};

