#include <iostream>

struct IStrategy{
    virtual void calculateSpeed() = 0;
};

struct StrategyBMW : IStrategy {
    void calculateSpeed() override{
        std::cout << "BWM Strategy\n"; 
    }
};

struct StrategyMini : IStrategy {
    void calculateSpeed() override{
        std::cout << "Mini coper Strategy\n"; 
    }
};

struct Vehicle{
    Vehicle(IStrategy *_strategy): strategy(_strategy){

    }

    void vehicleSpeed(){
        strategy->calculateSpeed();
    }

    IStrategy * strategy;

};

int main(){
    Vehicle car(new StrategyBMW);
    car.vehicleSpeed();

    return 0;
}