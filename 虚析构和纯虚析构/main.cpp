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
        cout << "���๹��" << endl;
    }
    virtual ~Abstract_vector()
    {
        cout << "����������" << endl;
    }

    virtual void Print() = 0;       // ��ӡԪ��
    virtual void add(int data) = 0; // ���Ԫ��

    // virtual ~Abstract_vector()=0;//���ി������
};
/* //���ി������
 Abstract_vector::~Abstract_vector()
 {
    cout << "���ി������" << endl;
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
        cout << "���๹��" << endl;
    }
    ~int_vector()
    {
        if (array)
        {
            cout << "��������" << endl;
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
    cout << "!!���н���!!" << endl;
    return 0;
}