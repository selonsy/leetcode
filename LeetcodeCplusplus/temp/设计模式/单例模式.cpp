#include <iostream>
#include <thread>
using namespace std;

class Singelton
{
private:
    Singelton() {}
    static Singelton *single;

public:
    static Singelton *GetSingelton();
};
Singelton *Singelton::single = nullptr;
Singelton *Singelton::GetSingelton()
{
    if (single == nullptr)
    {
        single = new Singelton;
    }
    return single;
}

int main()
{
    // 只有我们调用GetSingelton时，类才会new出对象。
    Singelton *s1 = Singelton::GetSingelton();
    Singelton *s2 = Singelton::GetSingelton();
    assert(s1 == s2);

    return 0;
}