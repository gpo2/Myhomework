#include<iostream>

using namespace std;

class People
{
protected:
    string name;
    string sex;
    int age;
public:
    void show()
    {
    cout << "People:\n" << "Name:" << name << "\nSex:"  << sex << "\nAge:" << age << "\n" <<endl;
    }
};

class Student : virtual public People
{
protected:
    int studentnum;
    int score;
public:
    void show()
    {
        cout << "Student:\n" << "Name:" << name << "\nSex:" << sex << "\nAge:" << age << "\nNo.:" << studentnum << "\nScore:" << score << "\n" << endl;
    }
};

class Teacher : virtual public People
{
protected:
    string duty;
    string department;
public:
    void show()
    {
        cout << "Teacher:\n" << "Name:" << name << "\nSex:" << sex << "\nAge:" << age << "\nPosition:" << duty << "\nDepartment:" << department << "\n" <<endl;
    }
};
class GradOnWork : public Student, public Teacher
{
protected:
    string reserchdic;
    string tutor;
public:
    GradOnWork(string na,string se,string pos,string depa,string tu,string dic,int ag,int nu,int sco)
    {
        name = na;
        sex = se;
        duty = pos;
        department = depa;
        tutor = tu;
        reserchdic = dic;
        age = ag;
        studentnum = nu;
        score = sco;
    }
    void show()
    {
        cout << "GardOnWork:\n"
        << "Name:" << name << "\nSex:" << sex << "\nAge:" << age
        << "\nNo.:" << studentnum << "\nScore:" << score
        << "\nPosition:" << duty << "\nDepartment:" << department 
        << "\nDirection:" << reserchdic << "\nTutor:" << tutor << endl;
    }
};

int main()
{
    string na,se,pos,depa,tu,dic;
    int ag,nu,sco;
    cin >> na >> se >> ag >> nu >> sco >> pos >> depa >> dic >> tu;
    GradOnWork a(na,se,pos,depa,tu,dic,ag,nu,sco);
    a.Student::People::show();
    a.Teacher::show();
    a.Student::show();
    a.show();
    return 0;
}
/*
定义一个人员类People，其属性（保护类型）有：姓名、性别、年龄；

从People类派生出学生类Student，添加属性：学号和入学成绩；

从People类再派生出教师类Teacher，添加属性：职务、部门；

从Student和Teacher类共同派生出在职研究生类GradOnWork，添加属性：研究方向、导师；

分别定义以上类的构造函数、输出函数及其他函数（如需要）。

输入：

第一行：姓名，性别，年龄；

第二行：学号，成绩；

第三行：职务，部门；

第四行：研究方向，导师；

输出：各类的成员输出，具体可见实例。
*/