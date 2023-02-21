#include <iostream>

int main()
{
    int count = 10;
    const int &countRef = count;
    auto myAuto = countRef; // int myAuto=countRef;
    
    std::cout << "&count=\t" << &count << std::endl;
    std::cout << "&countRef=\t" << &countRef << std::endl;
    std::cout << "&myAuto=\t" << &myAuto << std::endl;

    return 0;
}