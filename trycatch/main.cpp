#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string str="3.1415926";
    try
    {
        double d=stod(str);
        cout<<d<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}