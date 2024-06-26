#include <iostream>
#include <memory>

class GasolineSource {
public:
    virtual void FuelUp() = 0;
    virtual ~GasolineSource() = default;
};

class GasStation : public GasolineSource {
public:
    void FuelUp() {
        std::cout << "Pumping gas at gas station" << std::endl;
    }
};

class FuelCan : public GasolineSource {
public:
    void FuelUp() {
        std::cout << "Pumping gas from fuel can" << std::endl;
    }
};

class Car {

private:
    std::unique_ptr<GasolineSource> gasolineService = nullptr;

public:
    //dependency injection
    // The dependency for a source of gasoline is passed in
    // through constructor injection
    // as opposed to hard-coded into the class definition.
    Car(std::unique_ptr<GasolineSource> && service)
    : gasolineService(std::move(service)) {
        // If the dependency was not defined, throw an exception.
        if(gasolineService == nullptr){
            throw std::invalid_argument("service must not be null");
        }
    }
    void getGasoline() {
        std::cout << "Car needs more gasoline!" << std::endl;
        // Abstract away the dependency implementation with polymorphism.
        gasolineService->FuelUp();
    }
};

int main() {
    std::unique_ptr<GasStation> gas = std::make_unique<GasStation>();
    std::unique_ptr<FuelCan> fuel = std::make_unique<FuelCan>();

    // racecar is independent from the implementation of the fuel service.
    // a gas station service is injected.
    Car racecar(std::move(gas));
    racecar.getGasoline(); 

    // dune buggy is independent from the implementation of the fuel service.
    // a fuel can service is injected.
    Car duneBuggy(std::move(fuel));
    duneBuggy.getGasoline();
    
    return 0;
}