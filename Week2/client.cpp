#include<iostream>
#include<cstring>
using namespace std;

class Client
{
private:
    char * m_name;
    int m_age;
public:
    Client(string name, int age)
    {
        m_name = new char[name.size()+1];
        strcpy(m_name, name.c_str());
        m_age = age; 
    }
    ~Client()
    {
        delete[] m_name;
    }
    void display()
    {
        cout << "Name:" << m_name << "\n" << "Age:" << m_age << endl;
    }
};

int main()
{
    string name1;
    int age;
    cin >> name1 >> age ;
    Client Client1(name1 , age);
    Client1.display();
    return 0;
}