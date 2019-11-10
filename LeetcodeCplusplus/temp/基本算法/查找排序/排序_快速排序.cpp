#include <iostream>
#include <vector>
using namespace std;

/*
思想：分治法。
1、从数列中取出一个数作为基准数（枢轴，pivot）。 
2、将数组进行划分(partition)，将比基准数大的元素都移至枢轴右边，将小于等于基准数的元素都移至枢轴左边。
3、再对左右的子区间重复第二步的划分操作，直至每个子区间只有一个元素。

不稳定，时间复杂度在最坏情况下是O(N2)，平均的时间复杂度是O(N*lgN)。

*/
void quicksort(vector<int> &data, int left, int right)
{
    if (left >= right)
        return;
    int pivot = (left + right) / 2; // 支点选择，一般以第一个元素，中间元素，或者最后一个元素为基准。
    vector<int> less;
    vector<int> greater;
    int tmp;
    for (int i = left; i < right; i++)
    {
        if (i == pivot)
            tmp = data[pivot];
        else if (data[i] < data[pivot])
            less.push_back(data[i]);
        else
            greater.push_back(data[i]);
    }
    for (int i = left; i < right; i++)
    {
        if (i < left + less.size())
            data[i] = less[less.size() - i - 1 + left];
        else if (i == left + less.size())
            data[i] = tmp, pivot = i;
        else
            data[i] = greater[greater.size() - i + less.size() + left];
    }
    quicksort(data, left, pivot);
    quicksort(data, pivot + 1, right);
}

int main()
{

    vector<int> array = {3, 4, 5, 7, 8, 2, 1, 9, 0, 6};
    int left = 0, right = array.size();

    quicksort(array, left, right);

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}