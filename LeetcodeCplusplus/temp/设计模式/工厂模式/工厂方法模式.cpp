#include <iostream>
using namespace std;

class Car //车类
{
public:
    virtual void createdCar(void) = 0;
};

class BenzCar : public Car //奔驰车
{
public:
    BenzCar()
    {
        cout << "Benz::Benz()" << endl;
    }
    virtual void createdCar(void)
    {
        cout << "BenzCar::createdCar()" << endl;
    }
    ~BenzCar()
    {
    }
};

class BmwCar : public Car //宝马车
{
public:
    BmwCar()
    {
        cout << "Bmw::Bmw()" << endl;
    }
    virtual void createdCar(void)
    {
        cout << "BmwCar::createdCar()" << endl;
    }
};

class Factory //车厂
{
public:
    virtual Car *createSpecificCar(void) = 0;
};

class BenzFactory : public Factory //奔驰车厂
{
public:
    virtual Car *createSpecificCar(void)
    {
        return (new BenzCar());
    }
};

class BmwFactory : public Factory //宝马车厂
{
public:
    virtual Car *createSpecificCar(void)
    {
        return (new BmwCar());
    }
};

int main(int argc, char **argv)
{
    Factory *factory = new BenzFactory();
    Car *specificCarA = factory->createSpecificCar();
    factory = new BmwFactory();
    Car *specificCarB = factory->createSpecificCar();

    delete factory;
    delete specificCarA;
    delete specificCarB;

    return 0;
}