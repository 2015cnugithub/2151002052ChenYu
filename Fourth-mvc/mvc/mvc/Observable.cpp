#include "stdafx.h"
#include "Observable.h"
#include "Observer.h"


Observable::Observable()
{
	observer = vector<Observer* >();
	flag = 0;
}


Observable::~Observable()
{
}

void Observable::AddObserver(Observer* o_val)
{
	observer.push_back(o_val);
}

void Observable::SetFlag()
{
	flag++;
}

void Observable::ClearFlag()
{
	flag++;
}
void Observable::NotifyObservers()
{
	if (!(flag % 2)) return;
	ClearFlag();//根据标志的奇偶来判断是否发生变化
	vector<Observer*>::iterator it;
	for (it = observer.begin(); it != observer.end(); it++)
	{
		(*it)->Update(this);
	}
}
