#include<iostream>

using namespace std;
class Person
{
protected:
    string name;
    int sex;
    int age;
public:
    Person():name("LiHua"),sex(1),age(18){}
    void show()
    {
        cout << "name:" << name <<  "\nage:" << age << "\nsex:";
        if(sex == 1)
        {
            cout << "男\n";
        }
        else
        {
            cout << "女\n";
        }
    }
};

class Employee : public Person 
{
protected:
    int basicSalary;
    int leaveDays;
public:
    Employee(string n ,int a,int s,int b,int l)
    {
        name = n;
        age = a ,sex = s ,basicSalary = b ,leaveDays = l;
    }
    void show()
    {
        cout << "name:" << name <<  "\nage:" << age << "\nsex:";
        if(sex == 1)
        {
            cout << "男\n";
        }
        else
        {
            cout << "女\n";
        }
        cout << "basicSalary:" << basicSalary << "\nleavedays:" << leaveDays << endl;
    }
};

int main()
{
    string n;
    int a,s,b,l;
    cin >> n >> s >> a >> b >> l;
    Employee Em(n,a,s,b,l);
    Em.show();
}
/*
定义一个基类Person，它有3个protected的数据成员：姓名name(char  类型)、性别 sex(1表示男，0表示女)、年龄age(int 类型)；
一个构造函数用于对数据成员初始化；有一个成员函数show()用于输出数据成员的信息。

创建Person类的公有派生类Employee，增加两个数据成员： 基本工资 basicSalary（int类型）和 请假天数leaveDays（int型）；
为它定义初始化成员信息的构造函数，和显示数据成员信息的成员函数show()。

输入：依次输入姓名，性别（0或1），年龄，基本工资，请假天数。
LiHua?
0?
23?
8000?
7?
输出：录入的信息。
name:LiHua?
age:23?
sex:女?
basicSalary:8000?
leavedays:7?
*/