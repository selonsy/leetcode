#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <iomanip>
#include <bitset>
using namespace std;
/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 

******************************开始写代码******************************/
// 字符串分割
vector<string> split(const string &str, const string &delim)
{
    vector<string> res;
    if ("" == str)
        return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p)
    {
        string s = p;     //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}
bool CheckBlackList(string userIP, string blackIP)
{
    bool res = false;
    if (userIP == blackIP)
        res = true;
    else
    {
        vector<string> vs = split(blackIP, "/");
        if (vs.size() == 2)
        {
            int n = 0;
            string sss = vs[0];
            int mask = atoi(vs[1].c_str());
            vector<string> s1 = split(userIP, ".");
            vector<string> s2 = split(sss, ".");
            for (int i = 0; i < 4; i++)
            {
                bitset<8> bitset1(atoi(s1[i].c_str()));
                bitset<8> bitset2(atoi(s2[i].c_str()));
                bitset<8> test(atoi(s2[1].c_str()));
                if (n >= mask)
                {
                    res = true;
                    break;
                }
                if (bitset1 == bitset2)
                {
                    n += 8;
                }
                else
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (bitset1[j] == bitset2[j])
                        {
                            n += 1;
                        }
                    }
                }
            }
        }
    }

    return res;
}
/******************************结束写代码******************************/

int main()
{
    bool res;

    string _userIP;
    getline(cin, _userIP);
    string _blackIP;
    getline(cin, _blackIP);

    res = CheckBlackList(_userIP, _blackIP);
    cout << res << endl;

    return 0;
}