#include <iostream>
#include <string>

namespace Append
{
    int main(void)
    {
        std::cout<<"str=\"hello world\""<<std::endl;
        // ���ַ�����ĩβ����ַ�
        for (int i = 0; i < 10; i++)
        {
            std::string str = "hello world";
            switch (i)
            {
            case 0:
            {
                std::cout << "1:��һ���ַ���׷�ӵ����ַ���" << std::endl;
                std::string another = "hello";
                std::cout << "std::string another = \"hello\"" << std::endl;
                std::cout << "str.append(another) :" << std::endl;
                str.append(another);
                std::cout << str << std::endl;
            }
            break;
            case 1:
            {
                std::cout << "2:��һ���ַ����Ĳ���׷�ӵ����ַ���" << std::endl;
                std::string another = "hello";
                std::cout << "std::string another = \"hello\"" << std::endl;
                std::cout << "str.append(another,1,4) :" << std::endl;
                str.append(another, 1, 4);
                std::cout << str << std::endl;
            }
            break;
            case 2:
            {
                std::cout << "3:��һ��C�ַ���׷�ӵ����ַ���" << std::endl;
                char another[] = "hello";
                std::cout << "char another[] = \"hello\"" << std::endl;
                std::cout << "str.append(another) :" << std::endl;
                str.append(another);
                std::cout << str << std::endl;
            }
            break;
            case 3:
            {
                std::cout << "4:��һ��C�ַ����Ĳ���׷�ӵ����ַ���" << std::endl;
                char another[] = "hello";
                std::cout << "char another[] = \"hello\"" << std::endl;
                std::cout << "str.append(another, 3) :" << std::endl;
                str.append(another, 3);
                std::cout << str << std::endl;
            }
            break;
            case 4:
            {
                std::cout << "5:׷�Ӷ���ַ���" << std::endl;
                std::cout << "str.append(3, '!') :" << std::endl;
                str.append(3, '!');
                std::cout << str << std::endl;
            }
            break;
            case 5:
            {
                std::cout << "6:�ӳ�ʼ���б�׷��" << std::endl;
                std::cout << "str.append({'!', '!', '!'}) :" << std::endl;
                str.append({'!', '!', '!'});
                std::cout << str << std::endl;
            }
            break;
            case 6:
            {
                std::cout << "7:��һ���ַ���Χ�ڵ��ַ�׷�ӵ����ַ���" << std::endl;
                std::string another = "hello";
                std::cout << "std::string another = \"hello\"" << std::endl;
                std::cout << "str.append(another.begin(), another.end()) :" << std::endl;
                str.append(another.begin(), another.end());
                std::cout << str << std::endl;
            }
            break;
            case 7:
            {
                std::cout << "8:׷�ӵ����ַ�" << std::endl;
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