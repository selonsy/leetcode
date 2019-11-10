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

class HighCar //高配版车型
{
public:
    virtual void createdCar(void) = 0;
};

class HighBenzCar : public HighCar //高配奔驰车
{
public:
    HighBenzCar()
    {
        cout << "HighBenzCarBenz::Benz()" << endl;
    }
    virtual void createdCar(void)
    {
        cout << "HighBenzCar::createdCar()" << endl;
    }
};

class HighBmwCar : public HighCar //高配宝马车
{
public:
    HighBmwCar()
    {
        cout << "HighBmwCar::Bmw()" << endl;
    }
    virtual void createdCar(void)
    {
        cout << "HighBmwCar::createdCar()" << endl;
    }
};

class Factory //车厂
{
public:
    virtual Car *createSpecificCar(void) = 0;
    virtual HighCar *createdSpecificHighCar(void) = 0;
};

class BenzFactory : public Factory //奔驰车厂
{
public:
    virtual Car *createSpecificCar(void)
    {
        return (new BenzCar());
    }

    virtual HighCar *createdSpecificHighCar(void)
    {
        return (new HighBenzCar());
    }
};

class BmwFactory : public Factory //宝马车厂
{
public:
    virtual Car *createSpecificCar(void)
    {
        return (new BmwCar());
    }
    virtual HighCar *createdSpecificHighCar(void)
    {
        return (new HighBmwCar());
    }
};

int main(int argc, char **argv)
{
    Factory *factory = new BenzFactory();
    Car *specificCar = factory->createSpecificCar();
    HighCar *spcificHighCar = factory->createdSpecificHighCar();

    delete factory;
    delete specificCar;
    delete spcificHighCar;

    return 0;
}