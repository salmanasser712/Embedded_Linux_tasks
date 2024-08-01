#ifndef A_STRUCT_H
#define A_STRUCT_H

#include<string>

struct A
{
    std::string s;
    A() = default;
 
    A(std::string str) : s(std::move(str)) {}
 
    A(const A& o) : s(o.s) {}
 
    A(A&& o) : s(std::move(o.s)) { }

    std::string get_str() {return s;}
 
    A& operator=(const A& other)
    {
        s = other.s;
        return *this;
    }
 
    A& operator=(A&& other)
    {
        s = std::move(other.s);
        return *this;
    }
};

#endif