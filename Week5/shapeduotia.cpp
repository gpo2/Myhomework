#include<iostream>
using namespace std;

const double pai = 3.1415926;
class Shape
{
public:
    Shape()
    {
        cout << "Shape constructor" << endl;
    }
    ~Shape()
    {
        cout << "Shape destructor" << endl;
    }
    virtual void calcArea(){}//用来计算形状的面积；

    virtual void calcVolume(){}//用来计算形状的体积；

    virtual void set_r(double r){}//设置数据成员r的值；

    virtual void set_a(double a){}//设置数据成员a的值；

    virtual void set_b(double b){}//设置数据成员b的值；

    virtual void set_c(double c){}//设置数据成员c的值；

    virtual void printValue(){}//显示所有成员变量的值。
};

class Circle : public Shape
{
protected:
    double r,s;
public:
    Circle(double rad) : r(rad)
    {
        cout << "Circle constructor" << endl;
    }
    ~Circle()
    {
        cout << "Circle destructor" << endl;
    }
    void calcArea()
    {
        s = pai * r * r;
    }
    void set_r(double rad)//设置圆半径 r 的值；
    {
        r = rad;
    }

void printValue()//输出r和s的值；
    {
        cout << "Circle" << "\n" << "r=" << r << "\n" << "s=" << s << endl;
    }
};

class Rectangle : public Shape
{
protected:
    double a,b,s;
public:
    Rectangle(double a1,double b1) : a(a1), b(b1)
    {
        cout << "Rectangle constructor" << endl;
    }
    ~Rectangle()
    {
        cout << "Rectangle destructor" << endl;
    }
    void calcArea()//计算矩形面积；
    {
        s = a * b;
    }
    void set_a(double a1)//设置矩形长a的值；
    {
        a = a1;
    }
    void set_b(double b1)//设置矩形宽b的值；
    {
        b = b1;
    }
    void printValue()//输出a、b和s的值；
    {
        cout << "Rectangle" << "\n" << "a=" << a << "\n" << "b=" << b << "\n" << "s=" << s << endl;
    }
};

class Cuboid : public Shape
{
protected:
    double a,b,c,v;
public:
    Cuboid(double a1,double b1,double c1) : a(a1),b(b1),c(c1)
    {
        cout << "Cuboid constructor" << endl;
    }
    ~Cuboid()
    {
        cout << "Cuboid destructor" << endl;
    }
    void calcVolume()//计算长方体体积；
    {
        v = a * b * c;
    }
    void set_a(double a1)//设置长方体长a的值；
    {
        a = a1;
    }
    void set_b(double b1)//设置长方体宽b的值；
    {
        b = b1;
    }
    void set_c(double c1)//设置长方体高c的值；
    {
        c = c1;
    }
    void printValue()//输出a、b、c和v的值；
    {
        cout << "Cuboid" << "\n" << "a=" << a << "\n" << "b=" << b << "\n" << "c=" << c << "\n" << "v=" << v << endl;
    }
};

int main()
{
    int i = 0;
    cin >> i;
    switch (i)
    {
    case 1:
        {
            double r;
            cin >> r;
            Circle cir(r);
            cir.calcArea();
            cir.printValue();
        }
        break;
    case 2:
        {
            double a,b;
            cin >> a >> b;
            Rectangle rec(a,b);
            rec.calcArea();
            rec.printValue();
        }
        break;
    case 3:
        {
            double a,b,c;
            cin >> a >> b >> c;
            Cuboid cub(a,b,c);
            cub.calcVolume();
            cub.printValue();
        }
        break;
    default:
        break;
    }
}
/*
设计一个几何图形基类Shape及其派生类 Circle、Rectangle和Cuboid实现以下功能：

1. Shape类

纯虚函数：

void calcArea()，用来计算形状的面积；

void calcVolume()，用来计算形状的体积；

void set_r(double r)，设置数据成员r的值；

void set_a(double a)，设置数据成员a的值；

void set_b(double b)，设置数据成员b的值；

void set_c(double c)，设置数据成员c的值；

void printValue()，显示所有成员变量的值。

2. Circle类公有继承自Shape类

成员变量：double r，s，其中 r 为圆的半径，s 为圆的面积，初值均为0；

虚函数实现： 

void calcArea()，计算圆面积；

void set_r(double r)，设置圆半径 r 的值；

void printValue()，输出r和s的值；

3. Rectangle类公有继承自Shape类

成员变量：double a，b，s，其中 a 和 b 分别为矩形的长和宽，s 为矩形的面积，初值均为0；

虚函数实现： 

void calcArea()，计算矩形面积；

void set_a(double a)，设置矩形长a的值；

void set_b(double b)，设置矩形宽b的值；

void printValue()，输出a、b和s的值；

3. Cuboid类公有继承自Shape类

成员变量：double a，b，c，v，其中 a、b 和 c 分别为矩形的长、宽和高，v 为长方体的体积，初值均为0；

虚函数实现： 

void calcVolume()，计算长方体体积；

void set_a(double a)，设置长方体长a的值；

void set_b(double b)，设置长方体宽b的值；

void set_c(double c)，设置长方体高c的值；

void printValue()，输出a、b、c和v的值；


4. 圆周率 pi=3.1415926，通过基类指针指向派生类的对象实现多态，采用虚析构函数正确析构派生类的对象，所有数据成员均定义为私有访问属性，通过公有访问属性的成员函数访问。



输入包含两行，
    第一行为形状选择，输入1表示圆形，输入2表示矩形，输入3表示长方体；
    第二行输入对应的形状的参数，
        圆形输入半径 r，
        矩形输入长 a 和宽 b，
        长方体输入长 a、宽 b 和高 c，
    用空格分隔。

输出为对应形状字符串和对应的参数值，
    圆形输出字符串 “Circle”、半径和面积，
    矩形输出字符串 “Rectangle”、长、宽和面积，
    长方体输出字符串 “Cuboid”、长、宽、高和体积，
每行输出一个参数。

同时，各类的构造函数和析构函数执行时输出响应的字符串，见输入输出示例。

输入输出示例如下：

输入：

1

10

输出：

Shape constructor

Circle constructor

Circle

r=10

s=314.159

Circle destructor

Shape destructor
*/