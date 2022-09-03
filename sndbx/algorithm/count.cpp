#include <iostream>
#include <array>
#include <algorithm>
#include <string>
int main()
{
	std::array<std::string, 6> arr{"apple", "peanut", "coconut", "dick", "walnut", "cock"};
	auto print{[&arr](){for(std::string &nm: arr)	std::cout << nm <<"  "; std::cout << std::endl;}};
	print();
	std::cout << "Count subline: ";
	std::string ln{};
	std::getline(std::cin, ln);
	auto count{std::count_if(&arr[0], arr.end(), [&ln](std::string &thng){return thng.find(ln) != std::string::npos;})};
	std::cout << count <<std::endl;
	return 0;
}
