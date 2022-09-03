#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> solution(const std::string &s);
void print(const std::vector<std::string> &v);
int main()
{
	print(solution("shutthefuckupstupidcuntsuckmydick"));
	return 0;
}
void print(const std::vector<std::string> &v)
{
	for(std::string iter: v) std::cout<<iter<<" ";
}
std::vector<std::string> solution(const std::string &str)
{
	std::vector<std::string> stck;
	std::string s = str;
	std::string buff;
	if(s.size() % 2 != 0)	s.push_back('_');
	for(int a = 0; a < s.size(); ++a)
	{
		if(a % 2 == 0)	buff.push_back(s[a]);
		else
		{
			buff.push_back(s[a]);
			stck.push_back(buff);
			buff.clear();
		}
	}
	return stck;
}

