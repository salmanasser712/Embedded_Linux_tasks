#include <iostream>
#include <vector>

class Animal{
    public:
    virtual void makeSound() = 0;
    virtual ~Animal(){
        std::cout << "Base Distractor!!\n";
    };

};

class Dog : public Animal{
    public:
    void makeSound() override{
        std:: cout << "Dog Sound\n";
    }
};

class Cat : public Animal{
    public:
    void makeSound() override{
        std:: cout << "Cat Sound\n";
    }
};

class Cow : public Animal{
    public:
    void makeSound() override{
        std:: cout << "Cow Sound\n";
    }
};

void Sound(std::vector<Animal*> animals){
    for(int i = 0; i < animals.size(); i++){
        animals[i]->makeSound();
    }
}

int main(){
    Animal * dog = new Dog();
    Animal * cat = new Cat();
    Animal * cow = new Cow();
    std::vector<Animal *> animals = {dog, cat, cow};
    Sound(animals);
    delete(dog);
    return 0;
}