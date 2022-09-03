#include<iostream>
#include<string>
std::string spinWords(const std::string &strI);
int main()
{
	std::string str;
	std::cout<<spinWords("shut the fuck up stupid cunt suck my dick abcdefghijklmnopqrstuvwxyz")<<std::endl;
	return 0;
}
std::string spinWords(const std::string &strI)
{
	std::string str = strI;
	str += ' ';
	std::string buff;
	int a{0};
	while(a < (str.size()))
	{
		if(str[a] != ' ')
		{
			buff += str[a];	
		}
		else if((a == (str.size() - 1))||(str[a] == ' '))
		{
			if(buff.size() > 4)
			{
				int aa = 0;
				while(aa < buff.size())
				{
					str[a - buff.size() + aa] = buff[buff.size() - 1 - aa];//-1
					++aa;
				}
			}
				buff.clear();
			
		}
		++a;
	}
	str.pop_back();
	return str;
}

