#pragma once

#include<iostream>
#include<string>
class ListNode
{
public:
    std::string ID;
    std::string Password;

    std::string name;
    int phonenum;
    std::string email;
    std::string IDcard;
    int bankcard;
    double money;
    ListNode *next;
    ListNode();//nextIDPasswordnamephonenumemailIDcardbankcardmoney
    ListNode(std::string ID1,std::string Password1,std::string name1,int phonenum1,std::string email1,std::string IDcard1,int bankcard1,double money1);//nextIDPasswordnamephonenumemailIDcardbankcardmoney
};
class Ablist
{
private:    
    ListNode *head;
    int length;
    
    ListNode* Geti(int i);
    void deletelist();
public:
    Ablist();
    Ablist(ListNode *head1,int length1);
    ~Ablist();
    ListNode* Gethead();
    void Setlist();// 
    void Insert_head(); //std::string ID1 = "",std::string Password1 = "",std::string name1 = "",int phonenum1 = 0,std::string email1 = "",std::string IDcard1 = "",int bankcard1 = 0,double money1 = 0
    void Insert_i(int i);
    void Insert_tail();
    ListNode* Getin(std::string ID1 ,std::string Password1);
};
