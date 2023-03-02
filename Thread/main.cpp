#include <thread>
#include <iostream>

void func(std::string name)
{
     for (int i = 0; i < 10; i++)
     {
          std::cout << "[" << name << "]:"
                    << "i=" << i + 1 << std::endl;
          // 休眠线程
          std::this_thread::sleep_for(std::chrono::milliseconds(200));
     }
     std::cout << "[" << name << "]:END" << std::endl;
}

void func()
{
     for (int i = 0; i < 10; i++)
     {
          std::cout << "[_id:" << std::this_thread::get_id() << "]:"
                    << "i=" << i + 1 << std::endl;
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
     }
     std::cout << "[_id:" << std::this_thread::get_id() << "]:END" << std::endl;
}

int main(void)
{
     // main 函数是主线程
     std::cout << "Main thread Id :"
               << std::this_thread::get_id()
               << std::endl;

     // 返回一个值，该值提示硬件线程上下文的数量。
     unsigned int num = std::thread::hardware_concurrency();
     std::cout << "CPU number: " << num << std::endl;

     // 有多个重载的函数用强制转换指定
     std::thread t2((void (*)())func);

     void (*p1)(std::string) = &func;
     std::thread t1(p1, "name"); // 子线程函数传入参数包

     // 等待子线程 t1,t2 结束
     /*
          join      加入式：主线程阻塞 等待子线程的结束
          detach    分离式：子线程分离，直到运行结束
     */
     t1.join();
     t2.join();
     return 0;
}