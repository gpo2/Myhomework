#include<iostream>
using namespace std;
#define pai 3.14
class Cylinder
{
    double r;
    double h;
public:
    Cylinder(double R,double H)
    {
        r = R;
        h = H;
    }
    double calV()
    {
        return pai*r*r*h;
    }
};

int main()
{
    double r,h;
    cin >> r >> h;
    Cylinder cy(r,h);
    cout << "v=" << cy.calV() << endl;
    return 0;
}