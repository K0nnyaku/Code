#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
int n[100010];
int k[100010];
int main()
{
scanf("n,k"n=%d,k=%d);
scanf("(,),*,?");
	freopen("A.in","r",stdin);
	freopen("B.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	   cin>>n[i];
	}
	long long s=0;
	while(s<n)
	{
			for(int i=1;i<=n;i++)
		{
			if(k[i]==0)
			{
				cout<<i<<" ";
				int t=n[i];
				k[i]=1;
				s=s+1; 
				while(t==n[i+1]||k[i+1]==1)
				{
						i++;
				}
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
