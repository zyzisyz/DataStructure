/**********************************
* filename: sumI
* author: Yang Zhang
* e-mail: zyziszy@foxmail.com
* time: 2018-10-15
***********************************/

#include <iostream>
using namespace std;

//计算给定n个整数的总和
//时间复杂度为O(n)
int sumI(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];
    return sum;
}

//test function
int main(void)
{
    int A[] = {1, 2, 3, 4, 5};
    cout << "Sum:" << sumI(A, 5) << endl;

    //for windows test
    system("pause");
    return 0;
}
