

#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include <iostream>

class BusinessOwner{
    

    private:

std::string b_name{""};
float m_net_income{0.0f};

    public:

    BusinessOwner() = default;
    ~BusinessOwner()= default;
    BusinessOwner(const BusinessOwner&) = default;
    BusinessOwner(BusinessOwner&&)= delete;
    BusinessOwner& operator=(const BusinessOwner&) = default;
    BusinessOwner& operator=(BusinessOwner&&) = delete;

    BusinessOwner(std:: string name , float income)  : b_name{name} , m_net_income{income} {}

    friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
        os << "m_name: " << rhs.b_name
           << " m_net_income: " << rhs.m_net_income;
        return os;
    }

   void CalculateTaxAmount(){std::cout<<0.15f * m_net_income<<"\n";};

}
;



#endif // BUSINESSOWNER_H
