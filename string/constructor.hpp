#include <string>
#include <iostream>

namespace Constructor
{
    int main()
    {
        // 默认构造函数创建一个空字符串
        std::cout << "1:默认构造函数创建一个空字符串" << std::endl;
        std::cout << "std::string() :" << std::string() << std::endl;
        // 使用__str值的副本构造字符串
        std::cout << "2:使用__str值的副本构造字符串(拷贝构造)" << std::endl;
        std::string str2 = "copy";
        std::cout << "被拷贝对象std::string str2=\"copy\"" << std::endl;
        std::cout << "std::string(str2) :" << std::string(str2) << std::endl;
        // 构造字符串作为子字符串的副本
        std::cout << "3:构造字符串作为子字符串的副本" << std::endl;
        std::string str3 = "Source";
        std::cout << "源字符串std::string str3=\"Source\"" << std::endl;
        std::cout << "std::string(str3, 2)) :"
                  << std::string(str3, 2) << std::endl;
        // 构造字符串作为子字符串的副本
        std::cout << "4:构造字符串作为子字符串的副本" << std::endl;
        std::string str4 = "Source";
        std::cout << "源字符串std::string str4=\"Source\"" << std::endl;
        std::cout << "std::string(str3, 2, 2) :"
                  << std::string(str3, 2, 2) << std::endl;

        // 构造由字符数组初始化的字符串
        std::cout << "5:构造由字符数组初始化的字符串" << std::endl;
        char arr5[] = "char \0 array";
        std::cout << "字符数组::schar arr5[]=\"char array\"" << std::endl;
        std::cout << "std::string(arr5) :"
                  << std::string(arr5) << std::endl;
        // 构造由字符数组初始化的字符串
        std::cout << "6:构造由字符数组初始化的字符串" << std::endl;
        char arr6[] = "char \0 array";
        std::cout << "字符数组::schar arr6[]=\"char array\"" << std::endl;
        std::cout << "std::string(arr6,10) :"
                  << std::string(arr6, 10) << std::endl;
        // 将字符串构造为多个字符
        std::cout << "7:将字符串构造为多个字符" << std::endl;
        std::cout << "std::string(6,'H') :"
                  << std::string(6, 'H') << std::endl;
        // 移动构造字符串。
        std::cout << "8:移动构造字符串。" << std::endl;
        std::cout << "std::string(std::to_string(123456)) :"
                  << std::string(std::to_string(123456)) << std::endl;
        // 从初始化式列表构造字符串。
        std::cout << "9:从初始化式列表构造字符串。" << std::endl;
        std::cout << "std::string({'h', 'e', 'l', 'l', 'o'}) :"
                  << std::string({'h', 'e', 'l', 'l', 'o'}) << std::endl;
        // 构造字符串作为范围的副本。
        std::cout << "10:构造字符串作为范围的副本。" << std::endl;
        std::string str10 = "Source";
        std::cout << "源字符串std::string str10=\"Source\"" << std::endl;
        std::cout << "std::string(str10.begin(), str10.end()) :"
                  << std::string(str10.begin(), str10.end()) << std::endl;

        return 0;
    }

}
