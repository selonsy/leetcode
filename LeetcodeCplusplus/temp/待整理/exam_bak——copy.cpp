#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<string> myget(string str1, string str2)
{
    vector<vector<int>> result(str1.length(), vector<int>(str2.length()));
    vector<string> results;
    int max_length = 0, max_ending = 0;
    for (int i = 0; i < str1.length(); ++i)
        for (int j = 0; j < str2.length(); ++j)
        {
            if (str1[i] == str2[j])
            {
                if (i == 0 || j == 0)
                {
                    result[i][j] = 1;
                }
                else
                {
                    result[i][j] = result[i - 1][j - 1] + 1;
                }
            }
            else
            {
                result[i][j] = 0;
            }
            if (result[i][j] > max_length)
            {
                max_length = result[i][j];
                max_ending = i;
                string t = str1.substr(max_ending - max_length + 1, max_length);
                results.push_back(t);
            }
        }
    set<string> a;
    int maxl = 0;
    for (long i = 0; i < results.size(); i++)
    {
        if (results[i].size() > maxl)
        {
            maxl = results[i].size();
            a.clear();
            a.insert(results[i]);
        }
        else if (results[i].size() > maxl)
        {
            a.insert(results[i]);
        }
    }
    return a;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    set<string> s = myget(s1, s2);
    for (set<string>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i << endl;
    }
    return 0;
}
