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
    // 网易笔试题 2019-08-11 14:30 150min
    void wy_003_test() {
        int num;
        cin >> num;
        vector<int> line_num;
        vector<string> data;
        for (int i = 0; i < num; ++i) {
            string s;
            cin >> s;
            data.push_back(s);
        }
        wy_003(num, data, 'N', 2, line_num);
        for (int i = 0; i < num; ++i) {
            cout << line_num[i] << endl;
        }
    }

    void wy_003(int num, vector<string> data, char letter, int max_skip_num, vector<int> &output_num) {
        for (int i = 0; i < num; ++i) {
            string str = data[i];
            int last_pos = 0, l_num = 0, skip = 0, max_num = 0;
            vector<int> ret;
            for (int j = 0; j < str.length(); ++j) {
                if (str[j] == letter) {
                    ++l_num;
                    if (l_num > max_num)
                        max_num = l_num;
                } else if (skip < max_skip_num) {
                    ++l_num;
                    ++skip;
                    if (skip == 1) {
                        last_pos = j;
                    }
                } else {
                    ret.push_back(l_num);
                    l_num = 0;
                    skip = 0;
                    j = last_pos;
                }
            }
            max_num = *max_element(ret.begin(),ret.end());
            output_num.push_back(max_num);
        }
    }
// 网易笔试题 2019-08-11 14:30 150min
    void wy_003_test1() {
        int n, m;
        cin >> n;
        vector<int> num;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            num.push_back(m);
        }
        int front = num[0], end;
        vector<int> rest;
        for (int l = 0; l < n; ++l) {
            rest.push_back(100);
        }
        for (int j = 1; j < n; ++j) {
            end = j<n-1?num[j+1]:num[n-1];
            if (num[j] > front && num[j] > end) {
                rest[j] = rest[j - 1] + 100;
                j++;
            } else if (num[j] < front) {
                rest[j] = rest[j - 1] - 100;
            } else if (num[j] > front) {
                rest[j] = rest[j - 1] + 100;
            }
        }
        vector<int>::iterator myMin = max_element(rest.begin(), rest.end());
        int ret = 0;
        for (int k = 0; k < n; ++k) {
            ret += rest[k];
        }
        ret += (100 - *myMin) * n;
//        vector<int>::iterator myMax = max_element(myVec.begin(), myVec.end());
//        cout << *myMax << " " << distance(myVec.begin(), myMax) << endl;


//        int ret = n * 100;
//        for (int j = 1; j < n; ++j) {
//            end = num[j + 1];
//            if (num[j] > front && num[j] > end) {
//                ret += 100;
//                j += 1;
//            } else if (num[j] > front) {
//                ret += 100;
//            }
//        }
        cout << ret << endl;
    }
    // 网易笔试题 2019-08-11 14:30 150min
    void wy_003_test2() {
        int num;
        cin >> num;
        vector<int> line_num;
        vector<string> data;
        for (int i = 0; i < num; ++i) {
            string s;
            cin >> s;
            data.push_back(s);
        }
        wy_003_2(num, data, 'N', 2, line_num);
        for (int i = 0; i < num; ++i) {
            cout << line_num[i] << endl;
        }
    }

    void wy_003_2(int num, vector<string> data, char letter, int max_skip_num, vector<int> &output_num) {
        for (int i = 0; i < num; ++i) {
            string str = data[i];
            int last_pos = 0, l_num = 0, skip = 0, max_num = 0;
            vector<int> ret;
            for (int j = 0; j < str.length(); ++j) {
                if (str[j] == letter) {
                    ++l_num;
                    if (l_num > max_num)
                        max_num = l_num;
                } else if (skip < max_skip_num) {
                    ++l_num;
                    ++skip;
                    if (skip == 1) {
                        last_pos = j;
                    }
                } else {
                    ret.push_back(l_num);
                    l_num = 0;
                    skip = 0;
                    j = last_pos;
                }
            }
            vector<int>::iterator kk;
            for (kk=ret.begin();kk!=ret.end();kk++) {
                max_num = max(max_num,*kk);
            }
//            max_num = *max_element(ret.begin(),ret.end());
            output_num.push_back(max_num);
        }
    }
    void wy_004_test() {
        int N, M, t;
        cin >> N;
        vector<int> NN, MM;
        for (int i = 0; i < N; ++i) {
            cin >> t;
            NN.push_back(t);
        }
        cin >> M;
        for (int j = 0; j < M; ++j) {
            cin >> t;
            MM.push_back(t);
        }
        wy_004(N, NN, M, MM);
    }

    void wy_004(int n, vector<int> heights, int q, vector<int> hongshuis) {
        bool reset = true;
        for (int item : hongshuis) {
            int counter = 0;
            for (int h : heights) {
                if (h > item && reset) {
                    counter++;
                    reset = false;
                }
                if (h <= item) {
                    reset = true;
                }
            }
            cout << counter << endl;
        }
    }

    // 网易笔试题 2019-08-11 14:30 150min
    void wy_003_test3() {
        int num;
        cin >> num;
        vector<int> line_num;
        vector<string> data;
        for (int i = 0; i < num; ++i) {
            string s;
            cin >> s;
            data.push_back(s);
        }
        wy_003(num, data, 'N', 2, line_num);
        for (int i = 0; i < num; ++i) {
            cout << line_num[i] << endl;
        }
    }
    void wy_003_3(int num, vector<string> data, char letter, int max_skip_num, vector<int> &output_num) {
        for (int i = 0; i < num; ++i) {
            string s = data[i];
            int max_num = 0, cur_len = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != 'N')
                {
                    auto temp = s[i];
                    s[i] = 'N';
                    cur_len = s_n(s);
                    if (cur_len > max_num) max_num = cur_len;
                    for (int j = i; j < s.size(); j++)
                    {
                        if (s[j] != 'N')
                        {
                            auto temp_j = s[j];
                            s[j] = 'N';
                            cur_len = s_n(s);
                            if (cur_len > max_num) max_num = cur_len;
                            s[j] = temp_j;
                        }
                    }
                    s[i] = temp;
                }

            }
            output_num.push_back(max_num);
        }
    }
    int s_n(string s)
    {
        int max = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'N')
            {
                len++;
                if (len > max) max = len;
            }
            else
            {
                len = 0;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
//    s.wy_001_test();
//    s.wy_002_test();
    s.wy_003_test();
//    s.wy_004_test();
    return 0;
}

