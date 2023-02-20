#include <string>
#include <iostream>

namespace Assign
{
    int main(void)
    {
        std::string str;
        // ��value����Ϊ��һ���ַ���������(����)
        std::cout << "1:��value����Ϊ��һ���ַ���������(����)" << std::endl;
        std::string another = "another";
        std::cout << "std::string another = \"another\"" << std::endl;
        std::cout << "str.assign(another):" << std::endl;
        str.assign(another);
        std::cout << str << std::endl;
        // ��value����Ϊ��һ���ַ���������(��ֵ����)
        std::cout << "2:��value����Ϊ��һ���ַ���������(��ֵ����)" << std::endl;
        std::cout << "str.assign(std::to_string(3.14)):" << std::endl;
        str.assign(std::to_string(3.14));
        std::cout << str << std::endl;
        // ��value����Ϊ�ַ��������ַ���
        std::cout << "3:��value����Ϊ�ַ��������ַ���" << std::endl;
        std::string another3 = "another";
        std::cout << "std::string another3 = \"another\"" << std::endl;
        std::cout << "str.assign(another3, 2):" << std::endl;
        str.assign(another3, 2);
        // ��value����Ϊ�ַ��������ַ���
        std::cout << "4:��value����Ϊ�ַ��������ַ���" << std::endl;
        std::string another4 = "another";
        std::cout << "std::string another4 = \"another\"" << std::endl;
        std::cout << "str.assign(another4,2,5):" << std::endl;
        str.assign(another4, 2, 5);
        std::cout << str << std::endl;
        // ��value����ΪC�ַ��������ַ���
        std::cout << "5:��value����ΪC�ַ��������ַ���" << std::endl;
        char another5[] = "another";
        std::cout << "char another5[] = \"another\"" << std::endl;
        std::cout << "str.assign(another5, 2):" << std::endl;
        str.assign(another5, 2);
        std::cout << str << std::endl;
        // ��value����ΪC�ַ���
        std::cout << "6:��value����ΪC�ַ���" << std::endl;
        char another6[] = "another";
        std::cout << "char another6[] = \"another\"" << std::endl;
        std::cout << "str.assign(another6):" << std::endl;
        str.assign(another6);
        std::cout << str << std::endl;
        // ��value����Ϊ����ַ�
        std::cout << "7:��value����Ϊ����ַ�" << std::endl;
        std::cout << "str.assign(6,'!'):" << std::endl;
        str.assign(6, '!');
        std::cout << str << std::endl;
        // ��value����Ϊĳ����Χ�ڵ��ַ�
        std::cout << "8:��value����Ϊĳ����Χ�ڵ��ַ�" << std::endl;
        std::string another7 = "another";
        std::cout << "std::string another7 = \"another\"" << std::endl;
        std::cout << "str.assign(another7.begin(), another7.end()):" << std::endl;
        str.assign(another7.begin(), another7.end());
        std::cout << str << std::endl;

        return 0;
    }
}