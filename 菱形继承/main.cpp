#include <iostream>
using namespace std;

// ��ʱ�����ĸ���Animal��Ϊ�����
class Animal
{
public:
    int age;
};
// �̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
class Sheep : public virtual Animal{};

class Camel : public virtual Animal{};

class Alpaca : public Sheep, public Camel{};

int main(void)
{
    Alpaca a;
    a.age = 10;
    cout << a.Animal::age << endl;
    cout << a.Sheep::age << endl;
    cout << a.Camel::age << endl;
    return 0;
}