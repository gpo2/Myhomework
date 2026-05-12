#include<iostream>

using namespace std;

class RMB
{
private:
    int yuan;
    int jiao;
    int fen;
public:
    RMB(int y = 0,int j = 0,int f = 0)
    {
        yuan = y;
        jiao = j;
        fen = f;
    }
    void showrmb()
    {
        cout << yuan << "元" << jiao << "角" << fen << "分" << endl;
    }
friend RMB operator+(RMB& rmb1,RMB& rmb2);
friend RMB operator-(RMB& rmb1,RMB& rmb2);
};

RMB operator+(RMB& rmb1,RMB& rmb2);
RMB operator-(RMB& rmb1,RMB& rmb2);
int main()
{
    int yuan1(0),yuan2(0),jiao1(0),jiao2(0),fen1(0),fen2(0);
    cout << "请输入元、角、分：" << endl;
    cin >> yuan1 >> jiao1 >> fen1;
    RMB rmb1(yuan1,jiao1,fen1);
    cout << "请输入元、角、分：" << endl;
    cin >> yuan2 >> jiao2 >> fen2;
    RMB rmb2(yuan2,jiao2,fen2);
    cout << "和：";
    RMB rmb3 = rmb1 + rmb2;
    rmb3.showrmb();
    RMB rmb4 = rmb1 - rmb2;
    cout << "差：";
    rmb4.showrmb();
    return 0;
}

RMB operator+(RMB& rmb1,RMB& rmb2)
{
    int a = rmb1.yuan*100 + rmb1.jiao*10 + rmb1.fen;
    int b = rmb2.yuan*100 + rmb2.jiao*10 + rmb2.fen;
    int c = a + b;
    return RMB(c/100,(c/10)%10,c%10);
}
RMB operator-(RMB& rmb1,RMB& rmb2)
{
    int a = rmb1.yuan*100 + rmb1.jiao*10 + rmb1.fen;
    int b = rmb2.yuan*100 + rmb2.jiao*10 + rmb2.fen;
    int c = a - b;
    if(c<0)
    return RMB(c/100,((-c)/10)%10,(-c)%10);
    else
    return RMB(c/100,(c/10)%10,c%10);
}
/*
定义一个RMB类 Money，包含元、角、分三个数据成员，友元函数重载运算符‘+’（加） 和 ‘-’（减），实现货币的加减运算。

6 7 3
8 5 6

请输入元、角、分：

请输入元、角、分：

和：15元2角9分
差：-1元8角3分

*/