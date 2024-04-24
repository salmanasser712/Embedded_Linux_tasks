#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int main()
{
	std::vector<int> list { 80, 120, 1200, 15, 7, 6};

	std::array<int,5> myArray{5, 8, 18, 13, 77};

	std::sort(list.begin(), list.end(), [](int a, int b){
		return a > b;
	}); 

	int i = 1;

	std::for_each(myArray.begin(), myArray.end(), [&i](int &elem){
		elem *= i;
		std::cout << elem << " ";
		i++;
	});

	std::cout << std::endl;

    int x = 3;
    int y = 9;
    int z = 10;
    auto print = [&]()->void { 
                    x*=2;
                    y*=2;
                    z*=2;
                    std::cout << "var = " << x << " var2 " << y << " var3 " << z<< std::endl;
                };

    print();

    auto print_value = [=]()->void { 
            std::cout << "var = " << x << " var2 " << y << " var3 " << z << std::endl;
         };

    auto print_only_two = [&x, &y](int factor)->void { 
                                x += factor;
                                y += factor;
                                std::cout << "var = " << x << " var2 " << y;
                            };

    print_only_two(10);
	std::cout << std::endl;
    return 0;
}