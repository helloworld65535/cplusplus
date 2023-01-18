#include <iostream>
using namespace std;

class Answer
{
public:
    string text;
    Answer()
    {
        text = "空";
        cout << "Answer的无参构造函数调用" << endl;
    }
    Answer(string text)
    {
        this->text = text;
        cout << "Answer的有参构造函数调用" << endl;
    }
    Answer(const Answer &a)
    {
        text = a.text;
        cout << "Answer的拷贝构造函数调用" << endl;
    }

    // 析构函数
    ~Answer()
    {
        cout << "Answer的析构函数调用" << endl;
    }
};

int main(void)
{
    /* 括号法 */
    Answer wangwu;                   // 无参
    Answer lisi("这是李四写的答案"); // 有参
    Answer zhangsan(lisi);           // 拷贝

    /* 显式法*/
    // Answer wangwu1 = Answer();  //或Answer wangwu;
    // Answer lisi1 = Answer("这是李四1写的答案");
    // Answer zhangsan1=Answer(lisi1);

    /* 隐式法 */
    // Answer wangwu2;
    // Answer lisi2 = string("这是李四2写的答案");
    // Answer zhangsan2 = lisi2;

    cout << "王五:" << wangwu.text << endl;
    cout << "李四:" << lisi.text << endl;
    cout << "张三:" << zhangsan.text << endl;
    return 0;
}