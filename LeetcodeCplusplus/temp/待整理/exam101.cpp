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
using namespace std;

/**
 * Welcome to vivo !
 */
 
int solution(string str)
{
	int sum = 0;
    if(str.length()<=0)return 0;
    stack<char> sc;
    char pre,cur;
    pre = str[0];
    if(pre=='0' && str.length()==1)return 0;
    sc.push(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        cur = str[i];
        if(cur=='0')break;
        if(pre=='(' && cur==')'){
            sc.pop();
        }
        else {
            sc.push(cur);
        }
        /* code */
    }
    return sc.size();
}

int main()
{
	string str("");
	getline(cin, str);

	int sum = solution(str);
	cout << sum << endl;
	return 0;
}