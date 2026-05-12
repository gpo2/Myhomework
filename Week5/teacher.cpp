#include<iostream>

using namespace std;

class Teacher
{
protected:
    const char* position;
    char* name;
    char* sex;
    int num;
    int fixed_salary;
    int worktime;
    int allsalary;
public:
    virtual void show()
    {

    }
    virtual void pay()
    {

    }
};

class Professor : public Teacher
{
public:
    Professor(char* na,char* se,int nu,int woti)
    {
        position = "教授";
        name = na;
        sex = se;
        num = nu;
        fixed_salary = 20000;
        worktime = woti;
    }
    void show()
    {
        cout << "职称：" << position << "\n" << "姓名：" << name << "\n" << "性别：" << sex << "\n" 
        << "工号：" << num << "\n" << "课时数：" << worktime << "\n" << "本月工资：" << allsalary << endl;
    }
    void pay()
    {
        allsalary = fixed_salary + worktime*50;
    }
};

class Subprofessor : public Teacher
{
public:
    Subprofessor(char* na,char* se,int nu,int woti)
    {
        position = "副教授";
        name = na;
        sex = se;
        num = nu;
        fixed_salary = 15000;
        worktime = woti;
    }
    void show()
    {
        cout << "职称：" << position << "\n" << "姓名：" << name << "\n" << "性别：" << sex << "\n" 
        << "工号：" << num << "\n" << "课时数：" << worktime << "\n" << "本月工资：" << allsalary << endl;
    }
    void pay()
    {
        allsalary = fixed_salary + worktime*30;
    }
};

class Lecturer : public Teacher
{
public:
    Lecturer(char* na,char* se,int nu,int woti)
    {
        position = "讲师";
        name = na;
        sex = se;
        num = nu;
        fixed_salary = 10000;
        worktime = woti;
    }
    void show()
    {
        cout << "职称：" << position << "\n" << "姓名：" << name << "\n" << "性别：" << sex << "\n" 
        << "工号：" << num << "\n" << "课时数：" << worktime << "\n" << "本月工资：" << allsalary << endl;
    }
    void pay()
    {
        allsalary = fixed_salary + worktime*20;
    }
};

int main()
{
    char* na = (char*)malloc(sizeof(char(100))), *se = (char*)malloc(sizeof(char(100)));
    int nu,woti,position;
    cin >> position; 
    cin >> na;
    cin >> se;
    cin >> nu;
    cin >> woti;
    switch (position)
    {
    case 1:
        {
            Professor pro(na,se,nu,woti);
            pro.pay();
            pro.show();
            break;
        }
    case 2:
        {
            Subprofessor sub(na,se,nu,woti);
            sub.pay();
            sub.show();
            break;
        }
    case 3:
        {
            Lecturer lec(na,se,nu,woti);
            lec.pay();
            lec.show();
            break;
        }
    default:
        break;
    }
    return 0;
}
/*
某学校对教师工资的计算公式如下：
    固定工资+课时补贴。
    教授的固定工资为20000元，每个课时补贴50元；
    副教授的固定工资为15000元，每个课时补贴30元；
    讲师的固定工资为10000元，每个课时补贴20元。

要求：

定义教师抽象类，
    数据成员包括姓名，性别，工号，固定工资，课时数（上课总的时间），总工资；
    成员函数pay计算总工资，将其定义为虚函数（因计算方法不同），其他成员函数根据需要进行定义。
    派生出不同职称的教师类（每个类具有相同的数据成员）；不同类的工资计算方法不同（课时工资不同），
编写程序求教师的工资。

1?
Bob?
male?
1001?
36?

职称：教授?
姓名：Bob?
性别：male?
工号：1001?
课时数：36?
本月工资：21800?
*/