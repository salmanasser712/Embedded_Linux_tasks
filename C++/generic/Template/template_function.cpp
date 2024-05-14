#include <iostream>

//template functions

template<typename type>

type max(type n1, type n2){
    return n1 > n2? n1: n2;
}

template<class T>
void swap(T& first, T& second){
    T temp = first;
    first = second;
    second = temp;
}


int main(){
    int first = 7;
    int second = 5;

    double n1 = 0.5;
    double n2 = 7.15;

    std::cout << "max is " << max(first, second) << std::endl;
    std::cout << "max is " << max(n1, n2) << std::endl;

}
