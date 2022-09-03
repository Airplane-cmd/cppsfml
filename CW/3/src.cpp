#include <iostream>

bool isPrime(int num);
int main()
{
	std::cout<<"Twelve: "<<isPrime(123458701);
	return 0;
}
bool isPrime(int num)
{
	if(num > 1)
	{
		for(int a{2}; a < (num - 1); ++a)
		{
			if(!(num % a)) return 0;
		}
		return 1;
	}
	else
		return 0;
}
