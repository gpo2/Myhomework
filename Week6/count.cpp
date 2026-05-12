#include<iostream>
#include<string>
using namespace std;

template<class T>
int count(T* arr,T target,int n)
{
    int count = 0;
    for(int i = 0;i < n;i++)
    {
        if(*(arr + i) == target)
        count++;
    }
    return count;
}

int main()
{
    int choice,n;
    cin >> choice >> n;
    switch (choice)
    {
    case 1:
        {
            int arr[n],target;
            for(int i = 0;i < n;i++)
            {
                cin >> arr[i];
            }
            cin >> target;
            cout << count(arr,target,n) << endl;
            break;
        }
    case 2:
    {
        float arr[n],target;
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        cin >> target;
        cout << count(arr,target,n) << endl;
        break;
    }
    case 3:
    {
        double arr[n],target;
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        cin >> target;
        cout << count(arr,target,n) << endl;
        break;
    }
    case 4:
    {
        string arr[n],target;
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        cin >> target;
        cout << count(arr,target,n) << endl;
        break;
    }
    default:
        break;
    }
    return 0;
}
/*
设计一个函数模板 count，用于统计给定元素在数组中的出现次数，
该函数需要能够处理如下数据类型的数组：int、float、double、string。返回目标元素在数组中出现的次数。

 输入格式：

第一行：输入数据类型，1表示int、2表示float、3表示double、4表示string。

第二行：输入数组中包含的元素的个数。

第三行：输入数组中每一个元素的值，用空格分隔。

第四行：输入要统计的元素值。

输出格式：

第一行：目标元素在数组中出现的次数。

 

输入输出示例如下：

输入：

1

10

1 2 3 4 3 5 3 6 3 8

3

输出：

4
*/