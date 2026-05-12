#include<iostream>
#include<string>
using namespace std;

class Book
{
protected:
    int booknum;
    string bookname;
    string publishinghouse;
    double price;
public:
    Book()
    {

    }
    void show()
    {
        cout << "Num:" << booknum << "\nBookName:" << bookname << "\nBookConcern:" << publishinghouse << "\nPrice:" << price << endl;
    }
};

class Author
{
protected:
    string name;
    int age;
    int writetime[3];
public:
    Author()
    {

    }
    void show()
    {
        cout << "AuthorName:" << name << "\nAuthorAge:" << age << "\nPrintTime:" << writetime[0] << "-" << writetime[1] << "-" << writetime[2] << endl;
    }
};

class Card : public Book , public Author
{
protected:
    string systemname;
public:
    Card(string sysname,int bonum,string bona,string bopub,double pri,string auname,int autag,int wrti[3])
    {
        systemname = sysname;
        booknum = bonum;
        bookname = bona;
        publishinghouse = bopub;
        price = pri;
        name = auname;
        age = autag;
        int i = 0;
        while(i<3)
        {
            writetime[i] = wrti[i];
            i++;
        }
    }
    void show()
    {
        cout << "SysName:" << systemname << endl; 
    }
};

int main()
{
    string sysname,bona,bopub,auname;
    int bonum,autag,wrti[3];
    double pri;
    cin >> sysname;
    cin >> bonum;
    cin >> bona >> bopub >> pri >> auname >> autag;
    for(int i = 0;i < 3;i++)
    {
        cin >> wrti[i];
    }
    Card car(sysname,bonum,bona,bopub,pri,auname,autag,wrti);
    car.Card::show();
    car.Book::show();
    car.Author::show();
    return 0;
}

/*
编写一个程序，其中有一个书类book，该类的数据成员包括：书号、书名、出版社和定价；
有一个作者类author，该类的数据成员包括：姓名、年龄和写作时间，
每个类都有相应的数据输入、输出。
以此两个类为基类，派生出图书查询卡card，并增加一个数据成员表示书籍系统名称，及一个可以显示系统名称、书名、作者、作者年龄、出版社和定价等数据的函数。

注： 输入数据内容有
  系统名称  图书编号  图书名 出版社 定价
  作者姓名 作者年龄 写作时间
输入：
BitLibrary
1001
C++Language
Bitcon
24.8
Lichunbao
40
2001 10 10
输出：

SysName:BitLibrary
Num:1001
BookName:C++Language
BookConcern:Bitcon
Price:24.8
AuthorName:Lichunbao
AuthorAge:40
PrintTime:2001-10-10 
*/