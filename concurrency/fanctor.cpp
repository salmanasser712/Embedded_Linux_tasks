#include <iostream>
#include <thread>

class Employee
{
    public:
    Employee(int id, std::string name, int salary): id_(id), name_(name), salary_(salary)
    {}

    void operator()()
    {
        std::cout << "ID: " << id_ << ", Name: " << name_ << ", Salary: " << salary_ << std::endl; 
    }

    private:
    int id_;
    std::string name_;
    int salary_;

};

int main()
{
    Employee Salma(1, "salma", 5);

    std::thread t1(Salma);

    t1.join();
    return 0;
}