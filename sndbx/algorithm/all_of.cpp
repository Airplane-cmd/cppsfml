#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
	auto lmbd{
		[](int v){return v % 2 == 0;}};
	std::vector<int> vctr{2, 4, 6, 8, 10};
	if(std::all_of(vctr.begin(), vctr.end(), lmbd))
		std::cout << "All numbers are even." << '\n';
	if(std::any_of(vctr.begin(), vctr.end(), lmbd))
		std::cout << "Any of these numbers are even"<<'\n';
	if(std::none_of(vctr.begin(), vctr.end(), [](int v){return v % 2 != 0;}))
		std::cout << "None of these numbers are odd"<<'\n';
	return 0;
}
