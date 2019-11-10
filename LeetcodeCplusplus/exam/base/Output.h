#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

#ifndef OUTPUT_H
#define OUTPUT_H

template <class T>
class output
{
public:
    static void o_vector(vector<T> vec);
    static void o_list(list<T> li);
};

template <class T>
void output<T>::o_vector(vector<T> vec)
{
    if (vec.size() == 0)
        cout << "vector is empty" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << " ";
    }
    cout<<endl;
}

template <class T>
void output<T>::o_list(list<T> li)
{
    int len = li.size();
    if (len == 0)
        cout << "list is empty" << endl;
    T data;
    for (int i = 0; i < len; i++)
    {
        data = li.front();
        cout << data;
        if (i != len - 1)
            cout << " ";
        li.pop_front();
    }
    cout<<endl;
}
#endif