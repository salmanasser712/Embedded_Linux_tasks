#include <iostream>
#include <stdint.h>

struct Fruit
{
    public:

    //default constructor
    Fruit() : price_kg(0), mWeight(0)
    {
    }

    //Parameterized constructor : initializer list
   Fruit(uint16_t price, uint16_t weight) : price_kg(price), mWeight(weight)
    {
        //do something
    }

    void setPrice(uint16_t price)
    {
        this->price_kg = price;
    }

    uint16_t getPrice()
    {
        return this->price_kg;
    }
    uint16_t getWeight()
    {
        return this->mWeight;
    }

    void setWeight(uint16_t weight)
    {
        this->mWeight = weight;
    }

    uint16_t getTotalPrice()
    {
        return this->mWeight * this->price_kg;
    }

    ~Fruit(){
        std::cout << "Object deleted\n";
    }

private:
    uint16_t price_kg;
    uint16_t mWeight;
    uint16_t total_price;

};

int main()
{
    Fruit orange(10, 10); 
    Fruit Apple;

    Apple.setPrice(7);
    Apple.setWeight(10);
    std::cout << "Apple Total price " << Apple.getTotalPrice() << std::endl;
    std::cout << "Total price " << orange.getTotalPrice() << std::endl;


    return 0;
}