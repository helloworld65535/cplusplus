#include <iostream>
using namespace std;

template <class DataType>
class Template_Base
{
protected:
    int a;
    DataType b;
};

template <class DataType>
class Template_Drived : public Template_Base<DataType>
{
public:
    void Print()
    {
        cout << "[派生类]模板 调用 [基类模板]的成员" << endl;
        cout << "Template_Base{ int a = " << Template_Base<DataType>::a
             << " DataType b = " << Template_Base<DataType>::b
             << "}" << endl;
    }
};

class Drived : public Template_Base<double>
{
public:
    void Print()
    {
        cout << "[派生类] 调用 [基类模板]的成员" << endl;
        cout << "Template_Base{ int a = " << a
             << " DataType b = " << b
             << "}" << endl;
    }
};

class MultiDrived:public Template_Base<double>,public Template_Base<int>
{
    public:
};

template <class DataType1,class DataType2>
class Template_MultiDrived:public Template_Base<DataType1>,public Template_Base<DataType2>
{

};

int main()
{
    Template_Drived<float> tTemplate_Drived;
    tTemplate_Drived.Print();

    Template_Drived<int> tTemplate_Drived1;
    tTemplate_Drived1.Print();

    // Drived tDrived;
    // tDrived.Print();

    return 0;
}