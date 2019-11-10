#include <iostream>
using namespace std;

int SequenceSearch(int a[], int value, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == value)
            return i;
    return -1;
}
int main()
{
    int a[10] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int i = SequenceSearch(a, 10, 10);
    cout << "index:" << i << " value:" << a[i] << endl;
}