#include<iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int y,int m,int d)
    {
        year = y;
        month = m;
        day = d;
    }
    ~Date()
    {

    }
    int GetDay()
    {
        cout << "day " << day << endl;
    }
    int GetMonth()
    {
        cout << "month " << month << endl;
    }
    int GetYear()
    {
        cout << "year " << year << endl;
    }
    void ShowDate()
    {
        cout << year << "/" << month << "/" << day << endl;
    }
};

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    Date date1(a,b,c);
    date1.ShowDate();
    date1.GetYear();
    date1.GetMonth();
    date1.GetDay();
    return 0;
}
