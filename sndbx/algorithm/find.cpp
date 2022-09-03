#include <iostream>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <ctime>
int main()
{
	srand(time(0));
	std::array<int, 20> arr;
	for(int &num : arr)	num = rand() % 20;
	auto printArr{[&arr](){for(int &num: arr)	std::cout << num << "  ";}};
	printArr();
	std::cout << std::endl;
	std::cout << "Search for: ";
	int srch{};
	std::cin >> srch;
	int *ptr{ std::find(arr.begin(), arr.end(), srch)};
	if(ptr != arr.end())
	{
		std::cout << "Replace with: ";
		int rplc{};
		std::cin >> rplc;
		*ptr = rplc;
		printArr();
	}
	else	std::cout << "Not found" << std::endl;
	std::cout << std::endl;	
	return 0;
}
