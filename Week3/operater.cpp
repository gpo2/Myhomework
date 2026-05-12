#include<iostream>

using namespace std;

class Fournum
{
private:
    int value;//shi jin zhi
public:
    Fournum(int num)
    {
        value = 0;
        for(int i = num % 10,j = 1;num > 0;i = num % 10)
        {
            value += i*j;
            j *= 4;
            num /= 10;
        }
    }
    int ten_to_four(int p)
    {
        int j = 0;
        int m = 1;
        for(int i = p % 4;p > 3;i = p % 4,m *= 10)
        {
            j += i*m;
            p /= 4;
        }
        j += p*m;
        return j;
    }
    Fournum operator+(Fournum& other)
    {
        return Fournum(ten_to_four(value + other.value));
    }
    int Printvalue()
    {
        return ten_to_four(value);
    }
};

int main()
{
    int n =0,tem = 0;
    cin >> n;
    Fournum last(0);
    for(int i = 0;i < n;i++)
    {   
        cin >> tem;
        Fournum a(tem);
        last = last + a;
    }
    cout << last.Printvalue() << endl;
    return 0;
}

/*
定义一个四进制的类，重定义“+”号实现四进制数的累加。
输入：第一行输入所需要的四进制数的个数
           第二行开始，依次输入四进制数。
输出：所有输入四进制数累加的和。
*/