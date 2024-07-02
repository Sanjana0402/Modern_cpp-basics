// RAII : Resource Acquisition Is Inialization Principle

/*
    Resource

        memory
        open files
        network connection

*/

#include<iostream>

class ABC
{
private:
    /* data */
    int m_id{0};
    float* m_valueptr{nullptr};
public:
    ABC() =  default;
    ABC(int id,float* ptr):m_id{id},m_valueptr{ptr} {}

    ABC(const ABC& other)=delete;
    ABC& operator=(const ABC& other)=delete;
    ABC(ABC&& other)=delete;
    ABC& operator=(ABC&& other)=delete;

    ~ABC() {
        delete m_valueptr;//memory leakage prevented
    }
};

template <typename T>
class Wrapper
{
private:
    T* m_ptr; /* data */
public:
    Wrapper(T* ptr /* args */) : m_ptr{ptr}{};

    ~Wrapper(){
        delete m_ptr;
    }
};


void Magic(){
    Wrapper<ABC> wr_obj{new ABC {101,new float{200.f}}};
}

int main(){
    Magic();
}

/*
    1) Main calls Magic() 
    2) In Magic function we create wr_obj (stack memory) 
    3) wr_obj stores the address of the heap allocated ABC object 
    4) wr_obj goes out of scope at the end of Mahic function. Since wr_obj is a stack allocated variable, 
    it will get auto destructed. Destructor of Wrapper<ABC> class will be called. 
    5) Wrapper class destructor will call delete on the stored pointer for ABC. which will indirectly also delete it
*/