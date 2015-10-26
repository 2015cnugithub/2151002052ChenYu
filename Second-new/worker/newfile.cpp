#include<iostream>
#include<iomanip>
#include<cstring>
#include<conio.h>
//#include<cstdlib>
using namespace std;
class Worker{
protected:
    char *name;
    int age;
    char sex;
    double pay_per_hour;//小时工资额
public:
    Worker(char *name_val,int age_val,char sex_val,double pay_per_hour_val);
    virtual void Compute_pay(double hours)=0;
    friend ostream& operator<<(ostream& out,Worker& worker);
    void Name();//用于在菜单结构中显示每个工人的姓名作为用户选择的菜单项
    virtual ~Worker();
};
Worker::Worker(char* name_val, int age_val, char sex_val, double pay_per_hour_val)
{
    name=new char[strlen(name_val)+1];
    strcpy(name,name_val);
    age=age_val;
    sex=sex_val;
    pay_per_hour=pay_per_hour_val;
}
Worker::~Worker()
{
    cout<<"Deleting Worker."<<endl;
}
void Worker::Name()
{
    cout<<name<<endl;
}
ostream& operator<<(ostream& out,Worker& worker)
{
    out<<setw(6)<<"姓名"<<setw(8)<<"年龄"<<setw(6)<<"性别"<<setw(6)<<"时薪"<<setw(10)<<"类别"<<endl;
    if(worker.pay_per_hour==30||worker.pay_per_hour==50)
        out<<setw(6)<<worker.name<<setw(6)<<worker.age<<setw(6)<<worker.sex<<setw(6)<<worker.pay_per_hour<<setw(18)<<"Salaried Worker"<<endl;
    else
        out<<setw(6)<<worker.name<<setw(6)<<worker.age<<setw(6)<<worker.sex<<setw(6)<<worker.pay_per_hour<<setw(18)<<"Hourly Worker"<<endl;
    return out;
}
class HourlyWorker:public Worker
{
public:
    HourlyWorker(char* name_val, int age_val, char sex_val, double pay_per_hour_val):
    Worker(name_val,age_val,sex_val,pay_per_hour_val) {}
    ~HourlyWorker() {cout<<"Deleting HourlyWorker."<<endl;}
    void Compute_pay(double hours);
};
void HourlyWorker::Compute_pay(double hours)
{
    double payment;//计时周薪
    payment=(hours<=40.0)?hours*pay_per_hour:40*pay_per_hour+1.5*(hours-40.0)*pay_per_hour;
    /*如果每周的工作时数（hours）在40以内，则周薪 = 小时工资额 × 实际工作时数；
     如果每周的工作时数（hours）超过40，则周薪 = 小时工资额 × 40 + 1.5 × 小时工资额 ×（实际工作时数 – 40）*/
    cout<<"此工人的周薪为："<<setw(4)<<payment<<"元"<<endl;
}
class SalariedWorker:public Worker
{
public:
    SalariedWorker(char* name_val, int age_val, char sex_val, double pay_per_hour_val):
    Worker(name_val,age_val,sex_val,pay_per_hour_val) {}
    ~SalariedWorker() {cout<<"Deleting SalariedWorker."<<endl;}
    void Compute_pay(double hours);
};
void SalariedWorker::Compute_pay(double hours)
{
    double payment;//计薪周薪
    payment=(hours>=35.0)?40*pay_per_hour:pay_per_hour*hours+0.5*(35.0-hours)*pay_per_hour;
    /*如果每周的实际工作时数不少于35小时，则按40小时计周薪（允许有半个工作日的事/病假），
     超出40小时部分不计薪，即周薪 = 小时工资额 × 40；
      如果每周的实际工作时数少于35小时（不含35小时），
     则周薪 = 小时工资额 × 实际工作时数 + 0.5 × 小时工资额 × (35 - 实际工作时数)*/
    cout<<"此工人的周薪为："<<setw(4)<<payment<<"元"<<endl;
}
void presskey(){
  char ch;
  cout<<"\n********按回车键继续********";
  ch=getch();//不回显函数，从控制台读取一个字符，但不显示在屏幕上,头文件conin.h
  if(ch!='\r'||ch!='\n') putchar('\n');
}

int main()
{
    Worker *workers[5];
   int age;
   double per_pay;
   int find;//待查工人编号
   char ch;
   double hours;
    cout<<"依次输入工人信息："<<endl;
    for(int i=0;i<5;i++)
    {
        char name[10],sex;
        cout<<"工人编号："<<i+1<<endl;
        cout<<"姓名：";
	cin>>name;
	cout<<"年龄：";
	cin>>age;
	cout<<"性别：";
	cin>>sex;
	cout<<"时薪：";
	cin>>per_pay;
	cout<<endl;
	if(per_pay==30||per_pay==50)
            *(workers+i)=new SalariedWorker(name,age,sex,per_pay);
        else
            *(workers+i)=new HourlyWorker(name,age,sex,per_pay);
    }
    do{
        cout<<"工人菜单\n";
        for(int i=0;i<5;i++)
        {cout<<i+1<<"、";workers[i]->Name();}
        cout<<endl;
        cout<<"1、查询工人信息\n";
        cout<<"2、计算工人周薪\n";
        cout<<"0、退出\n";
        cout<<"请选择（0-2）：";
        cin>>ch;
        switch(ch)
        {
            case '0':break;
            case '1':cout<<"请输入工人编号：";
                     cin>>find;
                     cout<<*workers[find-1]<<endl;
                     presskey();
                     break;
            case '2':cout<<"请输入工人编号：";
                     cin>>find;
                     cout<<"请输入工作时长：";
                     cin>>hours;
                     workers[find-1]->Compute_pay(hours);
                     presskey();
                     break;
            default :cout<<"\n输入有误";
                     presskey();
                     break;
        }
    }while(ch!='0');
    for(int i=0;i<5;i++)
    {delete(*(workers+i));}
    return 0;
}