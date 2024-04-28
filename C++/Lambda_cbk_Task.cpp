#include<iostream>
#include<array>
#include<functional>
/*
Assignment : 

* Calculate takes  two parameters first is array/vector, second is a function which
* modifys the elements of the array:to be swapped with another array
* call std::sort for sorting array

*/

void Calculate (std::vector<int> &v, std::function<bool (std::vector<int>&)> swap, 
                                     std::function<void (void)> print)
{   
    bool valid = swap(v);
    if(valid){
        print();
    }
    else{
        std::cout << "Error While swapping\n";
    }
}

int main() {
    std::vector<int> v1, v2;
    int n;

    std::cout << "Enter the size of the 2 vectors:\n";
    std::cin >> n;

    std::cout << "Enter the Elements of the first vector: \n";
    for(int i = 0; i < n; i++){
        int num;
        std::cin >> num;
        v1.push_back(num); 
    }

    std::cout << "Enter the Elements of the second vector: \n";
    for(int i = 0; i < n; i++){
        int num;
        std::cin >> num;
        v2.push_back(num); 
    }
    int i = 0;
    auto swab = [&v2, &i](std::vector<int> &v) -> bool{
        std::sort(v2.begin(), v2.end());
        std::for_each(v.begin(), v.end(), [&v2, &i](int &item){
            int temp = item;
            item = v2[i];
            v2[i] = temp;
            i++;
        });
        return true;
    };


    auto print = [&v1, &v2](){
        std:: cout << "Elements are swapped!!\n";
        std:: cout << "Second vector sorted:\n";
        for(int i = 0; i < v1.size(); i++){
            std::cout << v1[i] << " ";
        }
        std:: cout << "\n";
        std:: cout << "First vector:\n";
        for(int i = 0; i < v2.size(); i++){
            std::cout << v2[i] << " ";
        }
        std:: cout << "\n";
    };

    Calculate(v1, swab, print);


   return 0;
}