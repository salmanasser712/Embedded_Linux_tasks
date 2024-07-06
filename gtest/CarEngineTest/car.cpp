#include "car.h"
#include "IEngine.h"

Car::Car(){}

Car::Car(std::shared_ptr<IEngine> engine) : m_engine(engine)
{
}

Car::~Car()
{
    m_engine->Stop();
}

void Car::Drive()
{
    m_engine->Start();
    //Drive
}
void Car::Stop()
{
    m_engine->Stop();
}

std::shared_ptr<IEngine> Car::getEngineInstance()
{
    return m_engine;
}  
