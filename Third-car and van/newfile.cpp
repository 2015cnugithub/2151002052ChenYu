// 1104.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <graphics.h>      // 就是需要引用这个图形库
#include <conio.h>
#include<iostream>
using namespace std;
class Figure
{
public:
	virtual void draw() {}
	virtual void hide() {}
	virtual void move() {}
};

class Circle:public Figure
{
protected:
	int cx,cy,radius;
public:
	Circle(int,int,int);
	Circle() {}
	~Circle() {}
    void draw();
	void hide();
	void move(int,int);
};

Circle::Circle(int x,int y,int r)
{
	cx=x; cy=y; radius=r;
}
void Circle::draw()
{
	circle(cx,cy,radius);
}
void Circle::hide()
{
	setlinecolor(getbkcolor());
	circle(cx,cy,radius);
	graphdefaults();
}
void Circle::move(int dx,int dy)
{
	cx=dx; cy=dy;
}

class Rect:public Figure
{
protected:
	int left,top,right,bottom;
public:
	Rect(int,int,int,int);
	Rect() {}
	~Rect() {}
    void draw();
	void hide();
	void move(int,int,int,int);
};

Rect::Rect(int l,int t,int r,int b)
{
	left=l; top=t; right=r; bottom=b;
}
void Rect::draw()
{
	rectangle(left,top,right,bottom);
}
void Rect::hide()
{
	setlinecolor(getbkcolor());
	rectangle(left,top,right,bottom);
	graphdefaults();
}
void Rect::move(int dl,int dt,int dr,int db)
{
	left=dl; top=dt; right=dr; bottom=db;
}

class Polygon_3:public Figure
{
protected:
	int pts[6];
public:
	Polygon_3(int []);
	Polygon_3() {}
	~Polygon_3() {}
	void draw();
	void hide();
	void move(int []);
};

Polygon_3::Polygon_3(int a[6])
{
	pts[0]=a[0];
	pts[1]=a[1];
	pts[2]=a[2];
	pts[3]=a[3];
	pts[4]=a[4];
	pts[5]=a[5];
}
void Polygon_3::draw()
{
	polygon((POINT*)pts,3);
	//polygon(pts,3);
}
void Polygon_3::hide()
{
	setlinecolor(getbkcolor());
	polygon((POINT*)pts,3);
	//polygon(pts,3);
	graphdefaults();
}
void Polygon_3::move(int a[6])
{
	pts[0]=a[0];
	pts[1]=a[1];
	pts[2]=a[2];
	pts[3]=a[3];
	pts[4]=a[4];
	pts[5]=a[5];
}
class Car:public Circle,public Rect,public Polygon_3
{
private:
	int xstart,ystart,wheel;
public:
	//Figure *object[6];
	Circle *c[2];
	Rect *r[2];
	Polygon_3 *p[2];
	Car(int,int,int);
	void draw();
	void hide();
	void move(int,int);
	void clear();
};

