#include <iostream>
#include <thread>
#include <mutex>
#include <list>

using ThreadContainer = std::list<std::thread>;
class BankOperation
{
private:
    /* data */
    int32_t m_amt{1000};
    std::mutex mt;

public:
    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amt += 10;
            mt.unlock();
        }
    }

    void withDraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amt -= 10;
            mt.unlock();
        }
    }

    BankOperation(const BankOperation &) = delete;
    BankOperation(BankOperation &&) = delete;
    BankOperation &operator=(const BankOperation &) = delete;
    BankOperation &operator=(BankOperation &&) = delete;
    BankOperation() = default;

    BankOperation(int32_t val) : m_amt{val} {}
    ~BankOperation() = default;

    int32_t amt() const { return m_amt; }

    void setAmt(const int32_t &amt) { m_amt = amt; }
};

void CreateThreads(ThreadContainer &threads, BankOperation &b1)
{
    threads.emplace_back(&BankOperation::Deposit, &b1);
    threads.emplace_back(&BankOperation::withDraw, &b1);
}

void JoinThreads(ThreadContainer &threads)
{
    for (std::thread &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

void DisplayFinalAmt(BankOperation &b1)
{

    std::cout << "Final answer : " << b1.amt() << "\n";
}

int main()
{

    BankOperation b1{50000};

    ThreadContainer threads{}; // blank list of threads
    CreateThreads(threads, b1);

    // std::thread t1{&BankOperation::Deposit, &b1};
    // std::thread t2{&BankOperation::withDraw, &b1};

    // t1.join();
    // t2.join();

    JoinThreads(threads);

    DisplayFinalAmt(b1);
}