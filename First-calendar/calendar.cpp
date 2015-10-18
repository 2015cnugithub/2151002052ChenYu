#include<iostream>
#include<iomanip>//控制格式化输入输出
using namespace std;
    int TotalDay(int year,int month);
    int ShowCalendar(int year,int month);//显示某年某月日历
    bool IsLeapYear(int year);
    int GetDayofMonth(int year,int month);

    bool IsLeapYear(int year)
    {//判断闰年
        return((year%4==0 && year%100!=0) ||
               (year%400==0));
    }
    int GetDayofMonth(int year,int month)
    {//返回某年某月天数
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
{//若输入的是2015年9月，则返回的total是1800年1月1日到2015年8月31日的总天数
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
    excur=(TotalDay(year,month)+3)%7;//前月最后一天星期几，假设1800年1月1日是星期三;
    cout<<year<<"年"<<month<<"月"<<endl;
    cout<<setw(4)<<"日"<<setw(4)<<"一"<<setw(4)<<"二";
    cout<<setw(4)<<"三"<<setw(4)<<"四"<<setw(4)<<"五";
    cout<<setw(4)<<"六"<<endl;
    for(i=1;i<=excur;i++)
        cout<<setw(4)<<" ";//输出多余空格
    currentmonth=GetDayofMonth(year,month);//输入月份的天数
    for(i=1;i<=currentmonth;i++)
    {
        cout<<setw(4)<<i;
        if((i+excur)%7==0) cout<<endl;//换行，周一到周日
    }
    cout<<endl;
    return 0;
}
int main()
{
    int year,month;
    cout<<"请输入年份及月份:"<<endl;
    cin>>year>>month;
    cout<<"显示日历:";
    ShowCalendar(year,month);
    return 0;
}

