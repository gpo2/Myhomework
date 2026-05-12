#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a>=b&&a>=c)
    {
        cout << "Maximum:" << a << endl;
    }
    else if(b>=a&&b>=c)
    {
        cout << "Maximum:" << b  << endl;
    }
    else
    {
        cout << "Maximum:" << c << endl;
    }
    return 0;
}