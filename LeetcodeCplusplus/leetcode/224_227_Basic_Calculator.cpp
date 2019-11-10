#include <iostream>
#include <stack>
#include <map>
#include <sstream>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        //求后缀表达式
        string postOrder;
        stack<char> symbol;
        map<char, int> priority = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
        };
        for (int i = 0; i < (int)s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (isdigit(s[i]))
            {
                postOrder += s[i];
                while (i < s.length() - 1 && isdigit(s[i + 1]))
                {
                    postOrder += s[++i];
                }
            }
            else if (symbol.empty() || s[i] == '(' || (priority[s[i]] > priority[symbol.top()] && s[i] != ')'))
            {
                symbol.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!symbol.empty() && symbol.top() != '(')
                {
                    postOrder += symbol.top();
                    symbol.pop();
                    postOrder += " ";
                }
                symbol.pop();
            }
            else
            {
                while (!symbol.empty() && priority[s[i]] <= priority[symbol.top()])
                {
                    postOrder += symbol.top();
                    symbol.pop();
                    postOrder += " ";
                }
                symbol.push(s[i]);
            }
            if (!postOrder.empty() && postOrder.back() != ' ')
            {
                postOrder += " ";
            }
        }
        while (!symbol.empty())
        {
            postOrder += symbol.top();
            symbol.pop();
            postOrder += " ";
        }
        //利用后缀表达式来求值
        istringstream iss(postOrder);
        stack<double> st;
        int num = 0;
        char c = '\0';
        while (iss.peek() != EOF)
        {
            if (isdigit(iss.peek()))
            {
                iss >> num;
                st.push(num);
                iss.ignore();
            }
            else
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                iss >> c;
                switch (c)
                {
                case '+':
                    st.push(num2 + num1);
                    break;
                case '-':
                    st.push(num2 - num1);
                    break;
                case '*':
                    st.push(num2 * num1);
                    break;
                case '/':
                    st.push(double(num2) / double(num1));
                    break;
                }
                iss.ignore();
            }
        }
        return st.top();
    }
};

int main()
{
    Solution s;
    string str = "3+2-5*0";
    int res = s.calculate(str);
    cout << res << endl;
    return 0;
}