void Car::clear()
{
	int j;
	for(j=0;j<2;j++)
	delete(*(c+j));
	for(j=0;j<2;j++)
	delete(*(r+j));
	for(j=0;j<2;j++)
	delete(*(p+j));
}
Car::Car(int x,int y,int w)
{
	xstart=x;
	ystart=y;
	wheel=w;
    *(c+0)=new Circle(xstart+3.5*wheel,ystart-wheel,wheel);
	*(c+1)=new Circle(xstart+12.5*wheel,ystart-wheel,wheel);
	*(r+0)=new Rect(xstart,ystart-4*wheel,xstart+16*wheel,ystart-2*wheel);
	*(r+1)=new Rect(xstart+4.5*wheel,ystart-6*wheel,xstart+11.5*wheel,ystart-4*wheel);
	int a[6],b[6];
	a[0]=xstart+4.5*wheel;
	a[1]=ystart-6*wheel-1;//纵坐标减1是为了在运动过程中保持图形的完整性，避免覆盖
	a[2]=xstart+2.5*wheel;
	a[3]=ystart-4*wheel-1;
	a[4]=xstart+4.5*wheel;
	a[5]=ystart-4*wheel-1;
	b[0]=xstart+11.5*wheel;
	b[1]=ystart-6*wheel-1;
	b[2]=xstart+11.5*wheel;
	b[3]=ystart-4*wheel-1;
	b[4]=xstart+13.5*wheel;
	b[5]=ystart-4*wheel-1;
	*(p+0)=new Polygon_3(a);
	*(p+1)=new Polygon_3(b);

}
void Car::draw()
{
	c[0]->draw();
	c[1]->draw();
	r[0]->draw();
	r[1]->draw();
	p[0]->draw();
	p[1]->draw();
}
void Car::hide()
{
	c[0]->hide();
	c[1]->hide();
	r[0]->hide();
	r[1]->hide();
	p[0]->hide();
	p[1]->hide();
}
void Car::move(int dx,int dy)
{
	xstart=dx; ystart=dy;
	int a[6],b[6];
	a[0]=xstart+4.5*wheel;
	a[1]=ystart-6*wheel-1;
	a[2]=xstart+2.5*wheel;
	a[3]=ystart-4*wheel-1;
	a[4]=xstart+4.5*wheel;
	a[5]=ystart-4*wheel-1;
	b[0]=xstart+11.5*wheel;
	b[1]=ystart-6*wheel-1;
	b[2]=xstart+11.5*wheel;
	b[3]=ystart-4*wheel-1;
	b[4]=xstart+13.5*wheel;
	b[5]=ystart-4*wheel-1;
	c[0]->hide();
	c[0]->move(xstart+3.5*wheel,ystart-wheel);
	c[0]->draw();
	c[1]->hide();
	c[1]->move(xstart+12.5*wheel,ystart-wheel);
	c[1]->draw();
	r[0]->hide();
	r[0]->move(xstart,ystart-4*wheel,xstart+16*wheel,ystart-2*wheel);
	r[0]->draw();
	r[1]->hide();
	r[1]->move(xstart+4.5*wheel,ystart-6*wheel,xstart+11.5*wheel,ystart-4*wheel);
	r[1]->draw();
	p[0]->hide();
	p[0]->move(a);
	p[0]->draw();
	p[1]->hide();
	p[1]->move(b);
	p[1]->draw();
}

