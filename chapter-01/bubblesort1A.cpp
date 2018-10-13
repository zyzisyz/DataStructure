/**********************************
* filename: bubblosort1A
* author: Yang Zhang
* e-mail: zyziszy@foxmail.com
* time: 2018-10-11
***********************************/

#include <iostream>
using namespace std;


//起泡排序算法C++实现，从小到大
void bubblosort1A(int A[], int n)
{
    bool sorted = false;                //用于判断是否已经排好序
    while (!sorted)
    {
        sorted = true;
        for (int i = 1; i < n; i++)     //i-1因此从1开始循环
        {
            if (A[i - 1] > A[i])
            {
                swap(A[i], A[i - 1]);   //C++里可以直接用swap函数
                sorted = false;         //如果交换了则sort为false
            }
        }
    }
    n--;                                //最末尾的数必然是最大的
}


//test function
int main(void)
{
    int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Before sort:";
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl
         << "After sort:";
    bubblosort1A(A, 10);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";

    //for windows test
    system("pause");
    return 0;
}
