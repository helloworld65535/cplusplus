#include <iostream>
using namespace std;

class Abstract_vector
{
protected:
    int size;
    int capacity;

public:
    Abstract_vector()
    {
        cout << "父类构造" << endl;
    }
    virtual ~Abstract_vector()
    {
        cout << "父类虚析构" << endl;
    }

    virtual void Print() = 0;       // 打印元素
    virtual void add(int data) = 0; // 添加元素

    // virtual ~Abstract_vector()=0;//父类纯虚析构
};
/* //父类纯虚析构
 Abstract_vector::~Abstract_vector()
 {
    cout << "父类纯虚析构" << endl;
 }
 */

class int_vector : public Abstract_vector
{
private:
    int *array;

public:
    virtual void Print()
    {
        cout << "[";
        for (int i = 0; i < size; i++)
        {
            cout << array[i];
            if (i != size - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }

    void add(int data)
    {
        if (size >= capacity)
        {
            cout << "vector full";
            return;
        }
        array[size++] = data;
    }

    int_vector(int c)
    {
        size = 0;
        capacity = c;
        array = new int[capacity];
        cout << "子类构造" << endl;
    }
    ~int_vector()
    {
        if (array)
        {
            cout << "子类析构" << endl;
            delete[] array;
            array = nullptr;
        }
    }
};

void testfunc()
{
    Abstract_vector *a = new int_vector(2);
    a->add(1);
    a->add(2);
    a->Print();

    delete a;
}

int main(void)
{
    testfunc();
    cout << "!!运行结束!!" << endl;
    return 0;
}