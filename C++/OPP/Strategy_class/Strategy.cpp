#include<iostream>

class IStrategy{
    public:
    virtual void calculateSpeed() = 0;
};

class StrategyBMW : public IStrategy{
    public:
    void calculateSpeed() override{
        std::cout << "BWM Strategy\n";
    }
};

class StrategyMini : public IStrategy{
    public:
    void calculateSpeed() override{
        std::cout << "Mini Coper Strategy\n";
    }
};

class Vehicle {
    public:
    Vehicle(IStrategy * p_strategy): strategy(p_strategy){

    }

    void VehicleSpeed(){
        strategy->calculateSpeed();
    }

    private:
    IStrategy *strategy;
};

int main(){
    Vehicle BWM_car(new StrategyBMW());
    BWM_car.VehicleSpeed();

    Vehicle Mini_car(new StrategyMini());
    Mini_car.VehicleSpeed();

    return 0;
}