//void GetConseccutiveLetterNum(
//        int num, string data[], char letter,
//        int max_skip_num, int *output_num
//) {
//    for (int i = 0; i < num; ++i) {
//        string str = data[i];
//        int last_pos = 0, l_num = 0, skip = 0, max_num = 0;
//        for (int j = 0; j < str.length(); ++j) {
//            if (str[j] == letter) {
//                ++l_num;
//                if (l_num > max_num)
//                    max_num = l_num;
//            } else if (skip < max_skip_num) {
//                ++l_num;
//                ++skip;
//                if (skip == 1) {
//                    last_pos = j;
//                }
//            } else {
//                l_num = 0;
//                skip = 0;
//                j = last_pos;
//            }
//        }
//        output_num[i] = max_num;
//    }
//}
//
//int main() {
//    int num;
//    cin >> num;
//    int *line_num = new int(num);
//    string *data = new string[num];
//    for (int i = 0; i < num; ++i) {
//        cin >> data[i];
//    }
//    GetConseccutiveLetterNum(num, data, 'N', 2, line_num);
//    for (int i = 0; i < num; ++i) {
//        cout << line_num[i] << endl;
//    }
//    return 0;
//}

// 网易笔试题 2019-08-11 14:30 150min

//void wy_001_test() {
//    int N,M,T;
//    cin>>N;
//    for (int i = 0; i < N; ++i) {
//        cin>>M;
//        int s[32]={0};
//        int ret=0;
//        for (int j = 0; j < M; ++j) {
//            cin>>T;
//            int t=0;
//            while(T!=0)
//            {
//                int q = T%2;
//                if(q==1)t++;
//                T = T>>1;
//            }
//            s[t]++;
//        }
//        for (int k = 0; k < 32; ++k) {
//            if(s[k]!=0)ret++;
//        }
//        cout<<ret<<endl;
//    }
//}
//
//void wy_001() {
//
//}
//
//void wy_002_test() {
//    int X;
//    cin>>X;
//    vector<int> ret;
//    for (int i = 0; i <X ; ++i) {
//        int m,t,m1,t1,m2,t2;
//        cin>>m>>t>>m1>>t1>>m2>>t2;
//        int s = wy_002(m,t,m1,t1,m2,t2);
//        ret.push_back(s);
////            while(tt<=t){
////                if(open && close){
////                    ret += max((m1-m2),0);
////                } else if(!open && close){
////                    ret -= m2;
////                    ret = max(ret,0);
////                }else if(open && !close){
////                    ret+=m1;
////                }
////                tt++;
////                if(tt%t1==0)open=!open;
////                if(tt%t2==0)close=!close;
////            }
////            if(ret<=0)cout<<0<<endl;
////            else if(ret>=m)cout<<m<<endl;
////            else cout<<ret<<endl;
//    }
//    for(int a:ret){
//        cout<<a<<endl;
//    }
//}
//
//int wy_002(int m,int t,int m1,int t1,int m2,int t2) {
//    bool open[] = {true, true};
//    int remain = 0;
//    for (int i = 1; i <= t; i++) {
//        if (open[0] && open[1]) {
//            remain = max(remain + m1 - m2, 0);
//        } else if (open[0]) {
//            remain = max(remain + m1, 0);
//        } else if (open[1]) {
//            remain = max(remain - m2, 0);
//        }
//        remain = min(remain,m);
//        if (i % t1 == 0) {
//            open[0] = !open[0];
//        }
//        if (i % t2 == 0) {
//            open[1] = !open[1];
//        }
//    }
//    return remain;
//}
//void GetConseccutiveLetterNum(
//        int num, string data[], char letter,
//        int max_skip_num, int *output_num
//) {
//    for (int i = 0; i < num; ++i) {
//        string str = data[i];
//        int last_pos = 0, l_num = 0, skip = 0, max_num = 0;
//        for (int j = 0; j < str.length(); ++j) {
//            if (str[j] == letter) {
//                ++l_num;
//                if (l_num > max_num)
//                    max_num = l_num;
//            } else if (skip < max_skip_num) {
//                ++l_num;
//                ++skip;
//                if (skip == 1) {
//                    last_pos = j;
//                }
//            } else {
//                l_num = 0;
//                skip = 0;
//                j = last_pos;
//            }
//        }
//        output_num[i] = max_num;
//    }
//}
//void wy_003_test() {
//    int num;
//    cin >> num;
//    int *line_num = new int(num);
//    string *data = new string[num];
//    for (int i = 0; i < num; ++i) {
//        cin >> data[i];
//    }
//    GetConseccutiveLetterNum(num, data, 'N', 2, line_num);
//    for (int i = 0; i < num; ++i) {
//        cout << line_num[i] << endl;
//    }
//}
//
//void wy_003() {}