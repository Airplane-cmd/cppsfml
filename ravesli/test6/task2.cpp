#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct Student
{
	std::string name;
	int mark;
};
int main()
{
	int sz;
	std::cout << "Count of array: ";
	std::cin >> sz;
	std::vector<Student> vctr(sz);
	for(Student &vl: vctr)	{std::cin >> vl.name; std::cin >> vl.mark;}
	std::sort(vctr.begin(), vctr.end(), [](Student &a, Student &b){return a.mark > b.mark;});
	for(Student &vl: vctr)	std::cout<< vl.name << ", " << vl.mark << std::endl;
	return 0;
}
