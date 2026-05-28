#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
};

class Abstack
{
public:
    ListNode* bottom;
    ListNode* top;
    int height;
    int size;

    Abstack();
    Abstack(int high);
    Abstack(const Abstack& other); // Copy constructor
    ~Abstack();
    bool push(int m);
    ListNode* pop();
    void clear();
    bool isEmpty();
    void Copyqueue(Abstack enqStack, int deletimes);
};

Abstack::Abstack()
{
    bottom = nullptr;
    top = nullptr;
    height = 0;
    size = 10;
}

Abstack::Abstack(int high)
{
    bottom = nullptr;
    top = nullptr;
    height = 0;
    size = high;
}

Abstack::~Abstack()
{
    clear();
}

bool Abstack::push(int m)
{
    if(height == size)
    return false;
    else
    {
        ListNode* p = new ListNode;
        p->data = m;
        p->next = nullptr;
        if(height == 0)
        {
            top = p;
            bottom = p;
            height++;
        }
        else 
        {
            top->next = p;
            top = p;
            height++;
        }
        return true;
    }
}

ListNode* Abstack::pop()
{
    if(!height)
        return nullptr;
    else
    {
        if(height == 1)
        {
            ListNode* p = top;
            top = nullptr;
            bottom = nullptr;
            height--;
            return p;
        }
        else
        {
            ListNode* p = top;
            ListNode* q = bottom;
            while (q->next != top)
            {
                q = q->next;
            }
            top = q;
            q->next = nullptr;
            height--;
            return p;
        } 
    }
}

void Abstack::clear()
{
    ListNode* p = pop();
    while (p)
    {
        delete p;
        p = pop();
    }
}

bool Abstack::isEmpty()
{
    if(!height)
        return true;
    else
        return false;
}


ListNode* dequeue(Abstack &enqStack, Abstack &deqStack, int& deletimes)
{
    if(enqStack.height - deletimes == deqStack.height)
    {
        ListNode* p = deqStack.pop();
        deletimes++;
        return p;
    }
    else
    {
        deqStack.Copyqueue(enqStack, deletimes);
        ListNode* p = deqStack.pop();
        deletimes++;
        return p;
    }
}

inline void enqueue(Abstack& enqStack, int value)
{
    enqStack.push(value);
}

bool checkempty(Abstack& enqStack, Abstack& deqStack, int deletimes)
{
    if(deqStack.height == 0 && enqStack.height - deletimes == 0)
        return true;
    else
        return false;
}
int main()
{
    Abstack enqStack(20);
    Abstack deqStack(20);
    string str;
    int deletimes = 0;
    while(getline(cin, str))
    {
        istringstream ss(str);
        string command;
        ss >> command;
        if(command == "enqueue")
        {
            int value;
            ss >> value;
            enqueue(enqStack, value);
        }
        else if(command == "dequeue")
        {
            ListNode* p = dequeue(enqStack, deqStack, deletimes);
            if(p)
            {
                cout << p->data << endl;
                delete p;
            }
        }
        else if(command == "isEmpty")
        {
            if(checkempty(enqStack, deqStack, deletimes))
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }

}

void Abstack::Copyqueue(Abstack enqStack, int deletimes)
{
    clear();
    int count = enqStack.height - deletimes;
    for (int i = 0; i < count; i++)
    {
        ListNode* p = enqStack.pop();
        push(p->data);
        delete p;
    }
}

Abstack::Abstack(const Abstack &other)
{
    bottom = nullptr;
    top = nullptr;
    height = 0;
    size = other.size;
    ListNode* current = other.bottom;
    while (current)
    {
        push(current->data);
        current = current->next;
    }
}