class Van:public Circle,public Rect
{
private:
	int xstart,ystart,wheel;
public:
	Circle *c[5];
	Rect *r[2];
	Van(int,int,int);
	void draw();
	void hide();
	void move(int,int);
	void clear();
};
void Van::clear()
{
	int j;
	for(j=0;j<5;j++)
	delete(*(c+j));
	for(j=0;j<2;j++)
	delete(*(r+j));
}
Van::Van(int x,int y,int w)
{
	xstart=x;
	ystart=y;
	wheel=w;
	*(c+0)=new Circle(xstart+2*wheel,ystart-wheel,wheel);
	*(c+1)=new Circle(xstart+4.5*wheel,ystart-wheel,wheel);
	*(c+2)=new Circle(xstart+13.5*wheel,ystart-wheel,wheel);
	*(c+3)=new Circle(xstart+16*wheel,ystart-wheel,wheel);
	*(c+4)=new Circle(xstart+20*wheel+2,ystart-wheel,wheel);
	*(r+0)=new Rect(xstart,ystart-10*wheel,xstart+18*wheel,ystart-2*wheel);
	*(r+1)=new Rect(xstart+18*wheel+2,ystart-8*wheel,xstart+22*wheel+2,ystart-2*wheel);
}
void Van::draw()
{
	c[0]->draw();
	c[1]->draw();
	c[2]->draw();
	c[3]->draw();
	c[4]->draw();
	r[0]->draw();
	r[1]->draw();
}
void Van::hide()
{
	c[0]->hide();
	c[1]->hide();
	c[2]->hide();
	c[3]->hide();
	c[4]->hide();
	r[0]->hide();
	r[1]->hide();
}
void Van::move(int dx,int dy)
{
	xstart=dx; ystart=dy;
	c[0]->hide();
	c[0]->move(xstart+2*wheel,ystart-wheel);
	c[0]->draw();
	c[1]->hide();
	c[1]->move(xstart+4.5*wheel,ystart-wheel);
	c[1]->draw();
	c[2]->hide();
	c[2]->move(xstart+13.5*wheel,ystart-wheel);
	c[2]->draw();
	c[3]->hide();
	c[3]->move(xstart+16*wheel,ystart-wheel);
	c[3]->draw();
	c[4]->hide();
	c[4]->move(xstart+20*wheel+2,ystart-wheel);
	c[4]->draw();
	r[0]->hide();
	r[0]->move(xstart,ystart-10*wheel,xstart+18*wheel,ystart-2*wheel);
	r[0]->draw();
	r[1]->hide();
	r[1]->move(xstart+18*wheel+2,ystart-8*wheel,xstart+22*wheel+2,ystart-2*wheel);
	r[1]->draw();
}
int main()
{
	int xstart=100,ystart=560,wheel=10;
	int i;
	bool pause=false;
	int ms=100;
	Car car(xstart,ystart,wheel);
	Van van(xstart,ystart,wheel);
	char choice;
	char ch;
	do{
		cout<<"\n主菜单"<<endl;
		cout<<"1.Car"<<endl;
		cout<<"2.Truck"<<endl;
		cout<<"3.Close the graph"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"please choose from 0 to 3:";
		cin>>choice;
		switch(choice)
		{
			case '1':				
				initgraph(800,640);
				rectangle(20,40,779,619);//(left,top,right,bottom)
				outtextxy(1,1,"主菜单：You have already chosen the car.  3.Close the graph");
				outtextxy(1,21,"Before you want to close the graph, please input 'e' or wait for the car stopping automatically.");
				outtextxy(21,41,"Press<s> key to start moving");
				outtextxy(21,56,"Press<p> key to pause/continue moving");
				outtextxy(21,71,"Press<e> key to end moving");
				outtextxy(21,86,"Press<+> key to speed up");
				outtextxy(21,101,"Press<-> key to speed down");
				fillrectangle(20,560,779,569);
				car.draw();				
				ch=_getch();
				if(ch=='s')
					for(i=xstart;i<590;i=i+5)
					{
						car.move(i,ystart);
						Sleep(ms);
						if(_kbhit())
						{
							ch=_getch();
							if(ch=='e') break;
							if(ch=='p')
							{
								pause=true;
								while(pause==true)
								{
									ch=_getch();
									if(ch=='p')
									pause=!pause;
								}//while
							}//if
							if(ch=='+') {ms=ms-50; }
							if(ch=='-') {ms=ms+100; }
						}//if
					}//for
				break;//case '1'
				
			case '2':
				initgraph(800,640);
				rectangle(20,40,779,619);//(left,top,right,bottom)
				outtextxy(1,1,"主菜单：You have already chosen the van.  3.Close the graph");
				outtextxy(1,21,"Before you want to close the graph, please input 'e' or wait for the van stopping automatically.");
				outtextxy(21,41,"Press<s> key to start moving");
				outtextxy(21,56,"Press<p> key to pause/continue moving");
				outtextxy(21,71,"Press<e> key to end moving");
				outtextxy(21,86,"Press<+> key to speed up");
				outtextxy(21,101,"Press<-> key to speed down");
				fillrectangle(20,560,779,569);
				van.draw();
				ch=_getch();
				if(ch=='s')
					for(i=xstart;i<550;i=i+5)
					{
						van.move(i,ystart);
						Sleep(ms);
						if(_kbhit())
						{
							ch=_getch();
							if(ch=='e') break;
							if(ch=='p')
							{
								pause=true;
								while(pause==true)
								{
									ch=_getch();
									if(ch=='p')
									pause=!pause;
								}//while
							}//if
							if(ch=='+') ms=ms-50;
							if(ch=='-') ms=ms+100;
						}//if
					}//for				
				break;//case '2'

			case '3':closegraph();break;
		}//switch(choice)
	}while(choice!='0');
	car.clear();
	van.clear();
	return 0;
}
                                                           