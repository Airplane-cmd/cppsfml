#include <iostream>
void print(char *ln);
int main()
{
	print("Hello, world");
	return 0;
}
void print(char *ln)
{
	while(*ln != '\0')	{std::cout << *ln; ++ln;} std::cout << std::endl;
}
