#include<iostream>

using namespace std;

class Building
{
protected:
    int floor;
    int room;
    double area;
public:
    Building(int fl = 1,int ro = 3,double ar = 100)
    {
        floor = fl;
        room = ro;
        area = ar;
    }
    void show()
    {
        cout << floor << "\n" << room << "\n" << area << endl;
    }
};

class Office : public Building
{
protected:
    int tables;
    int Phones;
public:
    Office(int fl,int ro,double ar,int ta,int ph)
    {
        floor = fl;
        room = ro;
        area = ar;
        tables = ta;
        Phones = ph;
    }
    void show()
    {
        cout << "office_information" << "\nfloor:" << floor << "\nroom:" << room << "\narea:" << area << "\ntables:" << tables << "\nPhones:" << Phones << endl;
    }
};

class House : public Building
{
protected:
    int Bedrooms;
    int Bathrooms;
public:
    House(int fl,int ro,double ar,int be,int ba)
    {
        floor = fl;
        room = ro;
        area = ar;
        Bedrooms = be;
        Bathrooms = ba;
    }
    void show()
    {
        cout << "house_information" << "\nfloor:" << floor << "\nroom:" << room << "\narea:" << area << "\nBedrooms:" << Bedrooms << "\nBathrooms:" << Bathrooms << endl;
    }
};

int main()
{
    int fl,ro,be,ba,ta,ph;
    double ar;
    cin >> fl >> ro >> ar >> be >> ba;
    House hou(fl,ro,ar,be,ba);
    hou.show();
    cin >> fl >> ro >> ar >> ta >> ph;
    Office off(fl,ro,ar,ta,ph);
    off.show();
    return 0;
}
/*
一个建筑物（building）包含基本的信息，由该建筑物可以得到办公室（office）和家（house）；他们又有各自特殊属性。具体要求如下：
（1）定义一个基类building,内有数据成员：
    层数（floor：int 类型）、房间（room：int 类型）和面积（area：double 类型)。定义自己的构造函数和输出函数
（2）定义一个家类House，它是building类的派生类，在类中添加数据成员：
    Bedrooms（int 类型）、Bathrooms（int 类型），定义自己的构造函数和输出函数，在构造函数中继承基类的函数。
（3）定义一个办公室类Office，它是building类的派生类，在类中添加数据成员：
    tables（int 类型）,Phones（int 类型）
（4）定义主函数进行测试。
数据输入输出顺序格式如下：

输入：3 5 100 2 3

输出：house_information

floor:3

room:5

area:100

Bedrooms:2

Bathrooms:3

再次输入：3 5 100 8 6

输出：office_information

floor:3

room:5

area:100

tables:8

Phones:6
*/