#include<iostream>
#include<string>

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
    ~Abstack();
    bool push(int m);
    ListNode* pop();
    void clear();
    bool isEmpty();
    void printStack();
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

int main()
{
    Abstack s(20);
    Abqueue q(20);
    int n;
    bool test = true;
    cin >> n;


    int c;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        q.push(c);
    }


    for(int i = 0; i < n; i++)
    {
        cin >> c;
        ListNode* p = q.pop();
        while (p->data != c)
        {
            s.push(p->data);
            delete p;
            p = q.pop();
        }
        delete p;
        while (!s.isEmpty())
        {
            ListNode* temp = s.pop();
            cin >> c;
            i++;
            if(temp->data != c)
            {
                test = false;
            }
            delete temp;
        }
        
    }


    if(test)
        cout << "The pop order is possible." << endl;
    else
        cout << "The pop order is impossible." << endl;
    return 0;
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

void Abstack::printStack()
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
