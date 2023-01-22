#include <iostream>

#include <vector>
int main(void)
{
    std::vector<int> arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i * 2);
    }
    for (auto i : arr)
    {
        std::cout << i << " ";
    }

    int target = 0;
    std::cin>>target;
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (target <= arr[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    std::cout << std::endl
              << "left:" << arr[left] << std::endl
              << "right:" << arr[right] << std::endl;
    return 0;
}