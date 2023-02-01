#include <iostream>
#include <typeinfo>

int main(void)
{
    int i;
    std::cout<<typeid(i).name()<<std::endl;
    
    return 0;
}
