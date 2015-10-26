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
    double pay_per_hour;//Сʱ���ʶ�
public:
    Worker(char *name_val,int age_val,char sex_val,double pay_per_hour_val);
    virtual void Compute_pay(double hours)=0;
    friend ostream& operator<<(ostream& out,Worker& worker);
    void Name();//�����ڲ˵��ṹ����ʾÿ�����˵�������Ϊ�û�ѡ��Ĳ˵���
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
    out<<setw(6)<<"����"<<setw(8)<<"����"<<setw(6)<<"�Ա�"<<setw(6)<<"ʱн"<<setw(10)<<"���"<<endl;
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
    double payment;//��ʱ��н
    payment=(hours<=40.0)?hours*pay_per_hour:40*pay_per_hour+1.5*(hours-40.0)*pay_per_hour;
    /*���ÿ�ܵĹ���ʱ����hours����40���ڣ�����н = Сʱ���ʶ� �� ʵ�ʹ���ʱ����
     ���ÿ�ܵĹ���ʱ����hours������40������н = Сʱ���ʶ� �� 40 + 1.5 �� Сʱ���ʶ� ����ʵ�ʹ���ʱ�� �C 40��*/
    cout<<"�˹��˵���нΪ��"<<setw(4)<<payment<<"Ԫ"<<endl;
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
    double payment;//��н��н
    payment=(hours>=35.0)?40*pay_per_hour:pay_per_hour*hours+0.5*(35.0-hours)*pay_per_hour;
    /*���ÿ�ܵ�ʵ�ʹ���ʱ��������35Сʱ����40Сʱ����н�������а�������յ���/���٣���
     ����40Сʱ���ֲ���н������н = Сʱ���ʶ� �� 40��
      ���ÿ�ܵ�ʵ�ʹ���ʱ������35Сʱ������35Сʱ����
     ����н = Сʱ���ʶ� �� ʵ�ʹ���ʱ�� + 0.5 �� Сʱ���ʶ� �� (35 - ʵ�ʹ���ʱ��)*/
    cout<<"�˹��˵���нΪ��"<<setw(4)<<payment<<"Ԫ"<<endl;
}
void presskey(){
  char ch;
  cout<<"\n********���س�������********";
  ch=getch();//�����Ժ������ӿ���̨��ȡһ���ַ���������ʾ����Ļ��,ͷ�ļ�conin.h
  if(ch!='\r'||ch!='\n') putchar('\n');
}

int main()
{
    Worker *workers[5];
   int age;
   double per_pay;
   int find;//���鹤�˱��
   char ch;
   double hours;
    cout<<"�������빤����Ϣ��"<<endl;
    for(int i=0;i<5;i++)
    {
        char name[10],sex;
        cout<<"���˱�ţ�"<<i+1<<endl;
        cout<<"������";
	cin>>name;
	cout<<"���䣺";
	cin>>age;
	cout<<"�Ա�";
	cin>>sex;
	cout<<"ʱн��";
	cin>>per_pay;
	cout<<endl;
	if(per_pay==30||per_pay==50)
            *(workers+i)=new SalariedWorker(name,age,sex,per_pay);
        else
            *(workers+i)=new HourlyWorker(name,age,sex,per_pay);
    }
    do{
        cout<<"���˲˵�\n";
        for(int i=0;i<5;i++)
        {cout<<i+1<<"��";workers[i]->Name();}
        cout<<endl;
        cout<<"1����ѯ������Ϣ\n";
        cout<<"2�����㹤����н\n";
        cout<<"0���˳�\n";
        cout<<"��ѡ��0-2����";
        cin>>ch;
        switch(ch)
        {
            case '0':break;
            case '1':cout<<"�����빤�˱�ţ�";
                     cin>>find;
                     cout<<*workers[find-1]<<endl;
                     presskey();
                     break;
            case '2':cout<<"�����빤�˱�ţ�";
                     cin>>find;
                     cout<<"�����빤��ʱ����";
                     cin>>hours;
                     workers[find-1]->Compute_pay(hours);
                     presskey();
                     break;
            default :cout<<"\n��������";
                     presskey();
                     break;
        }
    }while(ch!='0');
    for(int i=0;i<5;i++)
    {delete(*(workers+i));}
    return 0;
}