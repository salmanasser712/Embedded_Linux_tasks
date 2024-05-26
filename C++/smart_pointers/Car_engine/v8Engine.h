#ifndef V8ENGINE_H
#define V8ENGINE_H

#include "Engine.h"
#include <memory>

class v8Engine: public Engine{
    void StartEngine()override;
    void StopEngine()override;
};

std::unique_ptr<Engine> MakeV8Engine();

#endif