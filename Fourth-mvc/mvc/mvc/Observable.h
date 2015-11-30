#pragma once
#include <vector>
using namespace std;
class Observer;

class Observable
{
public:
	Observable();
	~Observable();
	void AddObserver(Observer* o_val);
	void SetFlag();
	void ClearFlag();
	void NotifyObservers();
private:
	int flag;
	vector<Observer*> observer;
};

