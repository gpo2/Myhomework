#include<iostream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
};

class Ablist
{
public:
    int size;
    ListNode* head;

    Ablist()
    {
        size =0;
        head = nullptr;
    }
    ~Ablist()
    {
        deletelist();
    }
    ListNode* findx(int x);
    ListNode* findnextp(ListNode* p); //找到x前一个结点，若x为头节点，返回nullptr
    ListNode* findindex(int index);

    void insert_head(int x);
    void insert_tail(int x);
    void deletex(int x);
    void deletelist();
};

ListNode *Ablist::findx(int x)
{
    ListNode* p = head;
    while(p != nullptr)
    {
        if(p->data == x)
        return p;
        p = p->next;
    }
    return nullptr;
}

ListNode *Ablist::findnextp(ListNode *p)
{
    ListNode* q = head;
    if(q == p)
    {
        return nullptr;
    }
    while (q->next != p)
    {
        q = q->next;
    }
    return q;
}

void Ablist::deletex(int x)
{
    ListNode*p = findx(x);
    if(p)
    {
        ListNode *q = findnextp(p);
        if(q)
        {
            q->next = p->next;
            delete p;
            size--;
        }
        else
        {
            q = head->next;
            delete head;
            head = q;
            size--;
        }
    }
}

void Ablist::deletelist()
{
    ListNode* p = head;
    if(head != nullptr)
    {
        while(head->next != nullptr)
        {
            while(p->next->next != nullptr)
            {
                p = p->next;
            }
            ListNode* q = p->next;
            delete q;
            p->next = nullptr;
            p = head;
        }
        delete p;
        head = nullptr;
    }
    size = 0;
}

void Ablist::insert_head(int x)
{
    if(head)
    {
        ListNode* p = new ListNode;
        p->data = x;
        p->next = head;
        head = p;
        size++;
    }
    else
    {
        ListNode* p = new ListNode;
        p->data = x;
        p->next = nullptr;
        head = p;
        size++;
    }
}

ListNode *Ablist::findindex(int index)
{
    if(index > size - 1||index < 0)
    {    
        return nullptr;
    }
    else
    {
        ListNode* p = head;
        while(index > 0)
        {
            p = p->next;
            index--;
        } 
        return p;
    }
}

void Ablist::insert_tail(int x)
{
    if(size > 0)
    {
        ListNode* p = findindex(size - 1);
        p->next = new ListNode;
        p->next->data = x;
        p->next->next = nullptr;
        size++;
    }
    else
    {
        head = new ListNode;
        head->data = x;
        head->next = nullptr;
        size++;
    }
}
