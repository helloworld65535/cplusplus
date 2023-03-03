#include <iostream>
#include <thread>
#include <atomic>

void increment(std::atomic<int> &number)
{
    for (int i = 0; i < 500; i++)
    {
        int num = ++number;
        printf("[increment]:%d\n", num);
    }
}

void decrement(std::atomic<int> &number)
{
    for (int i = 0; i < 500; i++)
    {
        int num = --number;
        printf("[decrement]:%d\n", num);
    }
}

int main(void)
{
    std::atomic<int> number = 0;
    // std::ref 引用传递
    std::thread thread_in(increment, std::ref(number));
    std::thread thread_de(decrement, std::ref(number));
    thread_in.join();
    thread_de.join();

    return 0;
}