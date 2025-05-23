/*
    objective : I want to write an "Adaptor" function which will accept

    a) vector of integer 32 bit numbers
    b) a function that accepts a single integer 32 value and returns void 

    Adaptor should 'map' function provided onto the data provided
*/
#include<iostream>
#include<vector>

void Square (int32_t number){
    std::cout << number * number << "\n";
}

void Cube(int32_t number){
    std::cout << number * number * number << "\n";
}

void Adaptor( 
    void (*fn) (int32_t number) , 
    std::vector<int32_t>& data  
    ){

        for (int32_t val : data){
            (* fn)(val);
        }
    }

int main(){
    // int n1 = 10;
    // int* ptr = &n1;

    // function ka pointer -----> address of a function

//     void (*ptr)(int32_t) = &Square;

//     void (*temp)(int32_t number) = &Cube;

//     (*temp)(10);//call cube function as cube (10)
//     (*ptr)(9);// square function as square(9)


std::vector <int32_t> data{1,2,3,4,5};
Adaptor(&Cube, data );
Adaptor(&Square, data );



//if user wants they login the can design their own function and use its
//logic to proccesss "data"

}