#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int x = 5;

struct Fruit{
    double price;
    double weight;
    std::string name;
    void Buy(){
        std::cout << "Price Of " << name << ": " << price * weight << std::endl;
    }
};

void Buy(Fruit fruit){
    std::cout << "Price Of " << fruit.name << ": " << fruit.price * fruit.weight << std::endl;
}

void Buy(Fruit* fruit){
    std::cout << "Price Of " << fruit->name << ": " << fruit->price * fruit->weight << std::endl;
}

int main()
{   
    Fruit Orange;
    Orange.Buy();
    Orange.name = "Orange";
    Orange.price = 15;
    Orange.weight = 5;

    //Orange.Buy();

    Fruit Banana;
    Banana.name = "Banana";
    Banana.price = 10;
    Banana.weight = 2;

    Buy(Banana);

    return 0;
}
