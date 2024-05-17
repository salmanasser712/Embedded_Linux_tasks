#include <iostream>
#include<vector>
#include <algorithm>

struct Record{
    std::string name;
    int power_level;

    void Print_Data(){
        std::cout << "Name: " << name << ", Power Level: " << power_level << std::endl;
    }
};

int main(){

    auto CmpareByName = [](Record& a, Record& b)->bool{return a.name > b.name;};
    auto CmpareByPowerLevel = [](Record& a, Record& b)->bool{return a.power_level > b.power_level;};

    std::vector<Record> v = {{"Erin ", 100}, {"Armin", 80}, {"Mikasa", 120}, {"Reiner", 75}};

    std::cout<< "Sorted by Name: \n";

    std::sort(v.begin(), v.end(), CmpareByName);

    for(auto & record: v){
        record.Print_Data();
    }

    std::cout<< "Sorted by Power Level: \n";

    std::sort(v.begin(), v.end(), CmpareByPowerLevel);

    for(auto & record: v){
        record.Print_Data();
    }
    

    return 0;
}