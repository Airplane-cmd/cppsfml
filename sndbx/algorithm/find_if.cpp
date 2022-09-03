#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>
#include <sstream>
#include <string>
#include <cstdlib>
int main()
{
	std::array<std::string, 4> S_arr;
       	auto printSA{[&S_arr]{for(std::string &S_val: S_arr)	std::cout << S_val << "  ";}};
	std::string sbln{};
	auto containsSbln{[&sbln](std::string &str){return (str.find(sbln) != std::string::npos);}};
	auto chooseVar{[](int n)	{char v = n + 65; std::cout << v <<std::endl;}};
	srand(time(0));
	int a, b, c, d;
	std::array<std::stringstream, 4> SS_arr;
	SS_arr[0] << &a;
	SS_arr[1] << &b;
	SS_arr[2] << &c;
	SS_arr[3] << &d;
	std::array<std::string_view, 4> SV_arr;
	std::string *ptrS{&(S_arr[0])};
	for(std::stringstream &SS_val: SS_arr)	 SS_val >> *(ptrS++);
//	for(int i{0}; i < SV_arr.size(); ++i)	SV_arr[i] = S_arr[i];
	printSA();
	std::cout << std::endl;
	std::cout << "Search for: ";
	std::getline(std::cin, sbln);
	auto found{ std::find_if(S_arr.begin(), S_arr.end(), containsSbln)};
	if(found != S_arr.end())	{std::cout << "Variable "; chooseVar(found - &(S_arr[0])); std::cout << std::endl;}
	else				std::cout << "Not found" << std::endl;
	return 0;
}


