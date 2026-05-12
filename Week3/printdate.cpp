#include<iostream>

using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 0,int m = 0,int d = 0)
    {
        year = y;
        month = m;
        day = d;
    }
friend ostream& operator<<(ostream&, const Date& date);
};
ostream& operator<<(ostream& os, const Date& date)
{
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
}
int main()
{
    int y = 0,m = 0,d = 0;
    cin >> y >> m >> d;
    Date date(y,m,d);
    cout << date << endl;
    return 0;
}


/*
重载运算法<<，使之能够使用cout将Date类对象的值以日期格式输出。
2006 6 1
2006-6-1
*/