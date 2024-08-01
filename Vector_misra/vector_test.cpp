#include <iostream>
#include <vector>


int main()
{
    std::vector<int> v1;
    int a[] = { 1, 2, 3 };
    v1.assign(a, a + 3);
    std::cout << v1.capacity() << std::endl;
    return 0;
}