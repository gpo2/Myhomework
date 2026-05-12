#include<iostream>
using namespace std;

const double pai = 3.14159;
class Shape
{
public:
    virtual void area()
    {}
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double r) : radius(r)
    {

    }
    void area()
    {
        cout << "area of circle = " << pai * radius * radius << endl;
    }
};

class Rectangle : Shape
{
private:
    double length;
    double width;
public:
    Rectangle(double l,double w) : length(l) , width(w)
    {
        
    }
    void area()
    {
        cout << "area of rectangle = " << length * width << endl;
    }
};

int main()
{
    double r,l,w;
    cout << "请输入圆的半径" << endl;
    cin >> r;
    Circle cir(r);
    cir.area();
    cout << "请输入矩形的长和宽" << endl;
    cin >> l >> w;
    Rectangle rec(l,w);
    rec.area();
    return 0;
}
/*
定义抽象基类Shape，由它派生出2个类: Circle (圆形)、Rectangle (矩形)，显示两个图形的面积（圆周率用3.14159代替）。

要求:

(1)抽象基类Shape的公有成员有纯虚函数area()。

(2) Circle类公有继承自Shape类，新增数据成员radius (半径)，公有成员有构造函数和求圆面积的area()函数。

(3) Rectangle 类公有继承自Shape类，新增数据成员length (长)、width (宽)，公有成员有构造函数和求矩形面积的area()函数。

(4)在main()函数定义Circle类的对象circle1并赋初值，调用area()函数显示该圆面积;定义Rectangle类的对象rectangle1并赋初值，调用area ()函数显示该矩形面积。

请输入圆的半径?
area of circle = 12.5664?
请输入矩形的长和宽?
area of rectangle = 18?
*/