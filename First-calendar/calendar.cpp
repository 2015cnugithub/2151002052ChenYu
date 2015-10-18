#include<iostream>
#include<iomanip>//���Ƹ�ʽ���������
using namespace std;
    int TotalDay(int year,int month);
    int ShowCalendar(int year,int month);//��ʾĳ��ĳ������
    bool IsLeapYear(int year);
    int GetDayofMonth(int year,int month);

    bool IsLeapYear(int year)
    {//�ж�����
        return((year%4==0 && year%100!=0) ||
               (year%400==0));
    }
    int GetDayofMonth(int year,int month)
    {//����ĳ��ĳ������
        int day;
        if(month==2){
            if(IsLeapYear(year)) day=29;
            else day=28;
        }
        else{
            if((month==4)||(month==6)||(month==9)||(month==11))
                day=30;
            else day=31;
        }
        return day;
    }

int TotalDay(int year,int month)
{//���������2015��9�£��򷵻ص�total��1800��1��1�յ�2015��8��31�յ�������
    int total,i;
    for(i=1800,total=0;i<year;i++)
    {
       if(IsLeapYear(i)) total+=366;
        else total+=365;
    }
    for(i=1;i<month;i++)
    {total+=GetDayofMonth(year,i);}
    return total;

}
int ShowCalendar(int year,int month)
{
    int excur,i,currentmonth;
    excur=(TotalDay(year,month)+3)%7;//ǰ�����һ�����ڼ�������1800��1��1����������;
    cout<<year<<"��"<<month<<"��"<<endl;
    cout<<setw(4)<<"��"<<setw(4)<<"һ"<<setw(4)<<"��";
    cout<<setw(4)<<"��"<<setw(4)<<"��"<<setw(4)<<"��";
    cout<<setw(4)<<"��"<<endl;
    for(i=1;i<=excur;i++)
        cout<<setw(4)<<" ";//�������ո�
    currentmonth=GetDayofMonth(year,month);//�����·ݵ�����
    for(i=1;i<=currentmonth;i++)
    {
        cout<<setw(4)<<i;
        if((i+excur)%7==0) cout<<endl;//���У���һ������
    }
    cout<<endl;
    return 0;
}
int main()
{
    int year,month;
    cout<<"��������ݼ��·�:"<<endl;
    cin>>year>>month;
    cout<<"��ʾ����:";
    ShowCalendar(year,month);
    return 0;
}

