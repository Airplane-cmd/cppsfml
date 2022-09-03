#include <iostream>
int main()
{
	auto f{[](int &a, int &b){a^=b; b^=a; a^=b;}};
	int a{46754};
	int b{345765};
	f(a, b);
	std::cout << a << " " << b << std::endl;
	return 0;
}
