#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include <memory>

class Car{
    public:
    Car(std::unique_ptr<Engine>&& engine_version);
    void Drive();
    void Stop();

    private:
    std::unique_ptr<Engine> engine;
};

#endif