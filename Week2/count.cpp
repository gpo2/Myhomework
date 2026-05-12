#include<iostream>

using namespace std;

class Count 
{
    int count;
public:
    Count(int a = 0)
    {
        count = a;
    }
    void h()
    {
        count ++;
    }
    void show()
    {
        cout << "Words=" << count << endl;
    }
};

int main()
{   
    Count a;
    char b = getchar(); 
    if(b!=10)
    {
        a.h();
    }
    for(;b != 10;b = getchar())
    {
        if(b == 32)
        a.h();
    }
    a.show();
    return 0;
}