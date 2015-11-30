// mvc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "Sphere.h"
#include "Controller.h"
#include "TextView.h"
#include "GraphicsView.h"

int main(int argc, char* argv[])
{
	cout << "Here is a little application based on M-V-C frame." << endl;
	Sphere sphere;//建立模型对象
	TextView *textview = new TextView();//建立文本视图
	GraphicsView *graphicsview = new GraphicsView();//建立图形视图
	sphere.AddObserver(textview);//模型与文本视图相连
	sphere.AddObserver(graphicsview);//模型与图形视图相连
	double r;
	do
	{
		cout << endl << "Please input a radius for a sphere:";
		cin >> r;
		if (!r) break;
		Controller(sphere).ActionPerformed(r);
	} while (r != 0);
	return 0;
}


