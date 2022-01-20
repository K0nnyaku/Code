#include<iostream>
#include<cstdio>
using namespace std;
int main()
{freopen("palin.in","r",stdin);
freopen("palin.out","w",stdout);
int T;
cin>>T;
for(int j=1;j<=T;j++)
{   int aj;
	cin>>aj;
	int numj[2*aj];
	for(int kj=0;kj<2*aj;kj++)
	{
		cin>>numj[kj];
		int m=1;
		int n=0;
		while(numj[n]-numj[m]==0)	
		{
			if((m-n)%2==0)
			cout<<-1;
			else
			{
				m++;
			}
			m++;
		}
	}
	}
return 0;
}
