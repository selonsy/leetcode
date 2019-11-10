#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
string resolve(string expr)
{
    vector<string> v;
    int kuohao = 0;
    for (int i = 0; i < expr.size(); i++)
    {
        if (expr[i] == '(')
        {
            kuohao++;
            if (kuohao >= 2)
            {
                string temp;
                i++;
                while (expr[i] != ')' && i < expr.size())
                {
                    temp.push_back(expr[i]);
                    i++;
                }
                kuohao--;
                v.push_back(temp);
            }
        }
        else if (expr[i] == ')')
        {
            kuohao--;
            if (kuohao < 0)
                break;
        }
        else if (kuohao >= 0)
        {

            string temp;
            temp.push_back(expr[i]);
            v.push_back(temp);
        }
    }
    string ret;

    if (kuohao == 0)
    {
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ret = ret + v[i];
        }
    }
    return ret;
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
