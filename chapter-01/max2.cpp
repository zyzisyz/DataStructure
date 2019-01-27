/**********************************
* filename: max2
* author: Yang Zhang
* e-mail: zyziszy@foxmail.com
* time: 2018-10-11
***********************************/

// 递归+分治
//找出数组在区间[lo,hi)中最大的两个数字A[x1]和A[x2]

#include <iostream>
using namespace std;

void max2(int A[], int lo, int hi, int &x1, int &x2)
{
    //对于只有两个元素的情形
    if (lo + 2 == hi)
    {
    }
    //对于只有3个元素的情况
    if (lo + 3 == hi)
    {
    }
    int mi = (lo + hi) / 2;

    //分治左边
    int x1L, x2L;
    max2(A, lo, mi, x1L, x2L);
    //分治右边
    int x1R, x2R;
    max2(A, mi, hi, x1R, x2R);
}

//test
int main(void)
{
    A[10] = [ 1000, 0, 0, 0, 0, 0, 1, 0, 0, 9999 ];
    int x1,x2;
    
}