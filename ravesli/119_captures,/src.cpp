#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cmath>
int main()
{
	srand(time(0));
	int nmbr{};
	int cnt{};
	int k{};
	std::cout << "Start where? ";
	std::cin >> nmbr;
	std::cout <<"How many? ";
	std::cin >> cnt;
	auto setK{[&k]()
	{
		int v{0};
		while(v < 2)	v = (rand() % 5);
		k = v;
	}};
	setK();
	std::cout << "Multiplied by " << k <<'\n';
	std::vector<int> vctr;
	for(int i{nmbr}; i < (nmbr + cnt); ++i)	vctr.push_back(std::pow(i, 2) * k);
	int s{static_cast<int>(vctr.size())};
	for(int i{0}; i < s; ++i)
	{
		int num{};
		std::cout <<"Enter a number: ";
		std::cin >> num;
		auto found{std::find(vctr.begin(), vctr.end(), num)};
		if(found != vctr.end())
		{
			std::cout << "Number is found!\n";
			vctr.erase(found);//
		}
		else
		{
			auto actNum = std::min_element(vctr.begin(), vctr.end(), [num](int &a, int &b)
					{
						return (std::abs(a - num) < std::abs(b - num));
					});
			std::cout << "STFUSCSMD ";
			if(std::abs(*actNum - num) < 4)	std::cout << *actNum;
			std::cout << '\n';
			return 0;
		}
	}
	return 0;
}
