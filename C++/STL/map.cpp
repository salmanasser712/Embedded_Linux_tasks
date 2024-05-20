#include <iostream>
#include <map>

int main(){
    std::map<int, int> mp;
    mp.insert(std::make_pair<int, int>(1, 37));
    mp.insert(std::pair<int, int>(2, 11));
    mp.insert(std::pair<int, int>(3, 50));

    auto it = mp.find(3);
    if(it != mp.end()){
        std::cout << "found pair with key = 3, value = " << it->second << "\n"; 
    }

    mp.erase(1);

    it = mp.find(1);
    if(it == mp.end()){
        std::cout << "the value of key 1 is erased\n";
    }


    return 0;
}