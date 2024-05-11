#include "Person.h"
#include <iostream>
#include <cmath>
#include <cstdint>



class Professor : public Person{
    public:
    Professor():curr_id{1}{}

    static int p_id;

    void getdata() override{
        std::cin >> name >> age >> publications;
        curr_id = ++p_id;
    }

    void putdata() override{
        std::cout << name << " " << age << " " << publications << " " << curr_id << " \n";
    }


    private:
    std::uint16_t curr_id;
    std::uint16_t publications;
};

int Professor:: p_id = 0;

class Student : public Person{
    public:
    Student(){}

    void getdata() override{
        std:: cin >> name >> age;
        for(auto &mark: marks){
            std::cin >> mark;
        }
        curr_id = ++s_id;
    }

    void putdata() override{
        std::uint16_t sum = 0;
        for(auto &mark: marks){
            sum += mark;
        }
        std::cout << name << " " << age << " " << sum << " " << curr_id << "\n"; 
    }

    std::uint16_t curr_id{2};
    std::uint16_t marks[6];
    static int s_id;
};

int Student:: s_id = 0;

int main(){
    int n, val;
    std::cin >> n;
    Person *per[n];

    for(int i = 0; i < n; i++){
        std::cin >> val;
        if(val == 1){
            per[i] = new Professor;
        }
        else{
            per[i] = new Student;
        }
        per[i]->getdata();
    }

    for(int i = 0; i < n; i++){
        per[i]->putdata();
    }
}