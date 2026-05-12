#include<iostream>
using namespace std;
const double pi = 3.14159;

class Circle
{
private:
    double r;
public: 
    Circle(double r1)
    {
        r = r1;
    }
    double callength()
    {
        return  2*pi*(r+3);
    }
    double calarea()
    {
        return pi*((r+3)*(r+3)-r*r);
    }
};

int main()
{
    double R;
    cin >> R ;
    Circle a(R);
    cout << "Enter the radius of the pool:" << R << endl;
    cout << "Fencing Cost is " << a.callength()*35 << endl;
    cout << "Concrete Cost is " << a.calarea()*20 << endl;
}
