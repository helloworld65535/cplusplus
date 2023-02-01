#include <iostream>
#include <fstream> //包含头文件
#include <string>
class Person
{
public:
    std::string name_;
    int age_;
    Person(std::string name = "", int age = 0) : name_(name), age_(age) {}
    friend std::ofstream &operator<<(std::ofstream &out, const Person &person)
    {
        out << person.name_ << std::endl;
        out << person.age_ << std::endl;
        return out;
    }
    friend std::ostream &operator<<(std::ostream &out, const Person &person)
    {
        out << person.name_ << std::endl;
        out << person.age_ << std::endl;
        return out;
    }

    friend std::ifstream &operator>>(std::ifstream &in, Person &person)
    {
        std::string age;
        std::getline(in, person.name_);
        std::getline(in, age);
        person.age_ = stoi(age);
        return in;
    }
};

void WriteFile()
{
    // 创建流对象
    std::ofstream outfilestream;
    // 指定打开方式
    outfilestream.open("write.txt", std::ios::out);

    // 写入数据
    outfilestream << Person("张三", 18);
    outfilestream << Person("李四", 19);
    outfilestream << Person("王五", 20);

    // 关闭流
    outfilestream.close();
}
void ReadFile()
{
    // 创建流对象
    std::ifstream infilestream;
    // 指定打开方式
    infilestream.open("write.txt", std::ios::in);
    // 判断是否打开成功
    if (!infilestream.is_open())
    {
        std::cout << "open file fail" << std::endl;
        infilestream.close();
        return;
    }

    for (size_t i = 0; i < 3; i++)
    {
        Person temp;
        infilestream >> temp;
        std::cout << temp << std::endl;
    }

    // 关闭流
    infilestream.close();
}
int main(void)
{
    std::cout << "_______WriteFile_______" << std::endl;
    WriteFile();
    std::cout << "_______ReadFile_______" << std::endl;
    ReadFile();
    std::cout << "Exit" << std::endl;
    return 0;
}