#include<iostream>
using namespace std;

template<class T>
class input
{
private:
    T min;
    T max;
public:
    input(T x,T y)
    {
        min = x;
        max = y;
    }
    void output(T out)
    {
        if(out >= min && out <= max)
        {
            cout << out << endl;
        }
        else
        {
            cout << "数据不符合范围，请重新输入。" << endl;
        }
    }
};


int main() {  
    int x, y, z;  
    cin >> x >> y >> z;  
    char a, b, c;  
    cin >> a >> b >> c;  
    input< int> in1(x, y);  
    in1.output(z);  
      
    input < char> in2(a, b);  
    in2.output(c);  
  
}  

/*
建立类模板input，在调用构造函数时，完成以下工作：

（1）分别给定数值的输出范围（通过设定最小值与最大值）

（2）输入一个待输出数字或字符，符合范围内(闭区间)便输出；不符合范围内显示 “数据不符合范围，请重新输入”。

输入格式：

第一行：数字的最小值，数字的最大值，待输出数字。

第二行：字符的最小值，字符的最大值，待输出字符。

输出格式：

第一行：待输出数字。

第二行：待输出字符。
*/