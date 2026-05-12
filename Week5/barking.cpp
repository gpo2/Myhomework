#include<iostream>
using namespace std;
class Felid
{
public:
Felid()
{
    cout << "Felid constructor" << endl;
}
virtual ~Felid()
{
    cout << "Felid destructor" << endl;
}
virtual void sound()
{
    cout << "Miaow !" << endl;
}
};

class Cat : public Felid
{
public:
    Cat()
    {
        cout << "Cat constructor" << endl;
    }
    ~Cat()
    {
        cout << "Cat destructor" << endl;
    }
    void sound()
    {
        cout << "Miaow !" << endl;
    }
};
class Leopard : public Felid
{
public:
    Leopard()
    {
        cout << "Leopard constructor" << endl;
    }
    ~Leopard()
    {
        cout << "Leopard destructor" << endl;
    }
    void sound()
    {
        cout << "Howl !" << endl;
    }
};
int main()
{
    Felid *p1;
    p1 = new Cat;
    p1->sound();
    delete p1;
    Felid *p2;
    p2 = new Leopard;
    p2->sound();
    delete p2;
    return 0;
}
/*
定义猫科动物Felid类，由其派生出猫类（Cat）和豹类（Leopard）。

Felid包含构造函数、析构函数和纯虚函数sound

Cat包含构造函数、析构函数和虚函数sound

Leopard包含构造函数、析构函数和虚函数sound

要求：定义一个Felid类指针，采用动态内存分配的方式建议一个Cat对象，并且调用sound函数，之后撤销该对象，
采用动态内存分配的方式建议一个Leopard对象，并且调用sound函数，之后撤销该对象。

提示：虚析构函数

Felid constructor↵
Cat constructor↵
Miaow !↵
Cat destructor↵
Felid destructor↵
Felid constructor↵
Leopard constructor↵
Howl !↵
Leopard destructor↵
Felid destructor↵
*/