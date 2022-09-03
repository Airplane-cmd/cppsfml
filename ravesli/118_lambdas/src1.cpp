
#include <iostream>
#include <string_view>
#include <array>
#include <algorithm>
struct Season
{
	std::string_view name{};
	double aT{};
};
int main()
{
	std::array<Season, 4> arr{
		{{"Winter", -15.0},
		 {"Spring", 12.0},
		 {"Summer", 23.0},
		 {"Autumn", 13.0}}};
	std::sort(arr.begin(), arr.end(), [](Season &a, Season &b){
			return a.aT < b.aT;
			});
	for(Season &s:arr)	std::cout<<s.name<<"  ";
	std::cout<<std::endl;
	return 0;
}//done
