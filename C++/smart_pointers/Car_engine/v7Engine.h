#ifndef V7ENGINE_H
#define V7ENGINE_H

#include "Engine.h"
#include <iostream>

class v7Engine : public Engine{
    void StartEngine() override{
        std::cout << "Starting v7 Engine\n";
    }
    void StopEngine() override{
        std::cout << "Stopping v7 Engine\n";
    }
};

#endif