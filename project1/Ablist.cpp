#include"Ablist.h"

ListNode::ListNode()
{
    next = NULL;
    ID = "";
    Password = "";
    name = "";
    phonenum = 0;
    email = "";
    IDcard = "";
    bankcard = 0;
    money = 0;    
}

ListNode::ListNode(std::string ID1,std::string Password1,std::string name1,int phonenum1,std::string email1,std::string IDcard1,int bankcard1,double money1)
{
    next = NULL;
    ID = ID1;
    Password = Password1;
    name = name1;
    phonenum = phonenum1;
    email = email1;
    IDcard = IDcard1;
    bankcard = bankcard1;
    money = money1;    
}







Ablist::Ablist()
{
    head = NULL;
    length = 0;
}

Ablist::Ablist(ListNode *head1,int length1)
{
    head = head1;
    length = length1;
}

ListNode* Ablist::Gethead()
{
    return head;
}

void Ablist::Setlist()
{
    head = new ListNode; 
}

ListNode* Ablist::Geti(int i)
{
    if(i < 0)
    {
        std::cout << "Geti : Input Error" << std::endl;
        return NULL;
    }
    ListNode* p = head;
    for(int j = 0;j < i;j++)
    {
        p = p->next;
        if(p == NULL)
        break;
    }
    if(p == NULL)
    {
        std::cout << "没有该成员" << std::endl;
        return NULL;
    }
    else
    return p;
}
void Ablist::Insert_head()
{
    ListNode *p = head->next;
    head->next = new ListNode;
    length++;
}
void Ablist::Insert_i(int i) // head 1 2 3 4 5 6 NULL eg:3 -> 1234567
{
    ListNode* p = Geti(i);
    Geti(i-1)->next = new ListNode;
    Geti(i-1)->next->next = p;
    length++;
}
void Ablist::Insert_tail()
{
    ListNode *p = head;
    for(int i = 0;i < length;i++)
    {
        p = p->next;
    }
    p->next = new ListNode;
    length++;
}

ListNode* Ablist::Getin(std::string ID1 ,std::string Password1)
{
    int te = 0;
    ListNode* p = head;
    for(int i = 0;i < length&&(!te);i++)
    {
        p = p->next;
        if(ID1 == p->ID)
        {
            te = 1;
        }
    }
    if(!te)
    {
        std::cout << "账号错误" << std::endl;
        return NULL;
    }
    else
    {
        if(Password1 != p->Password)
        {
            std::cout << "密码错误" << std::endl;
            return NULL;
        }
        else
        {
            std::cout << "登陆成功" << std::endl;
            return p;
        }
    }
}

void Ablist::deletelist()
{
    ListNode* p = head->next;
    while(length > 0)
    {
        head->next = p->next;
        delete p;
        p = head->next;
        length--;
    }
}

Ablist::~Ablist()
{
    deletelist();
}