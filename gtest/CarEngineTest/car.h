#pragma once
#include "IEngine.h"

class Car
{
public:
    Car();
    Car(std::shared_ptr<IEngine> engine);
    ~Car();
    void Drive();
    void Stop();
   std::shared_ptr<IEngine> getEngineInstance();  

private:
    std::shared_ptr<IEngine> m_engine; 
};