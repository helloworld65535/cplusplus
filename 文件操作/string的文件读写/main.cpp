#include <iostream>
#include <fstream> //����ͷ�ļ�
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
    // ����������
    std::ofstream outfilestream;
    // ָ���򿪷�ʽ
    outfilestream.open("write.txt", std::ios::out);

    // д������
    outfilestream << Person("����", 18);
    outfilestream << Person("����", 19);
    outfilestream << Person("����", 20);

    // �ر���
    outfilestream.close();
}
void ReadFile()
{
    // ����������
    std::ifstream infilestream;
    // ָ���򿪷�ʽ
    infilestream.open("write.txt", std::ios::in);
    // �ж��Ƿ�򿪳ɹ�
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

    // �ر���
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