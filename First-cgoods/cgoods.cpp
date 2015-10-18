#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class CGoods{
private:
    long no;//��Ʒ��
    char *p_name;//��Ʒ��
    double price;//��Ʒ�۸�
    static int count;//��Ʒ����������������һ�����ȫ�ֱ���
public:
    CGoods(long no_val,char *p_name_val,double price_val);//���캯��
    CGoods(CGoods &c);//�������캯��
    ~CGoods();//��������
    void print();//��ӡ���ݳ�Ա
    static int getCount() {return count;}//��ȡ��Ʒ��������������ʵ�־�̬������Ҳ����Ҫstatic����
    friend char *getName(CGoods &c);//��Ԫ������ȡp_name
    bool operator< (const CGoods c);//���������
    bool operator>= (const CGoods c);//���������
};
/*
static�����ǰ��ճ�������������������ͷţ������ڳ����ʼ��ʱ�����䣬ֱ�������˳�ǰ�ű��ͷ�
*/
class CClothes:public CGoods
{
private:
    char *p_brand;//Ʒ������
public:
    CClothes(long no_val,char *p_name_val,double price_val,char *p_brand_val);
    ~CClothes() {delete p_brand;    cout<<"Deleting clothes."<<endl;}
    void useFor();//�����Ϣ
};
class CFood:public CGoods
{
private:
    char *p_brand;//Ʒ������
public:
    CFood(long no_val,char *p_name_val,double price_val,char *p_brand_val);
    ~CFood() {delete p_brand;    cout<<"Deleting food."<<endl;}
    void useFor();//�����Ϣ
};
int CGoods::count=0;//��ʼ��static���͵ı�����û����static����
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
    cout<<"��Ʒ���Ϊ"<<setw(5)<<no<<endl;
    cout<<"��Ʒ����Ϊ"<<p_name<<endl;
    cout<<"��Ʒ�۸�Ϊ"<<price<<"Ԫ"<<endl;
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
    cout<<"����������������c1�����á���ӡ����Ա������"<<endl;
    c1.print();
    cout<<endl;
    cout<<"���������������c2��"<<endl;
    long x;
    cout<<"��������Ʒ��ţ�";
    cin>>x;
    string y;
    cout<<"��������Ʒ���ƣ�";
    cin>>y;
    char* val;
    const int len=y.length();
    val=new char[len+1];
    strcpy(val,y.c_str());//��string����ת����char*����
    double z;
    cout<<"��������Ʒ�۸�Ԫ����";
    cin>>z;
    CGoods c2(x,val,z);
    cout<<"���á���ӡ����Ա����:"<<endl;
    c2.print();
    cout<<endl;
    CGoods c3(c1);//���ÿ������캯��
    cout<<"���ø��ƹ��캯����������c3��������ӡ����Ա������"<<endl;
    c3.print();
    cout<<endl;
    char name[20];
    strcpy(name,getName(c3));
    cout<<"��ȡ����c3����Ʒ���ƣ�"<<name<<endl<<endl;;
    int number;
    number=CGoods::getCount();
    cout<<"��ȡ��Ʒ������"<<number<<endl<<endl;
    cout<<"����c1��c2������������أ�"<<endl;
    c1<(c2);
    c1>=(c2);
    c2<(c1);
    c2>=(c1);
    /*��Ϊ����������ĺ�������ʱ�����˻���Ķ������Ի�ִ����������*/
    cout<<endl;
    number=CGoods::getCount();
    cout<<"�ٴλ�ȡ��Ʒ������"<<number<<endl<<endl;
    CClothes clothes(1003,"shirt",30,"cache");
    cout<<"�������������"<<endl;
    clothes.print();
    cout<<"��װ�����Ʒ�����ǣ�";
    clothes.useFor();
    cout<<endl;
    CFood food(1004,"milk",2.2,"����");
    cout<<"�������������"<<endl;
    food.print();
    cout<<"ʳƷ�����Ʒ�����ǣ�";
    food.useFor();
    cout<<endl;
    return 0;
}




