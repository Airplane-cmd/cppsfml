#include <iostream>
#include <string>
#include <array>
#include <algorithm>
int main()
{
	struct Student
	{
		std::string name;
		int mark;
	};
	std::array<Student, 8> arr{
		{{"Albert", 3},
		{"Ben", 5},
		{"Christine", 2},
		{"Den", 8},
		{"Rick", 4},
		{"Francise", 2}, 
		{"Greg", 5},
		{"Hagrid", 2}}};
	std::sort(arr.begin(), arr.end(), [](Student a, Student b)
			{
				return a.mark > b.mark;
			});
	std::cout<<arr[0].name<<"\n";
	return 0;
}//done
