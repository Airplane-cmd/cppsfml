#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <string>
bool comp1(int a, int b);
bool comp2(int a, int b);
int main()
{
	std::vector<int> v{2, 1, 5, 7, 8, 3, 6};
	auto print{
			[](std::vector<int> &arr)
			{
				for(int &num : arr)	std::cout << num <<"  ";
				std::cout << '\n';
			}
		  };
	std::sort(v.begin(), v.end(), comp1);
	print(v);
	std::sort(v.begin(), v.end(), comp2);
	print(v);
	std::sort(v.begin(), v.end(), [](int a, int b)//stranger things!
			{
				if ((a%2 == 0)&&(b%2!=0))	return 1;
				if ((a%2!=0)&&(b%2==0))		return 0;
				else				comp2(a, b);
			});
	print(v);
	return 0;
}
bool comp1(int a, int b)
{
	return a > b;
}
bool comp2(int a, int b)
{
	return a < b;
}
