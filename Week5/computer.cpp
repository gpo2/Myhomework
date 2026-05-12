#include<iostream>
using namespace std;

class Cpu
{
public:
    virtual void cry()
    {
        cout << "This is a cpu" << endl;
    } 
};

class Gpu
{
public:
    virtual void cry()
    {

    }
};

class Neicun
{
public:
    virtual void cry()
    {

    }
};

class Intel_cpu : public Cpu
{
public:
    void cry()
    {
        cout << "Intel的CPU开始计算了" << endl;
    }
};

class Lenovo_cpu : public Cpu
{
public:
    void cry()
    {
        cout << "Lenovo的CPU开始计算了" << endl;
    }
};

class Intel_gpu : public Gpu
{
public:
    void cry()
    {
        cout << "Intel的显卡开始显示了" << endl;
    }
};

class Lenovo_gpu : public Gpu
{
public:
    void cry()
    {
        cout << "Lenovo的显卡开始显示了" << endl;
    }
};

class Intel_neicun : public Neicun
{
public:
    void cry()
    {
        cout << "Intel的内存条开始存储了" << endl;
    }
};

class Lenovo_neicun : public Neicun
{
public:
    void cry()
    {
        cout << "Lenovo的内存条开始存储了" << endl;
    }
};

class Computer
{
private:
    Cpu *cpu;
    Gpu *gpu;
    Neicun *neicun;
public:
    ~Computer()
    {
        delete cpu;
        delete gpu;
        delete neicun;
    }
    void choosecpu(int i)
    {   
        if(i == 1)
        {
            cpu = new Intel_cpu;
        }
        else
        {
            cpu = new Lenovo_cpu;
        }
    }
    void choosegpu(int i)
    {
        if(i == 1)
        {
            gpu = new Intel_gpu;
        }
        else
        {
            gpu = new Lenovo_gpu;
        }
    }
    void chooseneicun(int i)
    {
        if(i == 1)
        {
            neicun = new Intel_neicun;
        }
        else
        {
            neicun = new Lenovo_neicun;
        }
    }
    void run()
    {
        cpu->cry();
        gpu->cry();
        neicun->cry();
    }
};

int main()
{
    int input[3] = {0};
    cin >> input[0]  >> input[1] >> input[2];
    Computer computer;
    computer.choosecpu(input[0]);
    computer.choosegpu(input[1]);
    computer.chooseneicun(input[2]);
    computer.run();
    return 0;
}
/*
计算机由cpu、内存条、存储器三种零件组成。生产零件的两大厂商 是intel和lenovo，每个厂商可以通过继承和多态来创建自己的cpu、内存条和存储器。继承关系建议可以用下图的方法设置：三个零件各自设置抽象基类，每个抽象基类都派生出了两个具体的子类，表示两种厂商的零件。计算机类的成员变量可以设置为三个基类的指针，指针根据要求可以指向不同厂商的零件。在主函数中，通过1和2选择厂商来设置计算机类中零件的指针，1代表intel,2代表lenovo。



输入输出示例如下：

输入：1 2 2

输出：

Intel的CPU开始计算了

Lenovo的显卡开始显示了

Lenovo的内存条开始存储了
*/