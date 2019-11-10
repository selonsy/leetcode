#include <iostream>
using namespace std;
int main()
{
    double c = 9.527345;
    char c_s[10];
    sprintf(c_s, "%.2lf", c);
    cout<<c_s<<endl;   //输出 9.53
    printf("%.2f",c); //输出 
    return 0;
}