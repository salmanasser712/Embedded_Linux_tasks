#include <iostream>
#include <cstdint>

class Student{
    public:
    Student(std::string p_name, std::uint16_t p_id, std::uint16_t p_age):
    name(p_name), id(p_id), age(p_age)
    {
        std::cout << "Constructor\n";
    }

    void setName(std::string In_name){
        this->name = In_name;
    }

    std::string getName(){
        return this->name;
    }

    void setAge(std::uint16_t In_age){
        this->age = In_age;
    }

    std::uint16_t getAge(){
        return this->age;
    }

    void setId(std::uint16_t In_id){
        this->id = In_id;
    }

    std::uint16_t getId(){
        return this->id;
    }

    void DispalyInfo(){
        std::cout << "ID: " << this->id << ", Name: " << this->name << ", Age: " << this->age << std::endl;
    }

    ~Student(){
        std::cout << "Object Deleted\n";
    }

    private:
    std::uint16_t id;
    std::uint16_t age;
    std::string name; 
};

int main()
{
    Student s1("Salma", 0, 23);
    s1.DispalyInfo();
    return 0;
}