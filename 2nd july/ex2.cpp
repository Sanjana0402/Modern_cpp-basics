#include <iostream>
#include <thread>
#include <mutex>

class MathOperation
{
private:
    /* data */
    std::mutex mt{};
    int32_t m_value{0};

public:
    MathOperation(const MathOperation &) = default;
    MathOperation(MathOperation &&) = delete;
    MathOperation &operator=(const MathOperation &) = delete;
    MathOperation &operator=(MathOperation &&) = delete;
    MathOperation() = default;
    MathOperation(int val) : m_value{val} {}
    ~MathOperation() = default;

    void Square()
    {

        mt.lock();
        std::cout << "ID : of the thread square : " << std::this_thread::get_id() << "\n";
        std::cout << "Square of "
                  << m_value << " is : "
                  << m_value * m_value;

        mt.unlock();
    }

    int32_t addition(int other)
    {

        mt.lock();
        std::cout << "ID : of the thread addition : " << std::this_thread::get_id() << "\n";
        mt.unlock();
        return m_value + other;
    };

    int64_t operator()()
    {

        mt.lock();
        std::cout << "ID : of the thread operator() : " << std::this_thread::get_id() << "\n";
        mt.unlock();
        return m_value * m_value * m_value;
    }
};

// an object that behaves like a function (can be invoked like a function)
// is called a "functor" object

int main()
{

    MathOperation m1{100};

    std::thread t1{&MathOperation::Square, &m1};

    /*
        you cannot capture return values from a function when executing
        them via std::thread
    */
    // MathOperation m1{100};

    std::thread t2{std::ref(m1)}; // thread created by a functor object
    std::thread t3{&MathOperation::addition, &m1, 100};

    // m1();
    t1.join();
    t2.join();
    t3.join();
}