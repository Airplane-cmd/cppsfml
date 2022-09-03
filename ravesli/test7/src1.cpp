#include <iostream>
#include <array>
#include <vector>
int* binarySearchI(const int *arr, int target, int min, int max);
int* binarySearchR(const int *arr, int target, int min, int max);
int main()
{
	std::array<int, 15> arr{4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50};
	std::cout << "Enter a number: ";
	int num;
	std::cin >> num;
	int *val = binarySearchR(&(arr[0]), num, 0, 14);
	if (val != 0 )	std::cout << *val<<" at "<<(val - arr.begin()) << std::endl;
	else 			std::cout <<"Failed" << std::endl;
	return 0;
}
int* binarySearchI(const int *arr, int target, int min, int max)
{
	min = 0;
	int mdl = max / 2;
	bool chckd{0};
	do
	{

//		std::cout << min << "  " << mdl << "  " << max << std::endl;//db
		if(arr[mdl] > target)	
		{
			max = mdl - 1;
		}
		else if(arr[mdl] < target)
		{
			min = mdl + 1;
		}
		else if(arr[mdl] == target)	return const_cast<int*>(arr) + mdl;
		mdl = min + (max - min) / 2;	
	}
	while(max != min != mdl);
	return 0;
}
int* binarySearchR(const int *arr, int target, int min, int max)
{
	int mdl = min + (max - min) / 2;
//	std::cout << min << "  " << mdl << "  " << max << std::endl;//db
	if((arr[mdl] < target)&&((max-min)>1))			return binarySearchR(arr, target, mdl + 1, max);
	else if((arr[mdl] > target)&&(max-min)>1)		return binarySearchR(arr, target, min, mdl - 1);
	else if(arr[mdl] == target)		return const_cast<int*>(arr) + mdl;
//	std::cout << min << "  " << mdl << "  " << max << std::endl;//db
	if((min == max)&&(arr[mdl] != target))	return 0;
}
