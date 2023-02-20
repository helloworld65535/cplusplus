#include <string>
#include <iostream>

namespace Assign
{
    int main(void)
    {
        std::string str;
        // 将value设置为另一个字符串的内容(引用)
        std::cout << "1:将value设置为另一个字符串的内容(引用)" << std::endl;
        std::string another = "another";
        std::cout << "std::string another = \"another\"" << std::endl;
        std::cout << "str.assign(another):" << std::endl;
        str.assign(another);
        std::cout << str << std::endl;
        // 将value设置为另一个字符串的内容(右值引用)
        std::cout << "2:将value设置为另一个字符串的内容(右值引用)" << std::endl;
        std::cout << "str.assign(std::to_string(3.14)):" << std::endl;
        str.assign(std::to_string(3.14));
        std::cout << str << std::endl;
        // 将value设置为字符串的子字符串
        std::cout << "3:将value设置为字符串的子字符串" << std::endl;
        std::string another3 = "another";
        std::cout << "std::string another3 = \"another\"" << std::endl;
        std::cout << "str.assign(another3, 2):" << std::endl;
        str.assign(another3, 2);
        // 将value设置为字符串的子字符串
        std::cout << "4:将value设置为字符串的子字符串" << std::endl;
        std::string another4 = "another";
        std::cout << "std::string another4 = \"another\"" << std::endl;
        std::cout << "str.assign(another4,2,5):" << std::endl;
        str.assign(another4, 2, 5);
        std::cout << str << std::endl;
        // 将value设置为C字符串的子字符串
        std::cout << "5:将value设置为C字符串的子字符串" << std::endl;
        char another5[] = "another";
        std::cout << "char another5[] = \"another\"" << std::endl;
        std::cout << "str.assign(another5, 2):" << std::endl;
        str.assign(another5, 2);
        std::cout << str << std::endl;
        // 将value设置为C字符串
        std::cout << "6:将value设置为C字符串" << std::endl;
        char another6[] = "another";
        std::cout << "char another6[] = \"another\"" << std::endl;
        std::cout << "str.assign(another6):" << std::endl;
        str.assign(another6);
        std::cout << str << std::endl;
        // 将value设置为多个字符
        std::cout << "7:将value设置为多个字符" << std::endl;
        std::cout << "str.assign(6,'!'):" << std::endl;
        str.assign(6, '!');
        std::cout << str << std::endl;
        // 将value设置为某个范围内的字符
        std::cout << "8:将value设置为某个范围内的字符" << std::endl;
        std::string another7 = "another";
        std::cout << "std::string another7 = \"another\"" << std::endl;
        std::cout << "str.assign(another7.begin(), another7.end()):" << std::endl;
        str.assign(another7.begin(), another7.end());
        std::cout << str << std::endl;

        return 0;
    }
}