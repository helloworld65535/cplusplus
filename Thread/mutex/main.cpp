#include <iostream>
#include <thread>
#include <mutex>

namespace Mutex
{
    void download(int *progress, std::mutex *mutex)
    {
        auto id = std::this_thread::get_id();
        while (*progress < 10000)
        {
            mutex->lock();
            ++*progress;
            printf("[ID%d]:%d\n", id, *progress);
            mutex->unlock();
        }
    }

    int main(void)
    {
        int progress = 0;
        // �������������߳̽�����������֮�������߳̽��ȴ� ֱ�����⿪
        std::mutex mutex;
        std::thread t1(download, &progress, &mutex);
        std::thread t2(download, &progress, &mutex);
        std::thread t3(download, &progress, &mutex);
        t1.join();
        t2.join();
        t3.join();
        std::cout << "download:" << progress << std::endl;
        return 0;
    }
}
namespace lock_guard
{
    void download(int *progress, std::mutex *mutex)
    {
        auto id = std::this_thread::get_id();
        while (*progress < 10000)
        {

            // lock_guard ����ʵ������ mutex ���������ϣ�ֱ�����ͷź� ����
            std::lock_guard<std::mutex> lock(*mutex);
            ++*progress;
            printf("[ID%d]:%d\n", id, *progress);
        }
    }
    int main(void)
    {
        int progress = 0;
        // �������������߳̽�����������֮�������߳̽��ȴ� ֱ�����⿪
        std::mutex mutex;

        std::thread t1(download, &progress, &mutex);
        std::thread t2(download, &progress, &mutex);
        std::thread t3(download, &progress, &mutex);
        t1.join();
        t2.join();
        t3.join();
        std::cout << "download:" << progress << std::endl;

        return 0;
    }
}

namespace recursive_mutex
{
    struct Calculate
    {
        Calculate() : m_i(6) {}

        void mul(int x)
        {
            // recursive_mutex ���ᱻͬһ���̷߳�������
            m_mutex.lock();
            m_i *= x;
            m_mutex.unlock();
        }

        void div(int x)
        {
            m_mutex.lock();
            m_i /= x;
            m_mutex.unlock();
        }

        void both(int x, int y)
        {
            m_mutex.lock();
            mul(x);
            div(y);
            m_mutex.unlock();
        }

        int m_i;
        std::recursive_mutex m_mutex;
    };

    int main()
    {
        Calculate cal;
        cal.both(6, 3);
        std::cout << "cal.m_i = " << cal.m_i << std::endl;
        return 0;
    }
}

using namespace std;
timed_mutex g_mutex;
void work()
{
    chrono::seconds timeout(1);
    while (true)
    {
        // ͨ������һ����ʱ������ȡ�õ�����������Ȩ
        if (g_mutex.try_lock_for(timeout))
        {
            cout << "��ǰ�߳�ID: " << this_thread::get_id() 
                << ", �õ�����������Ȩ..." << endl;
            // ģ�⴦����������һ����ʱ��
            this_thread::sleep_for(chrono::seconds(10));
            // ����������
            g_mutex.unlock();
            break;
        }
        else
        {
            cout << "��ǰ�߳�ID: " << this_thread::get_id() 
                << ", û�еõ�����������Ȩ..." << endl;
            // ģ�⴦��������������һ����ʱ��
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
}

int main()
{
    thread t1(work);
    thread t2(work);

    t1.join();
    t2.join();

    return 0;
}

