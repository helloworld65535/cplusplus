#include <iostream>
#include <cmath>
using namespace std;

// ��װһ��Բ�࣬��Բ���ܳ�
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
        cout<<"Բ(r="<<r<<"):"<<endl;
    }
};

int main(void)
{
    Circle c1;//ʵ����
    c1.r=3;
    c1.Print();//
    cout<<"�ܳ�:"<<c1.getCircumference()<<endl;
    cout<<"���:"<<c1.getArea()<<endl;
    return 0;
}