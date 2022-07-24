#include<iostream>
#include<vector>
#include<string>
int max = 0;
bool con(std::string str1, std::string str2, int j)
{
    	for(int i = 0; i < j; ++i)
    	{
        	if(str1[i]!=str2[i])
          		return 0;
     	}
	return 1;
}
std::vector<std::vector<int>> idiot(std::string alph, std::vector<std::string> lines, int max)
{
	std::vector<std::vector<int>>kfs(lines.size(), std::vector<int>(max, 0));
	for(int i = 0; i < lines.size(); ++i)
	{
        	for(int j = 0; j < max; ++j)
        	{
			if(j < lines[i].size())
			{
				for(int k = 0; k < 26; ++k)
				{

        				if (alph[k] == lines[i][j])
                    				kfs[i][j] = k+1;
				}
			}
			else
				kfs[i][j] = -1;

        	}
    	}
    return kfs;

}
void printK(std::vector<std::vector<int>> kfc, int* c)
{
	std::cout<<++(*c)<<"k: "<<std::endl;
	for(int i = 0; i < kfc.size(); ++i)
	{
		for(int j = 0; j < max; ++j)
		{
			if((kfc[i][j] != -1)&&(kfc[i][j]+1 < 10))
				std::cout<<kfc[i][j]<<"  ";
			else if(kfc[i][j]+1 > 9)
				std::cout<<kfc[i][j]<<" ";
			else
				std::cout<<"#  ";
		}
		std::cout<<std::endl;
	}
//	std::cout<<"w";
}
void print(std::string alph, std::vector<std::string> lines)
{
	int c = 0;
 	std::vector<std::vector<int>>kfs;
	std::string cash;
	for(int i = 0; i < lines.size(); ++i)
	{
            	if(lines[i].size() > max)
          	      max = lines[i].size();
    	}
    	kfs = idiot(alph, lines, max);
//	printK(kfs, &c);
	int ic = 0;
	int jc = 0;
    	while(ic < (lines.size()-1))
    	{
        	while((jc < max)&&(ic < (lines.size()-1)))
        	{
//			std::cout<<ic<<" "<<kfs[ic][jc]<<" -- "<<kfs[ic+1][jc]<<std::endl;
                	if((kfs[ic][jc]>kfs[ic+1][jc])&&con(lines[ic], lines[ic+1], jc))
			{
				lines[ic].swap(lines[ic+1]);
              			ic = 0;
               			jc = 0;
		    		kfs = idiot(alph, lines, max);
//				printK(kfs, &c);
               		}
			else if((kfs[ic][jc]<kfs[ic+1][jc]))
			{
//				ic++;
				jc++;
				
//				std::cout<<"skip"<<std::endl;
			}
               		else if((kfs[ic+1][jc] == -1)&&(kfs[ic][jc] != -1)&&(lines[ic] !=lines[ic+1])&&con(lines[ic],lines[ic+1], jc))
           		{
            			lines[ic].swap(lines[ic+1]);
                		ic = 0;
                		jc = 0;
		  		kfs = idiot(alph, lines, max);
		   		std::cout<<std::endl;
//		    		printK(kfs, &c);
              		}
			else
				jc++;
			
        	}
		ic++;
		jc = 0;
//		std::cout<<"fuck"<<std::endl;
	}
	
    	for(int i = 0; i < lines.size(); ++i)
    	{
		std::cout<<lines[i]<<std::endl;
    	}
}
    int main()
    {
        int n = 4;
	std::string alph1{"abcdefghijklmnopqrstuvwxyz"};
	std::cin>>alph1;
        if (alph1.size()!=26)
            return -1;
	std::cin >> n;
//	std::vector<std::string> lines1{"d","c","b","a"};
	std::vector<std::string> lines1;	
	for(int i = 0; i < n; ++i)
	{
		std::string cash;
		std::cout<<i+1<<": ";
		std::cin>>cash;
		lines1.push_back(cash);
	}
        print(alph1, lines1);
        
        return 0;
    }

