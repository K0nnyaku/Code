#include<iostream>
#include<cstdio>
#define MAXN 500010
using namespace std;
int T,n;
int flag,ans;
int a[MAXN<<1];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[2*n+1-i])
			{
				ans=-1;
				flag=1;
			}
		}
		if(flag)
		{
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cout<<'L';
			}
			for(int i=1;i<=n;i++)
			{
				cout<<'R';
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
