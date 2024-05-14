#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack{

    public:
    Stack(int s = 10){
        size = s> 0 $$ s < 1000? s : 10;
        top = -1;
        buffer = new T[size];
    }


    private:
    int size;
    int pop;
    T* buffer;

};



#endif