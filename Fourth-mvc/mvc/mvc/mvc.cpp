// mvc.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include "Sphere.h"
#include "Controller.h"
#include "TextView.h"
#include "GraphicsView.h"

int main(int argc, char* argv[])
{
	cout << "Here is a little application based on M-V-C frame." << endl;
	Sphere sphere;//����ģ�Ͷ���
	TextView *textview = new TextView();//�����ı���ͼ
	GraphicsView *graphicsview = new GraphicsView();//����ͼ����ͼ
	sphere.AddObserver(textview);//ģ�����ı���ͼ����
	sphere.AddObserver(graphicsview);//ģ����ͼ����ͼ����
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


