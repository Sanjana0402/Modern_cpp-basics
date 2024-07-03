#include <iostream>
#include <thread>
#include <mutex>
#include <list>

// Singleton : A class which can be instantiated only once i.e only one object of the class can be present at any point in the app

using ThreadContainer = std::list<std::thread>;
class BankOperation
{
private:
    /* data */
    int32_t m_amt{1000};
    std::mutex mt;

    static BankOperation *m_instance_ptr;

    BankOperation(const BankOperation &) = delete;
    BankOperation(BankOperation &&) = delete;
    BankOperation &operator=(const BankOperation &) = delete;
    BankOperation &operator=(BankOperation &&) = delete;
    BankOperation() = default;

    BankOperation(int32_t val) : m_amt{val} {}

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

    // BankOperation(const BankOperation &) = delete;
    // BankOperation(BankOperation &&) = delete;
    // BankOperation &operator=(const BankOperation &) = delete;
    // BankOperation &operator=(BankOperation &&) = delete;
    // BankOperation() = default;

    // BankOperation(int32_t val) : m_amt{val} {}
    ~BankOperation() = default;

    int32_t amt() const { return m_amt; }

    void setAmt(const int32_t &amt) { m_amt = amt; }

    static BankOperation *GetInstance(int val)
    {
        if (m_instance_ptr)
        {
            m_instance_ptr->setAmt(val);
            return m_instance_ptr;
        }
        else
        {
            m_instance_ptr = new BankOperation(val);
            return m_instance_ptr;
        }
    }
};

BankOperation *BankOperation::m_instance_ptr{nullptr};

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

    BankOperation *ptr = BankOperation::GetInstance(50000);

    ThreadContainer threads{}; // blank list of threads
    CreateThreads(threads, *ptr);

    // std::thread t1{&BankOperation::Deposit, &b1};
    // std::thread t2{&BankOperation::withDraw, &b1};

    // t1.join();
    // t2.join();

    JoinThreads(threads);

    DisplayFinalAmt(*ptr);

    delete ptr;
}