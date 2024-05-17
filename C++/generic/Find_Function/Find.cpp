#include <iostream>
#include <vector>
#include <array>

template<class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val){
    for(InputIterator i = first; i != last; i++){
        if(*i == val) return i;
    }
    return last;
}

class Job{
    public:
    Job(int p_id, std::string p_name): name(p_name), id(p_id){

    }

    bool operator==(const Job& job){
        return this->name == job.name;
    }

    void printdata(){
        std::cout << "Id: " << this->id << ", name of the Job: " << this->name << std::endl;
    }


    private:
    std::string name;
    int id;

};

void testVector_int(){
    std::vector<int> v1 = {77, 37, 37, 37, 37, 80, 10, 15};
    std::cout << "For vector of: ";
    for(auto item: v1){
        std::cout << item << " ";
    }

    std::vector<int>::iterator it = find(v1.begin(), v1.end(), 50);
    if(it == v1.end()) std::cout << "\nCouldn't find 50 in this vector\n";
    it = find(v1.begin(), v1.end(), 37);
    if(it != v1.end()){
        std::cout << "The first occurrence of 37 is in index: " << it - v1.begin() << std::endl;
    }
}

void testVector_Person(){
    std::vector<Job> v1 = {Job(1, "Software Engineer"), Job(2, "Embedded software"), Job(5, "Embedded Linux"),Job(6, "Embedded Linux"),Job(7, "Embedded Linux"), Job(3, "Machine Learning")};
    std::cout << "For vector of jobs: \n";
    for(auto& job: v1){
        job.printdata();
    }
    std::vector<Job>::iterator it = find(v1.begin(), v1.end(), Job(7, "DevOps"));
    if(it == v1.end()) std::cout << "\nCouldn't find DevOps in this vector\n";
    it = find(v1.begin(), v1.end(), Job(7, "Embedded Linux"));
    if(it != v1.end()){
        std::cout << "The first occurrence of Embedded Linux is in index: " << it - v1.begin() << std::endl;
    }

}

void testArray_int(){
    std::array<int, 8> arr = {77, 37, 37, 37, 37, 80, 10, 15};
    std::cout << "For array of: ";
    for(auto item: arr){
        std::cout << item << " ";
    }

    std::array<int, 8>::iterator it = find(arr.begin(), arr.end(), 50);
    if(it == arr.end()) std::cout << "\nCouldn't find 50 in this array\n";
    it = find(arr.begin(), arr.end(), 37);
    if(it != arr.end()){
        std::cout << "The first occurrence of 37 is in index: " << it - arr.begin() << std::endl;
    }
}

void testArray_Person(){
    std::array<Job, 6> arr = {Job(1, "Software Engineer"), Job(2, "Embedded software"), Job(5, "Embedded Linux"),Job(6, "Embedded Linux"),Job(7, "Embedded Linux"), Job(3, "Machine Learning")};
    std::cout << "For array of jobs: \n";
    for(auto& job: arr){
        job.printdata();
    }
    std::array<Job, 6>::iterator it = find(arr.begin(), arr.end(), Job(7, "DevOps"));
    if(it == arr.end()) std::cout << "\nCouldn't find DevOps in this array\n";
    it = find(arr.begin(), arr.end(), Job(7, "Embedded Linux"));
    if(it != arr.end()){
        std::cout << "The first occurrence of Embedded Linux is in index: " << it - arr.begin() << std::endl;
    }
}

int main(){
    //finding an element in a vector of integers
    testVector_int();

    //finding an element in a vector of user defined datatype
    testVector_Person();

    //finding an element in an array of intergers
    testArray_int();

    //finding an element in a array of user defined datatype
    testArray_Person();

    return 0;
}