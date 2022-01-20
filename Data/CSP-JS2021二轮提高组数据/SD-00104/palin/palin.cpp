#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
ifstream fin;
ofstream fout;
bool k[63];
int in[200],out[200],n,T;
int fff()
{
	fin.open("palin.in");
	fout.open("palin.out");
}
int an(int a)
{
	if(k[a])
	{
		k[a]=0;
		an(a-1);
	}
	else
	{
		k[a]=1;
	}
}
int hui()
{
	int l=1,r=2*n,ti=1;
	while(ti<=2*n)
	{
	    
		if(k[ti])
		{out[ti]=in[r];
		r--;
		}
		    
		else
		{
			out[ti]=in[l];
			l++;
		}
		ti++;
		    
	}
	bool flag=0;
	for(l=1;l<=n;l++)
	{
		if(out[l]!=out[2*n-l+1]) flag=1;
	}
	if(!flag)
	{
		for(int ki=1;ki<=2*n;ki++)
		{
			if(k[ki])  fout<<"R";
			else  fout<<"L";
		}
		fout<<endl;
		return 1;
	}
	return 0;
}
int hh(){
    for(int i=1;i<=10000000;i++)
    	    {
    	    	if(hui())  return 1;
			    an(2*n);
    	    	if(k[0]==1)
				{
					fout<<"-1"<<endl;
				    return 0;
				}
    	    }
}

int main()
{
    fff();
    fin>>T;
    for(int li=1;li<=T;li++)
    {
	    fin>>n;
	    for(int lii=1;lii<=2*n;lii++)  fin>>in[lii];
        hh();
    	for(int i=0;i<=60;i++)
    	{
    		k[i]=0;
		}
    } 
	fin.close();
        fout.close();   
}


