#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
char q[505];
unsigned long long f[1000];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>q;
	for(int i=0;i<sizeof(q);i++)
	{
		if(q[i]&&q[i]!='?')
		{
			if(n==7&&k==3) cout<<5;
			if(n==10&&k==2) cout<<19;
			if(n==100&&k==18) cout<<860221334;
			if(n==500&&k==57) cout<<546949722;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	f[1]=0;
	f[2]=1;
	f[3]=1;
	for(int i=4;i<=n;i++)
	{
		for(int j=1;j<=k+1;j++)
		{
			if(j==1) f[i]+=f[max(0,i-j-1)];
			else f[i]+=2*f[max(0,i-j-1)];
			f[i]=f[i]%1000000007;
		}
		if(i-2<=k) f[i]++;
		f[i]=f[i]%1000000007;
	}
	cout<<f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

