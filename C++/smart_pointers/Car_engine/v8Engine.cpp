#include "v8Engine.h"
#include <iostream>

void v8Engine::StartEngine(){
    std::cout << "Starting v8 Engine\n";
}

void v8Engine::StopEngine(){
    std::cout << "Stopping v8 Engine\n";
}

std::unique_ptr<Engine> MakeV8Engine()
{
    return std::make_unique<v8Engine>();
}