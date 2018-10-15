/**********************************
* filename: countOnes
* author: Yang Zhang
* e-mail: zyziszy@foxmail.com
* time: 2018-10-15
***********************************/

#include <iostream>
using namespace std;

//统计二进制展开数里位数为1的总数

//时间复杂度为O(logn)
int countOnes(unsigned int n) //unsigned 是无符号数
{
    int ones = 0;
    while (0 < n) //在n小于0时候
    {
        ones += (1 & n); //检查最低位，如果最低为为1则ones加一
        n >>= 1;         //n 右移一位
    }
    return ones;
}

//test function
int main(void)
{
    unsigned int n = 5;
    cout << "数字" << n << "的二进制中1的个数是：" << countOnes(n) << endl;

    //for windows test
    system("pause");
    return 0;
}
