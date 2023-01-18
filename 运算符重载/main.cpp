#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
        cout << "Point(" << x << "," << y << ")������һ�ݿ���" << endl;
    }
    void Print()
    {
        cout << "Point(" << x << "," << y << ")" << endl;
    }
    /*
        ~Point()
        {
            cout << "Point(" << x << "," << y << ")��������" << endl;
        }
     */
    // + - * / ���������
    Point operator+(const Point &c)
    {
        Point temp;
        temp.x = x + c.x;
        temp.y = y + c.y;
        return temp;
    }
    Point operator-(const Point &c)
    {
        Point temp;
        temp.x = x - c.x;
        temp.y = y - c.y;
        return temp;
    }
    Point operator*(const Point &c)
    {
        Point temp;
        temp.x = x * c.x;
        temp.y = y * c.y;
        return temp;
    }
    Point operator/(const Point &c)
    {
        Point temp;
        temp.x = x / c.x;
        temp.y = y / c.y;
        return temp;
    }

    // >> ���������
    friend ostream &operator<<(ostream &cout, const Point &p)
    {
        cout << "Point(" << p.x << "," << p.y << ")";
        return cout;
    }
    friend istream &operator>>(istream &cin, Point &p)
    {
        cin >> p.x >> p.y;
        return cin;
    }

    // == != ���������
    bool operator==(const Point &p)
    {
        return (x == p.x && y == p.y);
    }
    bool operator!=(const Point &p)
    {
        return !(x == p.x && y == p.y);
    }

    // = ���������
    Point &operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }

    // ++ ���������
    Point &operator++() // ǰ��++
    {
        x++;
        y++;
        return *this;
    }

    const Point operator++(int) // ����++
    {
        Point temp = *this;
        x++;
        y++;
        return temp;
    }

    // ������������� () ����
    double operator()(const Point& p)
    {
        double distance=sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
        return distance;
    }
};

void test_1()
{
    cout << " + ��������ز���" << endl;
    Point p1(1, 2);
    Point p2(2, 3);
    Point p3 = p1 + p2;
    p3.Print();
    cout << "================" << endl;
}
void test_2()
{
    cout << " - ��������ز���" << endl;
    Point p1(1, 2);
    Point p2(2, 3);
    Point p3 = p1 - p2;
    p3.Print();
    cout << "================" << endl;
}
void test_3()
{
    cout << " * ��������ز���" << endl;
    Point p1(1, 2);
    Point p2(2, 3);
    Point p3 = p1 * p2;
    p3.Print();
    cout << "================" << endl;
}
void test_4()
{
    cout << " / ��������ز���" << endl;
    Point p1(1, 2);
    Point p2(2, 3);
    Point p3 = p1 / p2;
    p3.Print();
    cout << "================" << endl;
}
void test_5()
{
    cout << " << ��������ز���" << endl;
    Point p(1, 2);
    cout << p << endl;
    cout << "================" << endl;
}
void test_6()
{
    cout << " >> ��������ز���" << endl;
    Point p;
    cin >> p;
    p.Print();
    cout << "================" << endl;
}
void test_7()
{
    cout << " == ��������ز���" << endl;
    Point p1(2, 4);
    Point p2(2, 4);
    Point p3(3, 4);
    cout << "p1=";
    p1.Print();
    cout << "p2=";
    p2.Print();
    cout << "p3=";
    p3.Print();
    cout << "p1==p2?" << (p1 == p2) << endl;
    cout << "p1==p3?" << (p1 == p3) << endl;
    cout << "================" << endl;
}
void test_8()
{
    cout << " != ��������ز���" << endl;
    Point p1(2, 4);
    Point p2(2, 4);
    Point p3(3, 4);
    cout << "p1=";
    p1.Print();
    cout << "p2=";
    p2.Print();
    cout << "p3=";
    p3.Print();
    cout << "p1!=p2?" << (p1 != p2) << endl;
    cout << "p1!=p3?" << (p1 != p3) << endl;
    cout << "================" << endl;
}
void test_9()
{
    cout << " = ��������ز���" << endl;
    Point p1, p2, p3(2, 4);
    p1 = p2 = p3;
    p1.Print();
    p2.Print();
    p3.Print();
    cout << "================" << endl;
}
void test_10()
{
    cout << " ++ ��������ز���" << endl;
    Point p(1, 2);
    cout << (++p)++ << endl;
    p.Print();
    cout << "================" << endl;
}
void test_11()
{
    cout << " () ��������ز���" << endl;
    Point p1(0, 0);
    Point p2(3, 4);
    p1.Print();
    p2.Print();
    cout<<"distance:"<<p1(p2)<<endl;

    cout << "================" << endl;
}

int main(void)
{
    test_11();

    return 0;
}