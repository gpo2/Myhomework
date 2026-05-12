#include<iostream>
#include<vector>

using namespace std;
class Date;
class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int newh = 0,int newm = 0,int news = 0)
    {
        hour = newh;
        minute = newm;
        second = news;
    }
friend void display(Date& date,Time& time); 
};

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int newy = 0,int newm = 0,int newd = 0):
    year(newy),month(newm),day(newd)
    {}
friend void display(Date& date,Time& time);
};

void display(Date& date,Time& time);

int main()
{
    int year,month,day,hour,minute,second;
    cin >> year >> month >> day >> hour >> minute >> second;
    Date date(year,month, day);
    Time time(hour,minute,second);
    display(date,time); 
    return 0;
}

void display(Date& date,Time& time)
{
    cout << date.year << "/" << date.month << "/" << date.day << endl;
    cout << time.hour << ":" << time.minute << ":" << time.second << endl;
}
/*设计一个日期类和时间类，编写display函数用于显示日期和时间。
要求：display函数作为类外的普通函数，分别在Time和Date类中将display声明为友元函数。
在主函数中调用display函数，display函数分别引用Time和Date两个类的对象的私有数据，输出年、月、日和时、分、秒。

2022 12 31 8 15 26↵

2022/12/31↵
8:15:26↵
*/
