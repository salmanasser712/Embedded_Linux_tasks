#ifndef ENGINE_H
#define ENGINE_H

class Engine{
    public:
    virtual void StartEngine() = 0;
    virtual void StopEngine() = 0;
    virtual ~Engine() = default;
};



#endif