#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double

// 数据结构


// 树状数组(标准): 区间和
// 注意: 相关数组从1计数! 数组类型通过模板DataType给入.
// 警告: 清空树状数组(惰性)未经过测试. 代码测试不完善.
// 已通过题目: LibreOJ-130.
template <class DataType>
class BinaryIndexedTree
{
    DataType *t; //树状数组
    int *tag;    //优化多组输入:t的上次使用时间
    int Tag;     //优化多组输入:记录当前组数, 从1计数
    int N;       //数组元素个数

private:
    int lowbit(int x); //找到x最低位1对应的数;
public:
    BinaryIndexedTree(int MAX_SIZE); //构造容量MAX_SIZE的标准树状数组, O(MAX_SIZE);
    ~BinaryIndexedTree();
    void add(int pos, DataType val);    //第pos位置增加k, O(log(N));
    void update(int pos, DataType val); //第pos位置变为k, O(log(N));
    void reset(int N);                  //清空树状数组(惰性), 相当于用全0数组初始化, O(1);
    DataType getsum(int k);             //计算前k项和:A[1..k], O(log(N));
    DataType getsum(int l, int r);      //计算l到r项的和:A[l..r], O(log(N));
    LL getsumLL(int k);                 //计算前k项和:A[1..k], O(log(N)), 强制返回long long;
    LL getsumLL(int l, int r);          //计算l到r项的和:A[l..r], O(log(N)), 强制返回long long;
    void init(DataType *A, int N);      //从A[1..N]初始化, O(N), 会调用reset.
};

template <class DataType>
BinaryIndexedTree<DataType>::BinaryIndexedTree(int MAX_SIZE)
{
    this->t = new DataType[MAX_SIZE];
    this->tag = new int[MAX_SIZE];
    this->Tag = 0;
    this->N = 0;
}
template <class DataType>
BinaryIndexedTree<DataType>::~BinaryIndexedTree()
{
    delete[] this->t;
    delete[] this->tag;
}
template <class DataType>
void BinaryIndexedTree<DataType>::init(DataType *A, int N)
{
    reset(N);
    for (int i = 1; i <= N; ++i)
    {
        if (this->tag[i] != this->Tag)
            this->t[i] = 0;
        this->t[i] += A[i], this->tag[i] = this->Tag;
        int j = i + lowbit(i);
        if (j <= N)
        {
            if (this->tag[j] != this->Tag)
                this->t[j] = 0;
            this->t[j] += this->t[i], this->tag[j] = this->Tag;
        }
    }
}
template <class DataType>
int BinaryIndexedTree<DataType>::lowbit(int x)
{
    return x & -x;
}
template <class DataType>
void BinaryIndexedTree<DataType>::reset(int N)
{
    ++this->Tag;
    this->N = N;
};
template <class DataType>
void BinaryIndexedTree<DataType>::add(int pos, DataType val)
{
    while (pos <= this->N)
    {
        if (this->tag[pos] != this->Tag)
            this->t[pos] = 0;
        this->t[pos] += val, this->tag[pos] = this->Tag;
        pos += lowbit(pos);
    }
}
template <class DataType>
DataType BinaryIndexedTree<DataType>::getsum(int k)
{
    DataType ret = (DataType)0;
    while (k)
    {
        if (this->tag[k] == this->Tag)
            ret += this->t[k];
        k -= lowbit(k);
    }
    return ret;
}
template <class DataType>
DataType BinaryIndexedTree<DataType>::getsum(int l, int r)
{
    return getsum(r) - getsum(l - 1);
}
template <class DataType>
LL BinaryIndexedTree<DataType>::getsumLL(int k)
{
    LL ret = 0LL;
    while (k)
    {
        if (this->tag[k] == this->Tag)
            ret += this->t[k];
        k -= lowbit(k);
    }
    return ret;
}
template <class DataType>
LL BinaryIndexedTree<DataType>::getsumLL(int l, int r)
{
    return getsumLL(r) - getsumLL(l - 1);
}
template <class DataType>
void BinaryIndexedTree<DataType>::update(int pos, DataType val)
{
    add(pos, val - getsum(pos, pos));
}


