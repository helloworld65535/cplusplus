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


int main(void)
{
    cout<<"_______WriteFile_______"<<endl;
    WriteFile();
    cout<<"_______ReadFile_______"<<endl;
    ReadFile();
    cout << "Exit" << endl;
    return 0;
}