#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string s1, s2;
unordered_map<string, int> hashs;
int main()
{
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = i; j < s1.length(); j++)
        {
            string t = s1.substr(i, j - i + 1);
            hashs[t] = 1;
        }
    }
    int maxLen = 0;
    vector<string> ans;
    for (int i = 0; i < s2.length(); i++)
    {
        for (int j = i; j < s2.length(); j++)
        {
            string t = s2.substr(i, j - i + 1);
            if (hashs.count(t) == 0 || t.length() < maxLen)
                continue;
            if (t.length() > maxLen)
            {
                maxLen = t.length();
                ans.clear();
                ans.push_back(t);
            }
            else if (t.length() == maxLen)
            {
                ans.push_back(t);
            }
        }
    }
    if (ans.empty())
    {
        cout << "NULL\n";
    }
    else
    {
        for (auto &v : ans)
            cout << v << endl;
    }
    return 0;
}