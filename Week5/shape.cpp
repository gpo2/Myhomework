#include<iostream>

using namespace std;

#define pai 3.14
class Shape
{
private:

public:
    virtual double Area()
    {

    }
    virtual double Volume()
    {

    }
};

class Juxing : public Shape
{
private:
    double a;
public:
    Juxing(double a1 = 0)
    {
        a = a1;
    }
    double Area()
    {
        return 6 * a * a;
    }
    double Volume()
    {
        return a * a * a;
    }
};

class Qiu : public Shape
{
private:
    double r;
public:
    Qiu(double r1 = 0)
    {
        r = r1;
    }
    double Area()
    {
        return 4 * pai * r * r;
    }
    double Volume()
    {
        return 4 * pai * r * r * r / 3;
    }
};

class Yuanzhu : public Shape
{
private:
    double r;
    double h;
public:
    Yuanzhu(double r1 = 0,double h1 = 0)
    {
        r = r1;
        h = h1;
    }
    double Area()
    {
        return 2 * pai * r * r + 2 * pai * r * h;
    }
    double Volume()
    {
        return pai * r * r * h;
    }
};

int main()
{    
    double a,r,rr,h;
    cin >> a >> r >> rr >> h;
    Shape *p1,*p2,*p3;
    p1 = new Juxing(a);
    p2 = new Qiu(r);
    p3 = new Yuanzhu(rr,h);
    cout << "Shape：正方体\n 面积、体积：" << p1->Area() << " " << p1->Volume() << "\n" << "Shape：球体\n 面积、体积：" << p2->Area() << " " << p2->Volume() << "\n" << "Shape：圆柱体\n 面积、体积：" << p3->Area() << " " << p3->Volume() << endl;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}
/*
定义一个抽象类Shape，在此基础上派生出正方体类、球体类和圆柱体类，都有计算对象表面积和体积的函数Area()和计算对象体积的函数Volume ()，
在主函数中定义一个Shape指针数组分别指向正方体类、球体类和圆柱体类的对象，并通过Shape类的指针实现对这3个对象的成员函数的调用，
输出正方体、球体和圆柱体的表面积和体积。

输入：第一行：正方体边长；

           第二行：球体半径；

           第三行：圆柱体的半径，高度。

输出：

Shape：正方体

 面积、体积：** **  

Shape：球体

 面积、体积：** **

Shape：圆柱体

 面积、体积：** **


*/