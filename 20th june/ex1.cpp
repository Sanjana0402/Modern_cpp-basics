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

int main(){
    ABC obj{101,new float(200.f)};
}