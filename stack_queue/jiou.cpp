#include<iostream>
#include<string>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
};

class Abqueue
{
public:
    int size;
    int capacity;
    ListNode* head;
    ListNode* tail;


    Abqueue();
    Abqueue(int cap);
    bool push(int value);
    ListNode* pop();
    void printQueue();
    

};
Abqueue::Abqueue()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    capacity = 10; 
}

Abqueue::Abqueue(int cap)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    capacity = cap;
}

bool Abqueue::push(int value)
{
    if (size == capacity)
    {
        return false;
    }

    ListNode* newNode = new ListNode();
    newNode->data = value;
    newNode->next = nullptr;

    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    size++;
    return true;
}

ListNode* Abqueue::pop()
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode* temp = head;
    head = head->next;
    size--;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    return temp;
}

void Abqueue::printQueue()
{
    ListNode* current = pop();
    while (current != nullptr)
    {
        cout << current->data << " ";
        delete current;
        current = pop();
    }
    cout << endl;
}

int main()
{    
    int n;
    cin >> n;
    Abqueue q1(n);
    Abqueue q2(n);
    int c;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        if(c % 2 == 0)
            q2.push(c);//偶数入队列2
        else
            q1.push(c);//奇数入队列1
    }
    ListNode* temp1 = q1.pop();
    ListNode* temp2 = q2.pop();
    while(temp1 != nullptr && temp2 != nullptr)
    {
        cout << temp1->data << " " << temp2->data << endl;
        delete temp1;
        delete temp2;
        temp1 = q1.pop();
        temp2 = q2.pop();
    }
    return 0;
}