#include<iostream>
using namespace std;

class Employee
{
protected:
    const char* name;
    double salary;
public:
    Employee(const char* na)
    {
        name = na;
    }
    double Getsalary()
    {
        return salary;
    }
};

class Manager : virtual public Employee
{
protected:
    double fixedsalary;
public:
    Manager(const char* na,double fixsa = 8000) : Employee(na)
    {
        fixedsalary = fixsa;
        salary = fixedsalary;
    }
};

class Technician : virtual public Employee
{
protected:
    int workhour;
public:
    Technician(const char* na,int woho) : Employee(na), workhour(woho)
    {
        salary = workhour * 100;
    }
};

class Sales : virtual public Employee
{
protected:
    double Salemoney;
public:
    Sales(const char* na,double samo) : Employee(na) , Salemoney(samo)
    {
        salary = Salemoney * 0.04;
    }
};

class Salesmanager : virtual public Manager,virtual public Sales
{
public:
    Salesmanager(const char* na,double samo,double fixal = 5000) : Employee(na), Manager(na,fixal),Sales(na,samo)
    {
        salary = fixedsalary + Salemoney * 0.005;
    }

};

int main()
{
    int woti;
    double sal,sao;
    cin >> woti >> sal >> sao;
    Manager Tom("Tom");
    Technician John("Tohn",woti);
    Salesmanager Antony("Antony",sal);
    Sales Jane("Jane",sao);
    cout << "Tom本月工资" << Tom.Getsalary() << "\n" 
         << "John本月工资" << John.Getsalary() << "\n" 
         << "Antony本月工资" << Antony.Getsalary() << "\n" 
         << "Jane本月工资" << Jane.Getsalary() << endl;
    return 0;
}
/*
编写一个程序实现小型公司的工资管理。
    该公司有4类人员，经理(manager)、技术人员(technician)、销售(sales)、销售经理(salesmanager)。
    这些人员都是职员(employee)，有姓名和月工资信息。
    月工资的计算方法是：经理固定月薪8000元，技术人员每小时100元，销售员按当月销售额的4%提成，
    销售经理既拿固定月工资5000元也拿销售提成，销售提成为所管辖部门当月销售额的5‰。要求编程计算月工资并显示全部信息。

经理Tom 技术人员John 销售经理Antony 销售Jane。

由键盘输入技术人员的工时数、销售经理的部门总销售额，销售员的销售额
123?
5000000?
60000?

Tom本月工资8000?
John本月工资12300?
Antony本月工资30000?
Jane本月工资2400?
*/