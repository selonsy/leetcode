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
using namespace std;
/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
bool process(char *message) {
    string s;
    s = message;
    int len = s.size();
//    int len = strlen(message);
//    char c[1024];
//    for (int i = 0; i < len; ++i) {
//        c[i] = message[i];
//    }
//    int _t = unique(c, c + len) - c;
    vector<char> vec;
    bool b[1030] = {0};
//    for (int j = 1025; j <=1029 ; ++j) {
//        b[j] =
//    }
    for (int i = 0; i < len; i++) {
        if (b[s[i] - 'A'] == 0) {
            vec.push_back(s[i]);
            b[s[i] - 'A'] = 1;//重复字符-'a'总是等于相同值，故重复字符对应的布尔值都为1；
        }
        else if(b[1025]==0) //$%^&*
        {
            vec.push_back(s[i]);
            b[1025]==1;
        }else if(b[1026]==0){
            vec.push_back(s[i]);
            b[1026]==1;
        }else if(b[1027]==0){
            vec.push_back(s[i]);
            b[1027]==1;
        }else if(b[1028]==0){
            vec.push_back(s[i]);
            b[1028]==1;
        }else if(b[1029]==0){
            vec.push_back(s[i]);
            b[1029]==1;
        }
    }
    int a_len = vec.size();
    if (a_len <= 20) {
        cout<<pow(2,a_len)<<" "<<1;
    }
    else
    {

    }
    return true;
}

int main() {
    bool res;

    vector<int> vec;

    char _message[2048];
    while(fgets(_message, 2048, stdin)) {
        res = process(_message);
    }

//    char s[6] = "YYAB^";
//    process(s);
    return 0;

}