/**********************************
* filename: vector.cpp
* author: Yang Zhang
* e-mail: zyziszy@foxmail.com
* create-time: 2018-10-17
* last-modified-time: 
***********************************/

typedef int Rank;             //秩
#define DEFAULT_CAPACITY = 3; //默认的初始模板

template <typename T>
class Vector
{
protected:
    Rank _size;    //规模
    int _capacity; //容量
    T *elem;       //数据区

    void copyFrom(T const *A, Rank lo, Rank hi); //复制数组区间A[lo, hi]
    void expand();                               //空间拓展不足时扩容
    void shrink();                               //装填因子过小时压缩
    void bubble(Rank lo, Rank hi);               //扫描交换
    void bubbleSort(Rank lo, Rank hi);           //起泡排序
    void max(Rank lo, Rank hi);                  //选取最大元素
    void selectionSort(Rank lo, Rank hi);        //选择排序算法
    void merge(Rank lo, Rank mi, Rank hi);       //归并算法
    void mergeSort(Rank lo, Rank hi);            //归并排序算法
    Rank partition(Rank lo, Rank hi);            //轴点构造法
    void quickSort(Rank lo, Rank hi);            //快速排序法
    void megeSort(Rank lo, Rank hi);             //归并排序
    void heapSort(Rank lo, Rank hi);             //堆排序
public:

};

