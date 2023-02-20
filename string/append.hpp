#include <iostream>
#include <string>

namespace Append
{
    int main(void)
    {
        std::cout<<"str=\"hello world\""<<std::endl;
        // 向字符串的末尾添加字符
        for (int i = 0; i < 10; i++)
        {
            std::string str = "hello world";
            switch (i)
            {
            case 0:
            {
                std::cout << "1:将一个字符串追加到此字符串" << std::endl;
                std::string another = "hello";
                std::cout << "std::string another = \"hello\"" << std::endl;
                std::cout << "str.append(another) :" << std::endl;
                str.append(another);
                std::cout << str << std::endl;
            }
            break;
            case 1:
            {
                std::cout << "2:将一个字符串的部分追加到此字符串" << std::endl;
                std::string another = "hello";
                std::cout << "std::string another = \"hello\"" << std::endl;
                std::cout << "str.append(another,1,4) :" << std::endl;
                str.append(another, 1, 4);
                std::cout << str << std::endl;
            }
            break;
            case 2:
            {
                std::cout << "3:将一个C字符串追加到此字符串" << std::endl;
                char another[] = "hello";
                std::cout << "char another[] = \"hello\"" << std::endl;
                std::cout << "str.append(another) :" << std::endl;
                str.append(another);
                std::cout << str << std::endl;
            }
            break;
            case 3:
            {
                std::cout << "4:将一个C字符串的部分追加到此字符串" << std::endl;
                char another[] = "hello";
                std::cout << "char another[] = \"hello\"" << std::endl;
                std::cout << "str.append(another, 3) :" << std::endl;
                str.append(another, 3);
                std::cout << str << std::endl;
            }
            break;
            case 4:
            {
                std::cout << "5:追加多个字符。" << std::endl;
                std::cout << "str.append(3, '!') :" << std::endl;
                str.append(3, '!');
                std::cout << str << std::endl;
            }
            break;
            case 5:
            {
                std::cout << "6:从初始化列表追加" << std::endl;
                std::cout << "str.append({'!', '!', '!'}) :" << std::endl;
                str.append({'!', '!', '!'});
                std::cout << str << std::endl;
            }
            break;
            case 6:
            {
                std::cout << "7:将一个字符范围内的字符追加到此字符串" << std::endl;
                std::string another = "hello";
                std::cout << "std::string another = \"hello\"" << std::endl;
                std::cout << "str.append(another.begin(), another.end()) :" << std::endl;
                str.append(another.begin(), another.end());
                std::cout << str << std::endl;
            }
            break;
            case 7:
            {
                std::cout << "8:追加单个字符" << std::endl;
                std::cout << "str.push_back('!') :" << std::endl;
                str.push_back('!');
                std::cout << str << std::endl;
            }
            break;
            default:
                break;
            }
        }
        return 0;
    }
}