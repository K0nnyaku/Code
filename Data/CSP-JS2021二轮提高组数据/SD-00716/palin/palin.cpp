#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long n,m;
unsigned long long A[500005],B[500005];
long long book;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
    cin>>m;
    long long p=0;
	long long i=0,j=0;
	long long all=0;
	for(i=1;i<=m;i++)
	{
		cin>>n;
		long long x=1,y=2*n;
		for(j=1;j<=2*n;j++)
		{
			cin>>A[j];	
		}
		while(x<y)
		{
			if(A[x]==A[y])
			{
				all++;
				x++;
				y--;
			}
		}
		if(all==n)
		{
			for(long long u=1;u<=2*n;u++)
			{
				cout<<"L";
			}
		}
	}	

	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
