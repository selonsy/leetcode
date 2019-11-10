#include <iostream>
#include <vector>
using namespace std;

// void bubbleSort(int array[], int n)
void bubbleSort(int *array, int n)
{
    // 冒泡排序：从第一个数到最后一个数，相邻的两个数进行比较，大数下沉，小数上浮，这样获得一个最大值；
    // 第二轮中从第一个数到倒数第二个数，两两比较…一共需要比较 n - 1轮。
    // i < n-1 : 控制比较趟次，n-1趟后就有序了，没必要比较n趟。
    // j < n-1-j: 每一趟里面控制比较次数，每一趟都有一个值确定有序，就不需要再比了。
    // 这种方式，简单，但是缺点就是：
    // 加入数组本身就有序，此方式依旧会进行比较，浪费时间。
    int tmp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                // int tmp = array[j];
                // cout<<&tmp<<endl;  地址一样的，系统自动进行优化，不会重复申请新的内存地址，直接复用。
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
}
void bubbleSort2(int *array, int n)
{
    // 简单改进：对于最好的情况，即数组本来就是有序的，再按照上述代码进行遍历，会浪费很多时间。
    // 故在此加入一个标志，如果本轮遍历未发生数据交换，就证明数组已然有序，直接结束循环。
    int tmp, flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}
void bubbleSort3(int *array, int n)
{
    // 进一步改进：我们可以在每一轮排序的最后，记录下最后一次元素交换的位置，那个位置也就是无序数列的边界，再往后就是有序区了。
    // sortBorder就是无序数列的边界。每一轮排序过程中，sortBorder之后的元素就完全不需要比较了，肯定是有序的。
    int tmp, flag;
    int lastExchangeIndex = 0;
    int sortBorder = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < sortBorder; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = 1;
                lastExchangeIndex = j;
            }
        }
        sortBorder = lastExchangeIndex;
        if (!flag)
            break;
    }
}
int main()
{
    int array[] = {3, 4, 5, 7, 8, 2, 1, 9, 0, 6};
    int array1[10] = {3, 4, 5, 7, 8, 2, 1, 9, 0, 6};
    int *array2 = new int[10]{3, 4, 5, 7, 8, 2, 1, 9, 0, 6};
    vector<int> array3 = {3, 4, 5, 7, 8, 2, 1, 9, 0, 6};
    int n = 10;

    bubbleSort3(array2, n);

    for (int i = 0; i < n; i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;
    return 0;
}