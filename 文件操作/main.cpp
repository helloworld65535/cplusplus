#include <iostream>

#include <fstream> //包含头文件
using namespace std;
void WriteFile()
{
    // 创建流对象
    ofstream outfilestream;
    // 指定打开方式
    outfilestream.open("write.txt", ios::out);
    // 写入数据
    outfilestream << "姓名：张三" << endl;
    outfilestream << "年龄：18" << endl;
    outfilestream << "性别：男" << endl;
    // 关闭流
    outfilestream.close();
}
void ReadFile()
{
    // 创建流对象
    ifstream infilestream;
    // 指定打开方式
    infilestream.open("write.txt", ios::in);
    // 判断是否打开成功
    if (!infilestream.is_open())
    {
        cout << "open file fail" << endl;
        infilestream.close();
        return;
    }
    // 读取数据
    /* 方法一 */

    /* char buf1[1024] = {0};
    while (infilestream >> buf1)
    {
        cout << buf1 << endl;
    } */

    /* 方法二 */

    /* char buf2[1024] = {0};
    while (infilestream.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    } */

    /* 方法三 */

    string buf3;
    while (getline(infilestream, buf3))
    {
        cout << buf3 << endl;
    }

    /* 方法四 */

    /* char buf4;
    while ((c = infilestream.get()) != EOF)
    {
        cout << buf4;
    } */

    // 关闭流
    infilestream.close();
}

class Person
{
public:
    char name[64];
    int age;
};
void BinaryWriteFile()
{
    ofstream outfilestream;
    // 指定打开方式
    outfilestream.open("binarywrite.txt", ios::out | ios::binary);
    // 写入数据
    Person p1 = {"张三", 18};
    Person p2 = {"李四", 19};
    Person p3 = {"王五", 20};
    outfilestream.write((const char *)&p1, sizeof(Person));
    outfilestream.write((const char *)&p2, sizeof(Person));
    outfilestream.write((const char *)&p3, sizeof(Person));

    // 关闭流
    outfilestream.close();
}

void BinaryReadFile()
{
    fstream infilestream;
    // 指定打开方式
    infilestream.open("binarywrite.txt", ios::in | ios::binary);
    // 判断是否打开成功
    if (!infilestream.is_open())
    {
        cout << "open file fail" << endl;
        infilestream.close();
        return;
    }
    // 读取数据
    Person p[3];
    // infilestream.read((char *)&p[0], sizeof(Person));
    // infilestream.read((char *)&p[1], sizeof(Person));
    // infilestream.read((char *)&p[2], sizeof(Person));

    for (int i = 0; i < 3; i++)
    {
        infilestream.read((char *)&p[i], sizeof(Person));
        cout << "姓名：" << p[i].name << endl
             << "年龄：" << p[i].age << endl;
    }

    // 关闭流
    infilestream.close();
}
int main(void)
{
    cout<<"_______WriteFile_______"<<endl;
    WriteFile();
    cout<<"_______ReadFile_______"<<endl;
    ReadFile();
    cout<<"_______BinaryWriteFile_______"<<endl;
    BinaryWriteFile();
    cout<<"_______BinaryReadFile_______"<<endl;
    BinaryReadFile();
    cout << "Exit" << endl;
    return 0;
}