#include <iostream>

template<class T>
class SmartPtr{
    public:

    SmartPtr(T *ptr=nullptr) : p(ptr){
        p = new T;
    }

    T& operator*(){
        return *p;
    }

    ~SmartPtr(){
        delete p;
    }

    private:
    T *p;
};

int main(){
    SmartPtr<int> smart;
    *smart = 10;
    std::cout << "value = " << *smart << "\n";
}