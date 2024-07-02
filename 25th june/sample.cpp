/*
    create adaptor which accepts

    a) a data container of string values
    b) a function with the following signature
        - input parameter : one string by lvalue reference
        - output : void

    Adaptor should used to perform operations on string values which are

        - identify vowels
        - print the last 3 characters of each string
        - print the first non-vowel character of each string

*/

#include <iostream>
#include <functional>
#include <vector>

using Logic = std::function<void(const std::string&)>;
using DataContainer = std::vector<std::string>;

void Adaptor(const Logic fn,const DataContainer& data )
{
    if(data.empty()){
        std::invalid_argument("Data is empty\n");
    }
    for(const std::string& st : data){
        fn(st);
    }
}

void findVowels(const std::string& val){
    if(val == " "){
        std::cerr<<"No string found\n";
        return;
    }
    
    bool flag{false};
    for(char c : val){
        if ( c=='A' || c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O' ||c=='o'||c=='U'||c=='u'){
            flag = true;
            std::cout<<c<<"\n";
        }
    }

    if(!flag){
        std::cerr<<"No vowels found\n";
    }
}

int main()
{
    std::vector<std::string> data1{" ","abc","xyz","mno"};
    // std::vector<std::string> data2{" "," "," "," "};
    // std::vector<std::string> data3{};

    try
    {   
        Adaptor(&findVowels,data1);
        // Adaptor(&findVowels,data2);
        // Adaptor(&findVowels,data3);
    }
    catch(std::invalid_argument& e)
    {
        std::cerr<<e.what()<<"\n";
    }

    std::cout<<"\n\nNo of spacings : ";

    Adaptor([](const std::string& st) {std::cout << st.length();},data1);

    std::cout<<"\n\n";
}