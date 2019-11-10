#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <stack>
#include <algorithm>
using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void myreverse(stack<char> &s)
{
    stack<char> ss;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        ss.push(s.top());
        s.pop();
    }
    s = ss;
}
string resolve(string expr)
{
    string res;
    stack<char> symbol;
    stack<char> kuohao;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(')
        {
            kuohao.push(expr[i]);
        }
        else if (expr[i] != '(' && expr[i] != ')')
        {
            symbol.push(expr[i]);
        }
        else if (expr[i] == ')')
        {
            myreverse(symbol);
            kuohao.pop();
        }
    }
    int len = symbol.size();
    for (int j = 0; j < len; j++)
    {
        res.push_back(symbol.top());
        symbol.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
/******************************结束写代码******************************/

int main()
{
    string res;

    string _expr;
    getline(cin, _expr);

    res = resolve(_expr);
    cout << res << endl;

    return 0;
}
