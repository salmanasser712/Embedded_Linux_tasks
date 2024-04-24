#include <iostream>
#include <array>
#include <vector>

constexpr int N = 2e5 + 7;

bool in_range(int &n){
	return n < N;
}

std::array<int, N> nums;

int main(){
	int t = 3;
	while(t--){
		int n;
		std::cout << "Please Enter number of numbers:" << std::endl;
		std::cin >> n;

		std::cout << "Please Enter the numbers:" << std::endl;
		bool valid = true;
		for(int i = 0; i < n; i++){
			int num;
			std::cin >> num;
			valid = in_range(num);
			if(valid){
				nums[num]++;
			}
			else{
				valid = false;
				break;
			}
		}

		if(!valid){
			std::cout << "Number out of Range!!" << std::endl;
			std::cout << "Number of Tries left " << t << std::endl << std::endl;
			continue;
		}

		std::cout << "Elements : Frequency" << std::endl;
		for(int i = 0; i < N; i++){
			if(nums[i] > 0){
				std::cout << i << ": " << nums[i] << std::endl;
			}
		}
		break;
	}


	return 0;


}
