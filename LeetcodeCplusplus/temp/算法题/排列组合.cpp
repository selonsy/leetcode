/*
1、求一个字符串的全排列。
如：123的全排列为：123，132，231，213，321，312等六种。
2、求A(M,N)。（M为全集，N为选定集，排列问题）
3、求C(M,N)。（M为全集，N为选定集，组合问题）
*/

/*
1、全排列就是指n个元素随机组合，不重复的所有排列方式，常见的算法实现分为 递归 和 非递归 ，
这里我们用一个例子来辅助说明。{1，2，3，4}
》递归：递归是一种优雅的思想，层层推进。首先，我们知道要实现1，2，3，4的全排列，每个数都会在第1个位置出现，
那我们先固定第1位是1，而后我们要做的就是对后面的3位子序列进行全排列，这时固定子序列的第一位为2。 
依此类推，直到子序列只剩1位，返回。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//打印数组全部元素
void prt(int arr[], int end)
{
    for (int i = 0; i <= end; ++i)
    {
        printf("%d", arr[i]);
    }
}

void perm(int arr[], int begin, int end)
{
    /**
     * 对arr数组中的begin~end进行全排列
     * 
     * 比如：
     *     arr = {1,2,3}
     *  第一步：执行 perm({1,2,3},0,2),begin=0,end=2;
     *      j=0,因此执行perm({1,2,3},1,2),begin=1,end=2;
     *          j=1,swap(arr,0,0)-->arr={1,2,3},  perm({1,2,3},2,2),begin=2,end=2;
     *               因为begin==end，因此输出数组{1,2,3}
     *           swap(arr,1,1) --> arr={1,2,3};
     *           j=2,swap(arr,1,2)-->arr={1,3,2},  perm({1,3,2},2,2),begin=2,end=2;
     *               因为begin==end，因此输出数组{1,3,2}
     *           swap(arr,2,1) --> arr={1,2,3};
     *       j=1,swap(arr,0,1) --> arr={2,1,3},      perm({2,1,3},1,2),begin=1,end=2;
     *           j=1,swap(arr,1,1)-->arr={2,1,3}   perm({2,1,3},2,2),begin=2,end=2;
     *               因为begin==end，因此输出数组{2,1,3}
     *           swap(arr,1,1)--> arr={2,1,3};
     *           j=2,swap(arr,1,2)后 arr={2,3,1},并执行perm({2,3,1},2,2),begin=2,end=2;
     *               因为begin==end，因此输出数组{2,3,1}
     *           swap(arr,2,1) --> arr={2,1,3};
     *       swap(arr,1,0)  --> arr={1,2,3}
     *       j=2,swap(arr,2,0) --> arr={3,2,1},执行perm({3,2,1},1,2),begin=1,end=2;
     *           j=1,swap(arr,1,1) --> arr={3,2,1} , perm({3,2,1},2,2),begin=2,end=2;
     *               因为begin==end，因此输出数组{3,2,1}
     *           swap(arr,1,1) --> arr={3,2,1};
     *           j=2,swap(arr,2,1) --> arr={3,1,2},并执行perm({2,3,1},2,2),begin=2,end=2;
     *               因为begin==end，因此输出数组{3,1,2}
     *           swap(arr,2,1) --> arr={3,2,1};
     *       swap(arr,0,2) --> arr={1,2,3}
     *       
     */
    if (begin == end) //一到递归的出口就输出数组，此数组为全排列
    {
        prt(arr, end);
        printf("\n");
        return;
    }
    for (int i = begin; i <= end; ++i)
    {                              //for循环将begin~end中的每个数放到begin位置中去
        swap(arr[begin], arr[i]);  //交换两个元素值
        perm(arr, begin + 1, end); //假设begin位置确定，那么对begin+1~end中的数继续递归
        swap(arr[begin], arr[i]);  //换过去后再还原
    }
}
/*
非递归的实现：这里采用的是字典序的方式生成全排列，1，2，3，4这4个数，组成形如1234，1243等序列，
这些序列中1234最小，4321最大，由此我们从1234开始（或者4321也行），寻找第一个比1234大的序列，是1243；
再寻找第一个比1243大的序列，是1324........依此类推，求出所有序列。

具体实现：从右向左开始，找到第一个这样的数A(n-1)<A(n),从A(n)向右找最后一个比A(n-1)大的数A(m)，
交换A(n-1)和A(m)，将A(n)到末尾所有元素逆序。重复上述步骤直到第一个元素。
*/
void perm_1(int arr[], int len)
{
    if (len < 2)
        return;
    int i, j, temp;
    do
    {
        //输出当前序列
        prt(arr, len - 1);
        printf("\n");
        i = j = len - 1;
        //向前查找第一个变小的元素
        while (i > 0 && arr[i] < arr[i - 1])
            --i;
        temp = i;
        if (i == 0)
            break;
        //先后查找第一个比arr[i-1]大的元素
        while (temp + 1 < len && arr[temp + 1] > arr[i - 1])
            ++temp;
        swap(arr[i - 1], arr[temp]); //交换两个值
        reverse(arr + i, arr + len); //逆序
    } while (true);
}

template <typename T>
void combine_inner(T &data, int start, int n, int m, int depth, T temp, vector<T> &result)
{
    if (depth == m - 1)
    {
        //最内层循环 将temp加入result
        for (int i = start; i < n - (m - depth - 1); ++i)
        {
            temp[depth] = data[i];
            result.push_back(temp);
        }
    }
    else
        for (int i = start; i < n - (m - depth - 1); ++i)
        {
            temp[depth] = data[i]; //每层输出一个元素
            combine_inner(data, i + 1, n, m, depth + 1, temp, result);
        }
}

//T可以调入vector<int>, string等，需要支持下标[]操作及size()函数
template <typename T>
vector<T> combine(T &data, int m)
{
    if (m <= 0)
        return {};
    int depth = 0;
    vector<T> result;
    T temp(m, 0);
    combine_inner(data, 0, data.size(), m, depth, temp, result);
    return result;
}

int main()
{
    int arr[3] = {1, 2, 3};
    perm(arr, 0, 2);

    //STL里面自带的排列函数
    int arr1[] = {3, 2, 1};
    //prev_permutation:数组需要按照降序排列
    cout << "用prev_permutation对3 2 1的全排列" << endl; // 默认比较是less，即arr1如果是1，2，3，则只有一个值
    do                                                   // 采用do-while是因为全排列至少有一次
    {
        cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << '\n';
    } while (prev_permutation(arr1, arr1 + 3)); ///获取上一个较大字典序排列，如果3改为2，只对前两个数全排列

    int arr2[] = {1, 2, 3};
    //next_permutation:数组需要按照升序排列
    cout << "用next_permutation对1 2 3的全排列" << endl;
    do
    {
        cout << arr2[0] << ' ' << arr2[1] << ' ' << arr2[2] << '\n';
    } while (next_permutation(arr2, arr2 + 3)); ///获取下一个较大字典序排列，如果3改为2，只对前两个数全排列
    ///注意数组顺序，必要时要对数组先进行排序

    //组合
    //例如C(n, m)，在m较小时可以手写循环，以C(5, 3) 为例：
    vector<int> A{1, 2, 3, 4, 5};
    for (int i = 0; i < A.size() - 2; ++i)
        for (int j = i + 1; j < A.size() - 1; ++j)
            for (int k = j + 1; k < A.size(); ++k)
            {
                cout << A[i] << A[j] << A[k] << endl;
            }
    //或者使用自定义的组合函数
    string s("ABCDEF");
    vector<string> result = combine(s, 3);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    cout << "共计 " << result.size() << " 种！" << endl;
}