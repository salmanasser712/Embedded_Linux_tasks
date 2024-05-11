#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdint>


class Person{
    public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;

    std::string name;
    std::uint16_t age;
    
};



#endif