#include<iostream>
#include<vector>

enum class Rating{
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_RATING
};

class Car
{
private:
    /* data */
    unsigned int m_id{0};
    float m_price{0.0f};
    Rating m_safetyRating{Rating::_NO_RATING};
public:
     Car(unsigned int id):m_id{id}{

    }
     Car(unsigned int id,float price):Car(id){
        m_price = price;
    }

    Car(unsigned int id,float price, Rating rate):Car(id,price){
        m_safetyRating = rate;
    }

    Car() = delete;
    Car(const Car&) = default;//copy constructor
    Car& operator=(const Car&)= delete;// copy assignment operator
    Car& operator=(Car&&)= delete;// move assignment operator
    Car(Car&&)= default;//move constructor
    ~Car()= default ;
};

int main(){
    Car c1(101,340000.f,Rating::_4_STAR);
    Car c2(102,670000.f,Rating::_3_STAR);

    // int32_t n1 = 10; //32 bits/4 bytes memory for integer
    // int16_t n2 = 20; //16 bits/2 bytes memory for integer
    // _Float32x n3 = 7.8f;

    std::vector<Car> cars{c1,c2};//enable copy constructor

    //move constructor / moving cars(not applicable in this context)

    //Create data inside the vector directly(emplacing)

    // std::vector<Car> cars;
    cars.emplace_back(101,340000.f,Rating::_4_STAR);
    cars.emplace_back(102,670000.f,Rating::_3_STAR);

    //prevent extra memory utilization

    std::cout<<"Number of elements in  the vector currently: "<<cars.size() <<"\n";




}