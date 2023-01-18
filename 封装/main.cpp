#include <iostream>
#include <cmath>
using namespace std;

// 封装一个圆类，求圆的周长
class Circle
{
private:
public:
    double r;
    double getCircumference()
    {
        return 2 * M_PI * r;
    }

    double getArea()
    {
        return M_PI * r * r;
    }
    void Print()
    {
        cout<<"圆(r="<<r<<"):"<<endl;
    }
};

int main(void)
{
    Circle c1;//实例化
    c1.r=3;
    c1.Print();//
    cout<<"周长:"<<c1.getCircumference()<<endl;
    cout<<"面积:"<<c1.getArea()<<endl;
    return 0;
}