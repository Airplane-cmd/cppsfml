#include <iostream>
#include <cassert>
bool lovefunc(int n1, int n2);
int main()
{
	assert(lovefunc(2, 94));
}
bool lovefunc(int n1, int n2)
{
	return (((n1 % 2)&&(!(n2 % 2)))||((n2 % 2)&&(!(n1 % 2))));
}

