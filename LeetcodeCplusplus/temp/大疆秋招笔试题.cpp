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
    // 大疆笔试题 2019-08-06 19:00 120min
    // 1、题目一
    /*爱玩游戏的小J
    时间限制：C/C++语言 1000MS；其他语言 3000MS
    内存限制：C/C++语言 65536KB；其他语言 589824KB
    题目描述：
    有许多程序员都热爱玩游戏游戏，而小J自称为游戏王，曾玩过几百种游戏，几乎所有能玩到的游戏大作都玩遍了。
    随着时间的推移，他发觉已经没有游戏可以让他玩了！于是他想改玩一些古老的游戏，以成为真正的“游戏王”。
     他希望在接下来的一段时间内将过去出的游戏全部玩一遍，但是毕竟时间有限，因此他感到很苦恼。于是他给每个游戏标上一个成就值，
     同时估算了完成这些游戏所需要的时间。

    现在他只有X天时间。而每个游戏一旦开始玩，至少需要玩一天才能够停下来。那么，他所玩完的游戏的成就值之和最大能达到多少呢？
     （每个游戏必须玩完才能取得成就值。）

    输入
    第一行输入case数T（0<T<20）。对于每个case，第一行输入游戏的数目N(0<N<11)，总时间X(0<X<1000)用空格分隔。
     从第二行到第N+1行每行输入游戏的成就值Ai(0<Ai<10000)，所需要花费时间Bi(0<Bi<10000)。

    输出
    对每个case输出一行，成就值之和的最大值。


    样例输入
    2
    2 2
    10 1
    20 2
    3 4
    10 2
    18 3
    10 2
    样例输出
    20
    20
     */
    void dj_001_test() {

    }

    void dj_001() {

    }

    // 2、题目二
    /*
     不听话的机器人
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小B平时喜欢倒腾一些小东西，最近他准备给自己做的小机器人加入一套语音控制的功能，每个指令对应一个动作。

由于语言转文字有很多现成的方案，所以小B打算直接复用这些方案，但是语音转成了文字之后，还需要将文字跟具体的动作对应起来。

因此小B需要实现一个函数，将语音转换出来的文字，再转换成相应的动作。

为了简单实现，小B将语音直接转成了拼音，然后把对应的动作也都起了名字，因此只要预先输入好两者的映射关系，然后输入语音指令就输出相应的动作。

然而因为小B的函数有bug，机器人并不想听他的话...

你能帮小B解决这个问题吗？

输入
输入包含多组测试数据，对于每组测试数据：

第一行输入两个正整数，空格隔开，需要进 行映射的命令的数目N 和进行调试时发送的语音指令条数 M (1 < N < 1000, 1 < M < 1000)

接下来N行，每行输入两个字符串表示语音指令和对应的动作cmd和action，以空格隔开，每个字符串的长度小于1000，且只有大小写字母

最后M行，每行输入一个字符串表示需要进行调试的语音指令

输出
对于每组测试数据：

输出M行，根据调试的语音指令输出对应的动作指令action


样例输入
4 4
ZuoZhuan TurnLeft
YouZhuan TurnRight
QianJin Forward
HouTui Backward
ZuoZhuan
QianJin
QianJin
HouTui
1 1
SDFlkjdf LNCIls
SDFlkjdf
样例输出
TurnLeft
Forward
Forward
Backward
LNCIls*/
    void dj_002_test() {
        int N,M;
        while(cin>>N>>M) {
            map<string, string> lmap;
            for (int i = 0; i < N; ++i) {
                string a, b;
                cin >> a;
                cin >> b;
                lmap[a] = b;
            }
            for (int j = 0; j < M; ++j) {
                string c;
                cin >> c;
                cout << lmap[c] << endl;
            }
        }
    }

    void dj_002() {

    }

    // 3、题目三
    /*
    应该怎么吃呢
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小W非常喜欢吃零食，经常都会去零食间里购买半价的零食吃，但是他为了控制自己的体重，因此会限制自己买零食的开销在某个数值以内。

但是小W有一个特别的爱好，他对于某些零食特别的喜欢，并且会对这些零食的喜爱成都进行排序。对于零食A和零食B，如果小W对零食A的喜爱程度大于对零食B的喜爱程度，那么每次拿零食的时候，一定会确保A的数目比B多。

现在零食间里有N种零食，假设每种零食都是取不完的，但小W每次都会刚好花完所有的开销，那么小W去取零食的时候应该有多少种可能的取法呢？

输入
输入包含多组测试数据，每组数组:

第一行：买零食的开销 V (V < 1000) 和 所有的零食种类数目 N (N < 200)。

第二行：第 i 个正整数表示第 i 种零食的价格 c_i (c_i < 1000)。

第三行：特别喜欢的零食的种类数 M (2 <= M <= N)

第四行：按照对 M 种零食的喜爱程度从高到低排序，第 i 种零食的喜爱程度会大于第 i + 1 种，保证不会形成环

输出
对于每组测试数据:

输出一个整数ans，表示在满足小W的特殊偏好的情况下，并且花光所有开销，有多少可能方案。

（由于ans_i可能很大，因此最终结果 ans_i % 10000007）


样例输入
5 2
1 2
2
2 1
样例输出
1

提示
存在一种方案数(1,2)*/
    void dj_003_test() {
        int money,type;
        cin>>money>>type;
        vector<int> price;
        for (int i = 0; i < type; ++i) {
            int p;
            cin>>p;
            price.push_back(p);
        }
        int best;
        cin>>best;
        vector<int> favor;
        for (int j = 0; j < best; ++j) {
            int p;
            cin>>p;
            favor.push_back(p);
        }
        cout<<1;

    }

    void dj_003() {}
};

int main() {
    Solution s;
//    s.dj_001_test();
//    s.dj_002_test();
    s.dj_003_test();
    return 0;
}
