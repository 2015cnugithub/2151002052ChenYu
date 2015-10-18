#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class CGoods{
private:
    long no;//商品号
    char *p_name;//商品名
    double price;//商品价格
    static int count;//商品总数，声明，类似一个类的全局变量
public:
    CGoods(long no_val,char *p_name_val,double price_val);//构造函数
    CGoods(CGoods &c);//拷贝构造函数
    ~CGoods();//析构函数
    void print();//打印数据成员
    static int getCount() {return count;}//获取商品总数，若在类外实现静态函数，也不需要static修饰
    friend char *getName(CGoods &c);//友元函数获取p_name
    bool operator< (const CGoods c);//重载运算符
    bool operator>= (const CGoods c);//重载运算符
};
/*
static变量是按照程序的生命周期来分配释放：变量在程序初始化时被分配，直到程序退出前才被释放
*/
class CClothes:public CGoods
{
private:
    char *p_brand;//品牌名称
public:
    CClothes(long no_val,char *p_name_val,double price_val,char *p_brand_val);
    ~CClothes() {delete p_brand;    cout<<"Deleting clothes."<<endl;}
    void useFor();//输出信息
};
class CFood:public CGoods
{
private:
    char *p_brand;//品牌名称
public:
    CFood(long no_val,char *p_name_val,double price_val,char *p_brand_val);
    ~CFood() {delete p_brand;    cout<<"Deleting food."<<endl;}
    void useFor();//输出信息
};
int CGoods::count=0;//初始化static类型的变量，没有用static修饰
CGoods::CGoods(long no_val,char *p_name_val,double price_val)
{
    no=no_val;
    p_name=new char[strlen(p_name_val)+1];
    strcpy(p_name,p_name_val);
    price=price_val;
    count++;
}
CGoods::CGoods(CGoods &c)
{
    no=c.no;
    p_name=new char[strlen(c.p_name)+1];
    strcpy(p_name,c.p_name);
    price=c.price;
    count++;
}
CGoods::~CGoods()
{
    cout<<"Deleting goods."<<endl;
    delete p_name;
    count--;

}
void CGoods::print()
{
    cout<<"商品编号为"<<setw(5)<<no<<endl;
    cout<<"商品名称为"<<p_name<<endl;
    cout<<"商品价格为"<<price<<"元"<<endl;
}
char *getName(CGoods &c)
{
    return c.p_name;
}
bool CGoods::operator<(const CGoods c)
{
    if(this->price<c.price)
    {
        cout<<this->p_name<<"'s price is cheaper than "<<c.p_name<<"'s price."<<endl;
        return true;
    }
    else if(this->price>=c.price)
    {
        cout<<this->p_name<<"'s price is not cheaper than "<<c.p_name<<"'s price."<<endl;
        return true;
    }
    else return false;
}
bool CGoods::operator>=(const CGoods c)
{
    if(this->price>=c.price)
    {
        cout<<this->p_name<<"'s price is more expensive than or equal to "<<c.p_name<<"'s price."<<endl;
        return true;
    }
    else if(this->price<c.price)
    {
        cout<<this->p_name<<"'s price is not more expensive than or equal to "<<c.p_name<<"'s price."<<endl;
        return true;
    }
    else return false;
}
CClothes::CClothes(long no_val,char *p_name_val,double price_val,char *p_brand_val):CGoods(no_val,p_name_val,price_val)
    {
        p_brand=new char[strlen(p_brand_val)+1];
        strcpy(p_brand,p_brand_val);
    }
void CClothes::useFor()
{
    cout<<this->p_brand<<endl;
}
CFood::CFood(long no_val,char *p_name_val,double price_val,char *p_brand_val):CGoods(no_val,p_name_val,price_val)
    {
        p_brand=new char[strlen(p_brand_val)+1];
        strcpy(p_brand,p_brand_val);
    }
void CFood::useFor()
{
    cout<<this->p_brand<<endl;
}
int main()
{
    char a1[]="apple";
    CGoods c1(1001,a1,3.5);//CGoods c1(1001,"apple",3.5)
    cout<<"给定参数创建对象c1，调用“打印”成员函数："<<endl;
    c1.print();
    cout<<endl;
    cout<<"输入参数创建对象c2："<<endl;
    long x;
    cout<<"请输入商品编号：";
    cin>>x;
    string y;
    cout<<"请输入商品名称：";
    cin>>y;
    char* val;
    const int len=y.length();
    val=new char[len+1];
    strcpy(val,y.c_str());//把string类型转换成char*类型
    double z;
    cout<<"请输入商品价格（元）：";
    cin>>z;
    CGoods c2(x,val,z);
    cout<<"调用“打印”成员函数:"<<endl;
    c2.print();
    cout<<endl;
    CGoods c3(c1);//调用拷贝构造函数
    cout<<"调用复制构造函数创建对象c3，并“打印”成员函数："<<endl;
    c3.print();
    cout<<endl;
    char name[20];
    strcpy(name,getName(c3));
    cout<<"获取对象c3的商品名称："<<name<<endl<<endl;;
    int number;
    number=CGoods::getCount();
    cout<<"获取商品总数："<<number<<endl<<endl;
    cout<<"对象c1和c2进行运算符重载："<<endl;
    c1<(c2);
    c1>=(c2);
    c2<(c1);
    c2>=(c1);
    /*因为重载运算符的函数调用时，给了基类的对象，所以会执行析构函数*/
    cout<<endl;
    number=CGoods::getCount();
    cout<<"再次获取商品总数："<<number<<endl<<endl;
    CClothes clothes(1003,"shirt",30,"cache");
    cout<<"创建派生类对象："<<endl;
    clothes.print();
    cout<<"服装类的商品名称是：";
    clothes.useFor();
    cout<<endl;
    CFood food(1004,"milk",2.2,"伊利");
    cout<<"创建派生类对象："<<endl;
    food.print();
    cout<<"食品类的商品名称是：";
    food.useFor();
    cout<<endl;
    return 0;
}




