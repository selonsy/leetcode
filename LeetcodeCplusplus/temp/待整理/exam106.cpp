#include <iostream>
#include <string>
#include <memory>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int _min = 0x7ffffff;
vector<int> min_steps;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void result(vector<vector<int> > &v, vector<int> steps)
{
    int a1 = 0, a2 = 0;
    int sum = v[a1][a2];
    for (int i = 0; i < steps.size(); i++)
    {
        if (steps[i] == 1)
            a2++;
        else
            a1++;
        sum += v[a1][a2];
    }
    if (sum < _min)
    {
        _min = sum;
        min_steps = steps;
    }
}

void func(vector<vector<int> > &v, vector<int> &steps, int t)
{
    int n = steps.size();
    if (t >= n)
    {
        result(v, steps);
    }
    for (int i = t; i < n; i++)
    {
        swap(steps[i], steps[t]);
        func(v, steps, t + 1);
        swap(steps[i], steps[t]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    vector<int> steps(n + m - 2);
    for (int i = 0; i < m - 1; i++)
        steps[i] = 1; //->
    for (int i = m - 1; i < n + m - 2; i++)
        steps[i] = 0; //
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            v1.push_back(a);
        }
        v.push_back(v1);
    }
    func(v, steps, 0);
    int a1 = 0, a2 = 0;
    cout << a2 << ' ' << a1 << endl;
    for (int i = 0; i < min_steps.size(); i++)
    {
        if (min_steps[i] == 1)
            a2++;
        else
            a1++;
        cout << a2 << ' ' << a1 << endl;
    }
}