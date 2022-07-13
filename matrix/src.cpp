#include<iostream>
#include<vector>
#include<cmath>
typedef std::vector<std::vector<double>> v2d;
double iuvgbn(v2d mtrx_f);
v2d jppif();
v2d gcdhvb(v2d &mtrx_f, int id);
void print(v2d &mtrx_f);
int main()
{
	
	v2d matrix = jppif();
//	v2d matrix{{2, 1, -2, 3}, {1, -1, -1, 0}, {1, 1, 3, 12}};
	print(matrix);//db
//	return 0;//db
//	system("clear");
	std::vector <double>dtrmnnt(matrix[0].size());
	for(int e = 0; e < (matrix[0].size()); ++e)
	{
//		std::cout<<e<<std::endl;
		if(e == 0)
		{
			dtrmnnt[e] = iuvgbn(gcdhvb(matrix, 69));
		}
		else
		{
			dtrmnnt[e] = iuvgbn(gcdhvb(matrix, e - 1));
		}
//		std::cout<<e<<std::endl;
	}
	for(int d = 1; d < matrix[0].size(); ++d)
	{
		std::cout<<d;
		std::cout<<":="<<dtrmnnt[d]/dtrmnnt[0]<<std::endl;
	}
		
	

	return 0;
}
v2d jppif()
{
	v2d mtrx_rs;
	int sz_y{1}, sz_x{1}, y{0}, x{0};
//	std::vector<std::string> lns{{"2 1 -2 3"}, {"1 -1 -1 0"}, {"1 1 3 12/"}};
	while(y < sz_y)
	{
		
		std::vector<double> vctr;
		std::string crrnt_ln;
		std::getline(std::cin, crrnt_ln);
//		std::cin>>crrnt_ln;
//		crrnt_ln = lns[y];//db
		crrnt_ln += ' ';
//		std::cout<<crrnt_ln<<std::endl;//db
//		std::cout<<"cr "<<crrnt_ln<<std::endl;//db
		double nmbr{0};
                int pw{0};
		bool fckdM{0}, fckdD{0};
		for(int a{0}; a < crrnt_ln.size(); ++a)
		{	
			if(crrnt_ln[a] == '/')
			{
//				vctr.push_back(nmbr);
				sz_y = 0; 
			}
			if(crrnt_ln[a] == '-')
			{ 
				fckdM = 1;
			}
			if(crrnt_ln[a] == ' ') //!
			{
				if(fckdM == 1) nmbr*=-1;
				vctr.push_back(nmbr);
				if(y == 0) std::cout<<"push: "<<nmbr<<std::endl;//db
				pw = 0;
				nmbr = 0;
				fckdM = 0;
				fckdD = 0;
				
			}
			if(crrnt_ln[a] == '.')
			{
				fckdD = 1;
				pw = -1;
			}
			else if((crrnt_ln[a] != ' ') && (crrnt_ln[a] != '.') && (crrnt_ln[a] != '/') && (crrnt_ln[a] != '-')) 
			{	
//				std::cout<<"cunt";//db
				if(fckdD == 0)
				{
					double pr_nmbr = nmbr;
					nmbr = nmbr * pow(10, pw) + (crrnt_ln[a] - 48);
//					if(y == 0) std::cout<< pr_nmbr<<" * "<<pow(10, pw)<<" + "<<crrnt_ln[a] - 48<<" = "<< nmbr<<std::endl;//db
					pw = 1;
				}
				else
				{
					
					nmbr = nmbr + (crrnt_ln[a] - 48) * pow(10, pw);
					--pw;
				}
			}

		
		}
		++y;
		++sz_y;
		mtrx_rs.push_back(vctr);
	}
	return mtrx_rs;
}
double iuvgbn(v2d mtrx_f)
{
	double dtrmnnt;
	if((mtrx_f.size() != 2) && (mtrx_f[0].size() != 2))
	{		
		for(int c = 0; c < mtrx_f[0].size(); ++c)
		{
				int sgn;
				if ((c % 2) != 0) sgn = -1;
				else sgn = 1;
				v2d sbMtrx;
				int aa_cnt{0};
				int ab_cnt{0}; 
				for(int a = 1; a < mtrx_f.size(); ++a)
				{
					std::vector<double> sbVctr;
					for(int aa = 0; aa < mtrx_f[a].size(); ++aa)
					{
						if(aa == c)
							continue;
						sbVctr.push_back(mtrx_f[a][aa]);
					}
					sbMtrx.push_back(sbVctr);
				}
				dtrmnnt += sgn*mtrx_f[0][c]*iuvgbn(sbMtrx); 
		}
	}
	
	else
		dtrmnnt = mtrx_f[0][0] * mtrx_f[1][1] - mtrx_f[0][1] * mtrx_f[1][0];
//	std::cout<<"stupid cunt"<<std::endl;
	return dtrmnnt;
}
v2d gcdhvb(v2d &mtrx_f, int id)
{
	v2d mtrx_rs;
	for(int a = 0; a < mtrx_f.size(); ++a)
	{
		std::vector<double> sbVctr;
		for(int aa = 0; aa < mtrx_f[a].size(); ++aa)
		{
			if(id == 69)
			{
				if(aa != (mtrx_f[a].size() - 1))
					sbVctr.push_back(mtrx_f[a][aa]);
			}
			else
			{
				if((aa != id) && (aa != (mtrx_f[a].size() - 1)))
					sbVctr.push_back(mtrx_f[a][aa]);
				else if(aa == id)
					sbVctr.push_back(mtrx_f[a][mtrx_f[a].size() - 1]);
			}
		}
		mtrx_rs.push_back(sbVctr);
	}
//	std::cout<<"suck my cock ";
	return mtrx_rs;		
}	
void print(v2d &mtrx_f)
{
	std::cout<<mtrx_f.size()<<" "<<mtrx_f[0].size()<<std::endl;
	for(int a{0}; a < mtrx_f.size(); ++a)
	{
		for(int aa{0}; aa < mtrx_f[a].size(); ++aa)
		{

			std::cout<<mtrx_f[a][aa]<<" ";
		}
		std::cout<<std::endl;
	}
}



	

