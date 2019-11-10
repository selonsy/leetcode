#include <iostream>
using namespace std;

enum CarType
{
    BENZ,
    BMW
};

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

class CarFactory //车厂
{
public:
    Car *createSpecificCar(CarType type)
    {
        switch (type)
        {
        case BENZ: //生产奔驰车
            return (new BenzCar());
            break;
        case BMW: //生辰宝马车
            return (new BmwCar());
            break;
        default:
            return NULL;
            break;
        }
    }
};

int main(int argc, char **argv)
{
    CarFactory carfac;
    Car *specificCarA = carfac.createSpecificCar(BENZ); //看到网上众多示例在new后没有delete，感觉不是特别严谨
    Car *specificCarB = carfac.createSpecificCar(BMW);

    delete specificCarA;
    delete specificCarB;

    return 0;
}