#include "Functionalities.h"

void CreateObjects(Container& accounts)
{
    accounts.emplace_back 
    (
        new BankAccount
        (101, 
        "XYZ", 
        8990.0f, 
        BankAccountType::SAVINGS, 
        new DebitCard
        (111, 
        "19/12", 
        111122345673444, DebitCardType::MASTERCARD))
    );
    accounts.emplace_back 
    (
        new BankAccount
        (102, 
        "ABC", 
        9870.0f, 
        BankAccountType::SAVINGS, 
        new DebitCard
        (167, 
        "16/12", 
        124356223333444, DebitCardType::DINERSCLUB))
    );
    accounts.emplace_back 
    (
        new BankAccount
        (103, 
        "MNO", 
        78654.0f, 
        BankAccountType::SAVINGS, 
        new DebitCard
        (198, 
        "15/11", 
        11119876543444, DebitCardType::VISA))
    );
}


/*
    A function to find and display the details of debitcard for account whose number is provided as parameter
*/


void DisplayCardDetails(const Container& accounts, const long number){
    
    bool flag {false};
    for(const BankAccount* b : accounts) {
        if ( b->accountNumber() == number   ) {
            std::cout << b->attachedCard() << "\n";
            true;
            break;
        }
    }

    if (!flag){
        throw AccountNotFoundException("Invalid number");
    }
}

/*
    Find and display the count of DebitCard with type = VISA
*/


void CountVISACards(const Container& accounts){
    unsigned int count = 0;
    for(const BankAccount* b:accounts) {

        /*
            if i position account fetches debitcard and then checks type of debit
            card and it is VISA, increase count by 1
        */
        if (b->attachedCard()->cardType() == DebitCardType::VISA){
            count++;
        }
    }

    std::cout << "Count is: " << count << "\n";
}

void DeallocateMemory(Container &accounts)
{
    for(BankAccount* b:accounts){
        delete b;
    }
}
