#include<iostream>
#include<vector>
#include"header.h"
typedef std::vector<Block> tp;
tp setVector(std::string &ln);
int findMax(tp &vctr, int &vl);
int main()
{
	int vl{10};
//	std::cin >> vl;
	std::string ln = {".......x...x...xx.xxx.xx...x..."};
	tp vctr = setVector(ln);
	std::cout<<vctr.size()<<std::endl;//db
	std::cout<<findMax(vctr, vl)<<std::endl;
	return 0;
}
tp setVector(std::string &ln)
{

	int a{0};
	int ps{0};
	Block blck;
	bool fckd{0};
	int lstx{0};
	int lnght{0};
	int pst{0};
	tp vctr;
	int id{0};
	while(a < ln.size())
	{
		if((ln[a] == 'x') && ((ln[a - 1] == '.')||(a == 0)))
		{
			blck.setPos(a);
			fckd = 1;
		}
		if((fckd == 1)&&(ln[a] == 'x')&&((ln[a+1] == '.') || (a + 1 == ln.size())))
		{
			lstx = a;
			lnght = a - blck.getPos() + 1;	
			blck.setLenght(lnght);
		}
		if(((fckd == 1)&&(ln[a] == '.')&&(ln[a+1] == 'x'))||(a + 1 == ln.size()))
		{
			fckd = 0;
			pst = a - lstx;
			blck.setPst(pst);
			blck.setId(id);
			vctr.push_back(blck);
			++id;
		}
		++a;
	}
	return vctr;
}
int findMax(tp &vctr, int &vl)
{
	int max{0};
	int bff{0};
	int rg{0};
	int crng;
	for(int a{0}; a < vctr.size(); ++a)
	{
		int aa{0}, cntr{0};
		while(aa < vl)
		{
			rg = bff;
			if((vl - aa) > vctr[a + cntr].getPst())
			{	
				
				bff += (vctr[a + cntr].getLenght() + vctr[a + cntr].getPst());
				std::cout <<"up :"<<bff<<" = "<<rg<<" + "<<vctr[a + cntr].getLenght()<<" + "<<vl<<" - "<<aa<<std::endl;//db
				crng = vctr[a + cntr].getPst() - vl + aa;
				aa += vctr[a + cntr].getPst();
			}
			else
			{
				bff += vctr[a + cntr].getLenght() + vl - aa;
				std::cout <<bff<<"    "<<" = "<<rg<<" + "<< vctr[a + cntr].getLenght()<<" + "<<vl<<" - "<<aa<<std::endl;//db
				crng = vctr[a + cntr].getPst() - vl + aa;
				aa = vl;
			}
			
			if(((a + cntr + 1) != vctr.size()) && (crng == 0))
			{
				bff += vctr[a + cntr + 1].getLenght();
			}
			++cntr;
		}
		
//		std::cout << bff << std::endl;//db
		if (bff > max) max = bff;
		bff = 0;
		rg = 0;
	}
	return max;
}
