#include <string>
#include <iostream>

namespace Constructor
{
    int main()
    {
        // Ĭ�Ϲ��캯������һ�����ַ���
        std::cout << "1:Ĭ�Ϲ��캯������һ�����ַ���" << std::endl;
        std::cout << "std::string() :" << std::string() << std::endl;
        // ʹ��__strֵ�ĸ��������ַ���
        std::cout << "2:ʹ��__strֵ�ĸ��������ַ���(��������)" << std::endl;
        std::string str2 = "copy";
        std::cout << "����������std::string str2=\"copy\"" << std::endl;
        std::cout << "std::string(str2) :" << std::string(str2) << std::endl;
        // �����ַ�����Ϊ���ַ����ĸ���
        std::cout << "3:�����ַ�����Ϊ���ַ����ĸ���" << std::endl;
        std::string str3 = "Source";
        std::cout << "Դ�ַ���std::string str3=\"Source\"" << std::endl;
        std::cout << "std::string(str3, 2)) :"
                  << std::string(str3, 2) << std::endl;
        // �����ַ�����Ϊ���ַ����ĸ���
        std::cout << "4:�����ַ�����Ϊ���ַ����ĸ���" << std::endl;
        std::string str4 = "Source";
        std::cout << "Դ�ַ���std::string str4=\"Source\"" << std::endl;
        std::cout << "std::string(str3, 2, 2) :"
                  << std::string(str3, 2, 2) << std::endl;

        // �������ַ������ʼ�����ַ���
        std::cout << "5:�������ַ������ʼ�����ַ���" << std::endl;
        char arr5[] = "char \0 array";
        std::cout << "�ַ�����::schar arr5[]=\"char array\"" << std::endl;
        std::cout << "std::string(arr5) :"
                  << std::string(arr5) << std::endl;
        // �������ַ������ʼ�����ַ���
        std::cout << "6:�������ַ������ʼ�����ַ���" << std::endl;
        char arr6[] = "char \0 array";
        std::cout << "�ַ�����::schar arr6[]=\"char array\"" << std::endl;
        std::cout << "std::string(arr6,10) :"
                  << std::string(arr6, 10) << std::endl;
        // ���ַ�������Ϊ����ַ�
        std::cout << "7:���ַ�������Ϊ����ַ�" << std::endl;
        std::cout << "std::string(6,'H') :"
                  << std::string(6, 'H') << std::endl;
        // �ƶ������ַ�����
        std::cout << "8:�ƶ������ַ�����" << std::endl;
        std::cout << "std::string(std::to_string(123456)) :"
                  << std::string(std::to_string(123456)) << std::endl;
        // �ӳ�ʼ��ʽ�б����ַ�����
        std::cout << "9:�ӳ�ʼ��ʽ�б����ַ�����" << std::endl;
        std::cout << "std::string({'h', 'e', 'l', 'l', 'o'}) :"
                  << std::string({'h', 'e', 'l', 'l', 'o'}) << std::endl;
        // �����ַ�����Ϊ��Χ�ĸ�����
        std::cout << "10:�����ַ�����Ϊ��Χ�ĸ�����" << std::endl;
        std::string str10 = "Source";
        std::cout << "Դ�ַ���std::string str10=\"Source\"" << std::endl;
        std::cout << "std::string(str10.begin(), str10.end()) :"
                  << std::string(str10.begin(), str10.end()) << std::endl;

        return 0;
    }

}
