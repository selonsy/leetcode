//
// Created by devin on 2019-05-30.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//查找
// 自定义实现二分查找：如果查找到，就返回在数组中的下标，否则返回-1
int searchBin(int arr[], int len, int x)
{
    int low, high, mid;
    low = 0;
    high = len - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == arr[mid])
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
void search()
{
    int a[100] = {4, 10, 11, 30, 69, 70, 96, 100};
    int b = binary_search(a, a + 9, 4); //查找成功，返回1
}
void sort()
{
    vector<int> vec ;//= {2, 4, 6, 3, 10};

    //三个参数：开始，结束，比较函数（可省，默认为less()）
    //    sort(vec.begin(),vec.end(),less<int>());
    //    sort(vec.begin(),vec.begin()+3,less<int>());
    sort(vec.begin(), vec.end(), greater<int>());
    // 比较仿函数还有less_equal,greater_equal,equal_to,not_equal_to等~
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;

    //    return 0;
}

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

void split_test()
{
    string s = "sjl love qsy";
    vector<string> ss = split(s, " ");
    for (auto _s : ss)
    {
        cout << _s << endl;
    }
}

// 类型转换
void type_convert()
{

    // int 和 string 的转换
    // 可以这样理解，stringstream可以吞下不同的类型，根据s2的类型，然后吐出不同的类型。
    int aa = 30;
    stringstream ss;
    ss << aa;
    string s1 = ss.str();
    cout << s1 << endl; // 30

    string s2;
    ss >> s2;
    cout << s2 << endl; // 30

    // sprintf,需要头文件 stdio.h
    int i = 1234;
    char buf[10];
    sprintf(buf, "%d", i);
    cout << buf << endl; //"1234"

    //    // itoa,windows特有，跨平台不好，可能无效，需要头文件 stdlib.h
    //    int j=1234;
    //    char buf1[10];
    //    itoa(j, buf1, 10);

    int j = 5678;
    string jj = to_string(j); //c11新增的函数
    int k = atoi(buf);        //字符数组转整型

    // string 和 char[] 的转换

    //    将string类型转换为字符数组
    char arr1[10];
    string s11("ABCDEFG");
    int len = s11.copy(arr1, 9);
    arr1[len] = '\0';
    //    或者
    char arr2[10];
    string s22("ABCDEFG");
    strcpy(arr2, s22.c_str()); //strncpy(arr, s.c_str(), 10);

    //    字符数组转化成string类型
    char arr3[] = "ABCDEFG";
    string s33(arr3); //也可string str = ch;
                      //    或者
    char arr4[] = "ABCDEFG";
    string s44;
    s44 = arr4; //在原有基础上添加可以用s += arr;
}

// 输入输出
void input_output()
{
    // 空白字符（空格，TAB，回车）

    // 读取一个数字，并赋值
    int a1, a2;
    scanf("%d", &a1); //1
    cin >> a2;        //2
    // 注：%f，float；%lf，double；

    // 读取一个字符，并赋值
    char b1, b2, b3, b4;
    scanf("%*c%c", &b1); //1，此时上一行的末尾还有个换行符，需要跳过，使用  %*c;%*d,etc.
    cin >> b2;           //2
    b3 = getchar();      //3，需要包含<string>
    b4 = cin.get();      //4

    // 读取一个字符串，并赋值
    string c1;
    getline(cin, c1); //1，需要包含<string>

    char c2[20];
    gets(c2); //2，需要包含<string>

    char c3[20];
    scanf("%[^\n]", &c3); //3，直接读到一行的末尾，遇到回车结束

    char c4[20];
    cin >> c4; //4，遇到空格，回车，tab等结束

    //    char c5[5];
    //    cin.get(c5, 5);      //5，第二个参数指定接受字符的数目，可以接受空格（记得算上\0，也就是有效长度要减一）
    //
    //    char c6[5];
    //    cin.getline(c6, 5);  //6，函数原型为：cin.getline(m,5,'a'); 第三个参数为结束字符标记

    // 读取一行的两个数字，并分别赋值
    int d1, d2, d3, d4;
    cin >> d1 >> d2;
    scanf("%d%d", &d3, &d4);

    // 读取一行的多个数字，并赋值给一个数组
    //1、知道具体的数目或者最大的个数
    int e1[100], ei = 0, en;
    while (ei < 100)
    {
        cin >> e1[ei++];
        if (cin.get() == '\n')
            break; //遇到回车，输入结束
    }
    en = ei; //记录输入个数
    //2、不知道具体的数目(同样适用于字符串数组类型)
    string e2;
    getline(cin, e2);
    stringstream ss1(e2); //需要包含：#include<sstream>
    vector<int> e3;
    int e4;
    while (ss1 >> e4)
        e3.push_back(e4);

    // 根据输入，循环读取多个数字到一个二维数组
    int f1, f2;
    cin >> f1 >> f2;
    int f3[f1][f2];
    for (int k = 0; k < f1; ++k)
    {
        for (int j = 0; j < f2; ++j)
        {
            cin >> f3[k][j];
        }
    }

    // 输出一个字符串
    char s[10] = "sjl";
    printf(s);
    cout << s;

    // 输出一个字符数组

    // 输出一个整数数组，中间有空格，末尾无空格
    int g1[5] = {9, 5, 2, 7};
    int g1_length = sizeof(g1) / sizeof(g1[0]);
    for (int i = 0; i < 5; ++i)
    {
        cout << g1[i];
        if (i != 4)
            cout << " ";
    }
}

int main()
{
    cout << "exam base.cpp say Hello world!" << endl;
    //sort();
    //    type_convert();

    return 0;
}
