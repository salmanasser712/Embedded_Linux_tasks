#include <iostream>
#include "Car.h"
#include "v8Engine.h"
#include "v7Engine.h"

Car::Car(std::unique_ptr<Engine>&& engine_version): engine(std::move(engine_version))
{
 std::cout << "Constructor is working\n";
}

void Car::Drive()
{
    engine->StartEngine();
}

void Car::Stop()
{
    engine->StopEngine();
}

int main()
{
    auto engine_v7 = std::make_unique<v7Engine>();
    Car MiniCoper(std::move(engine_v7)); 
    MiniCoper.Drive();

    Car BMW(MakeV8Engine());
    BMW.Drive();
    BMW.Stop();
    return 0;
}



