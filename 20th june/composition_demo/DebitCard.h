#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <iostream>
#include "DebitCardType.h"

class DebitCard
{
private:
    short m_card_cvv{-1};
    std::string m_card_expiry_date{""};
    long long m_card_number{0};
    DebitCardType m_card_type{};
public:
    DebitCard() = default;
    
    DebitCard(short cvv, std::string expiryDate, long long cardNumber, DebitCardType cardType);
    
    ~DebitCard() = default;

    DebitCard(const DebitCard& other)=delete;
    DebitCard& operator=(const DebitCard& other)=delete;
    DebitCard(DebitCard&& other)=delete;
    DebitCard& operator=(DebitCard&& other)=delete;

    DebitCardType cardType() const { return m_card_type; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
