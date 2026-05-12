#include<iostream>
#include<vector>

using namespace std;

class Student
{
private:
    string name;
    double grade[100];
    double score[100];
    int coursenum;
public:
    Student() : grade{} , score{},coursenum{}
    {
        
    }
    void Getname(string name1)
    {
        name = name1;
    }
    void Getgrade(int i , double gradei)
    {   
        grade[i] = gradei;
    }
    void Getscore(int i , double scorei)
    {   
        score[i] = scorei;
    }
    void Getcoursrnum(int num)
    {
        coursenum = num;
    }
friend double calgrade(const vector<Student>& vec_stu );
};

double calgrade(const vector<Student>& vec_stu)
{
    double allgrade = 0;
    double sig_gasc = 0;
    double ave_score = 0;
    double ave_cheng = 0;
    double eachstudentscore[2][100] = {0};
    for(int i = 0;i < vec_stu.size();i++)//calculate each student's score,i is student' label
    {
        for(int j = 0;j < vec_stu[i].coursenum;j++)//calculate one student's score,j is the lable of student's class
        {
            allgrade += vec_stu[i].grade[j];
            sig_gasc += vec_stu[i].grade[j] * vec_stu[i].score[j];
        }
        eachstudentscore[0][i] = sig_gasc;
        eachstudentscore[1][i] = allgrade;
        sig_gasc = 0;
        allgrade = 0;
    }
    for(int i = 0;i < vec_stu.size();i++)
    {
        ave_score += eachstudentscore[0][i];
        ave_cheng += eachstudentscore[1][i];
    }
    ave_score /= ave_cheng;
    return ave_score;
}

int main()
{
    vector<Student> vec_stu;
    string name;
    double grade,score;
    int i=0;
    for(cin >> name;name != "no";cin >> name)
    {
        Student stu;
        stu.Getname(name);
        for(cin >>grade;grade != -1;i++,cin >>grade)
        {
            cin >>score;
            stu.Getgrade(i,grade);
            stu.Getscore(i,score);
        }
        stu.Getcoursrnum(i);
        i = 0;
        vec_stu.push_back(stu);
    }
    double allgrade = calgrade(vec_stu);
    cout << allgrade << endl;
    return 0;
}

/*
定义一个学生类，有三个私有成员：名字name、课程学分grade、课程成绩score。
定义一个友元函数，求全班同学的平均加权成绩。
平均加权成绩=每门课的成绩*每门课的学分的乘积的和/所有课程学分的和; 
全班同学人数不超过100名。

输入说明：
    输入若干行。
    每行一个学生的信息：
        第一个输入是学生的名字，
        第二个输入是第一门课程的学分，
        第三个输入是第一门课程的成绩，
        第四个输入是第二门课程的学分，
        第五个输入是第二门课程的成绩，
        以此类推，最后以-1表示该行输入结束。每个学生的课程数不超过100门。最后以 no 表示输入结束。
        eg:
            b 4 90 2 90 -1↵
            a 4 90 2 90 -1↵
            no↵
输出一行，即该全班同学的平均加权成绩。
*/ 