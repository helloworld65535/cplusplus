#include <iostream>
#include <array>

template <std::size_t _Nm>
void PrintArray(const std::array<int, _Nm> &arr)
{
     for (auto &&i : arr)
     {
          std::cout << i << " ";
     }
     std::cout << std::endl;
}

int main(void)
{
     std::array<int, 5> arr1{1, 2, 3, 4, 5};
     std::array<int, 4> arr2{1, 2, 3, 4};

     PrintArray(arr1);
     PrintArray(arr2);

     return 0;
}