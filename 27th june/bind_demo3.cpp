#include <iostream>
#include <functional>

class Data
{
private:
    /* data */
    int m_value;

public:
    Data() = default;

    Data(const Data &) = delete; // copy construuctor

    Data &operator=(const Data &) = delete; // copy assignment operator

    Data(Data &&) = delete; // move constructor

    Data &&operator=(Data &&) = delete; // move assignment operator


    ~Data() = default;

    Data(int val) : m_value{val} {}

    void Display(int factor)
    {
        std::cout << m_value * factor << "\n";
    }

    static void DisplayMsg(int times){
        std::cout<<"Hello World"<< times << "times\n";
    }
};

int main()
{

    Data obj{18};

    obj.Display(100);

    auto fn = std::bind(&Data::Display, &obj, 100);

    fn();

    Data::DisplayMsg(10);//"Hello world" 10 times printed

    auto binded_static = std::bind(Data::DisplayMsg,10);

    binded_static();//DisplayMsg(10)

}

/*

    For non-static member functons
    a) object address is mandatory
    b) It must be the first argument after specifying the name of the function in bind
    c) You "must" use & symbol with the name of the vmember function in bind

    for static member functions
    a) No object involved so no address required
    b) You "SHOULD NOT" use & symbol with the name of the function

*/