#include<iostream>
using namespace std;

class Time
{
private:
    int Hour;
    int Minute;
    int Second;
public:
    Time(int a,int b,int c)
    {
        Hour = a;
        Minute = b;
        Second = c;
    }
    void show()
    {
        cout << Hour << ":" << Minute << ":" << Second << endl;
    }
};

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    Time now(a,b,c);
    now.show();
    return 0;
}