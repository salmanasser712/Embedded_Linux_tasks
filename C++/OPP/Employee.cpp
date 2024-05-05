#include <iostream>
#include "Employee.h"

/*
Types of constructors for a class:

Default
Paramterized Constructor
copy Constructor
Move Constructor

*/

Employee::Employee() : m_id{0}, m_salary{0}{
    std::cout << "in defualt Constructor\n";
}

Employee::Employee(int id, int salary) :
m_id(id), m_salary(salary)
{
    std::cout << "in Paramterized Constructor\n";
}

Employee::Employee(const Employee& copy){
    m_id = copy.m_id;
    m_salary = copy.m_salary;
}

Employee::~Employee(){
    std::cout << "in destructor\n";
}

// "const" to say we won't change variables in this function
int Employee:: getId() const
{
    return m_id;
}

int main(){

    /*
    three ways to intalize variables
    int i = 0;  copy initializer at leat 3(instructions to execute)
    int x(5);   driect initializer -> faster than copy -> doesn't support all types
    int y{0};   uniform initializer -> preformance of direct and it supports all types    
    */

   // new -> gets enough memory in heap for object
    Employee *e1 = new Employee(8, 1100);
    int id  = e1->getId();

    std::cout << id << std::endl;

    delete e1;
    return 0;
}