// #include <iostream>
// #include <list>


// void Create(std::list<int> data){
//     data.emplace_back(10);
//     data.emplace_back(20);
// }

// void Total(std::list<int> data){
//     if(data.empty()){
//         throw std::invalid_argument("empty");
//     }

//     float tot{0.0f};

//     for(int val : data){
//         tot+= val;
//     }

//     std::cout<<"Total : "<<tot<<"\n";
// }

// void FirstEle(std::list<int> data){
//     if(data.empty()){
//         throw std::invalid_argument("empty");
//     }

//     std::cout<<data.front();
// }

// int main(){
//     std::list<int> data{};
//     Create(data);
//     Total(data);
//     FirstEle(data);
// }

////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

/*
Magic
                                         heap emp
ptr[0* 100H]---------------->  [101  |    ANju    |  9000.0f]
//////////
 
voidMagic (){
Employee* ptr = new Employee(101. "Anju", 9000.0f);
if(condition){
std::cout<<*ptr<<"\n";
delete ptr;
}
else
}
 
 
resoruces in prgramming is - memory, file or some input , in this case memory
owner - the object that claims resource  in this case : ptr
 
RAII class -  take resource put it into wrapper  . owner gets deleted as destructor
If you want to acquire a resource - do this by constructing the owner object , similalry want or deallocate this will happen
when owner is deleted by destructing (in destrutor we call delete to delete the owner)
 
 
unique pointer is a wrapper class and follows raii class
*/
 
#include <iostream>
#include <list>
 
void CreateData(int* data){
 
data[0]=10;
data[1]=20;
}
 
void CaluclateTotal(int* data, int size){
    
    float total {0.0f};
    for (int i =0;i<size;i++){
        total += data[i];
    }
    std::cout<< "total is:"<< total <<"\n";
}
 
    void PrintFirstElement(int* data, int size){
 
std::cout<<data[0];
    
}
 
 
int main(){
//std::list<int> data{};
 
int* arr = new int[2];
CreateData(arr);
CaluclateTotal(arr,2);
PrintFirstElement(arr,2);
 
}