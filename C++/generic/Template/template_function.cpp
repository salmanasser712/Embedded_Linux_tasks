#include <iostream>

//template functions

template<typename type>

type max(type n1, type n2){
    type temp = n1 > n2;
    return temp;
}

template<class T>
void swap(T& first, T& second){
    T temp = first;
    first = second;
    second = temp;
}


class Person{
    public:
    Person(int p_Id, int p_Age): Id(p_Id), Age(p_Age){

    }

    Person(Person &per){
        this->Age = per.Age;
        this->Id = per.Id;
    }

    Person operator > (Person & p2){
        if(p2.Age > this->Age) return p2;
        return *this;
    } 

    void operator = (Person &p2){
        this->Age = p2.Age;
        this->Id = p2.Id;
    }

    int getAge(){
        return this->Age;
    }

    int getId(){
        return this->Id;
    }

    private:
    int Age;
    int Id;
};


int main(){
    Person p1(1, 25);
    Person p2(2, 26);

    swap<Person>(p1, p2);

    std::cout << "P1 age = " << p1.getAge() << ", id = " << p1.getId() << std::endl;
    std::cout << "P2 age = " << p2.getAge() << ", id = " << p2.getId() << std::endl;

    Person p3 = max<Person>(p1, p2);

    std::cout << "Id of Max = " << p1.getId() << std::endl; 

}
