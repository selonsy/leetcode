//
// Created by devin on 2019-05-30.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<list>
#include<functional>
#include<map>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    // 网易模拟题 2019-08-04 19:00 150min
    // 1、个税缴纳
    void wy_moni_001_test() {}

    void wy_moni_001() {}

    // 2、字符串替换
    /*
    // 2、作为一名优秀的研发工程师，小Q经常在业余时间尝试优化游戏客户端和服务端的通信中，某些数据类型的传输性能。今天小Q尝试
    // 优化的是全由大写字母组成的字符串，他决定对字符串按照如下规则进行缩写：
    // 如果有连续的 M(M>4) 按字典递增顺序相邻的大写字母，则缩写为“首个字母-结束字母”的形式，譬如:
    // XYZABCDMMMGHIJKLRST 缩写为 XYZA-DMMMG-LRST
    // 输入描述：
    // 每个输入数据包含多个测试点。
    // 第一行为测试点的个数T(T <= 100)。
    // 每个测试点包含一行非空字符串，表示缩写前的字符串，字符串全由大写字母组成，字符串的长度不超过50000。
    // 输出描述：
    // 对于每个测试点，输出一行，表示缩写后的结果。
    // 示例：
    // 输入：
    //    3
    //    DCBA
    //    ZABCDEFGX
    //    XYZABCDMMMGHIJKLRST
    // 输出：
    //    DCBA
    //    ZA-GX
    //    XYZA-DMMMG-LRST
     */
    void wy_moni_002_test() {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i) {
            string c1;
//            getline(cin, c1);
            cin >> c1;
            string c2 = wy_moni_002(c1);
            //cout << c2 << endl;
            arr[i] = c2;
        }
        for (int j = 0; j < n; ++j) {
            cout << arr[j] << endl;
        }
    }

    string wy_moni_002(string str) {
        if (str.size() < 4)return str;
        // 暴力
        int count = 1;
        map<int, int> lmap;
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] - str[i - 1] != 1) {
                if (count >= 4) {
                    int tail = i - 1;
                    int first = i - count;
                    lmap.insert(pair<int, int>(first, tail));
                }
                count = 1;
            } else count++;
        }
        map<int, int>::iterator iter;
        for (iter = lmap.begin(); iter != lmap.end(); iter++) {
            str.replace(iter->first + 1, iter->second - 2, "-");
        }
        return str;
    }

    // 3、进制组合
    /*
     题目：
        小A在一个程序的输出中犯了错误，由于忘记输出空格，他把一个正整数N的X进制和Y进制表示连在了一起输出，
        得到了一个无法识别的数字。请你帮他恢复这个正整数N。
     输入描述：
        输入的第一行是一个正整数T（0 < T <= 100），表示有T个样例。对于每个样例，输入为X, Y, Z，其中X和Y为进制（2 <= X, Y <= 16），
        Z是一个字符串，长度不超过62，表示正整数N（0< N < 2^31 – 1）的X进制和Y进制连在一起的形式，10到15分别用大写A到F表示。
        数据保证一定有一个唯一解。
     数据范围：
        对于30%的数据，N小于等于100；
        对于70%的数据，N小于等于10000；
        对于100%的数据，N小于2^31-1；
     输出描述：对于每个样例，输出这个数字的10进制表示。
     示例：
        输入：
        3
        5 2 113221101000101
        13 7 1016
        4 12 2222248A
        输出：
        837
        13
        682
     */
    void wy_moni_003_test() {}

    void wy_moni_003() {}
};

int main() {
    Solution s;
//    s.wy_moni_001_test();
//    s.wy_moni_002_test();
//    s.wy_moni_003_test();
    return 0;
}
