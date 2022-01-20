#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[500050],aa[500050],b[500050],flag=0,al,bl,ar;
char c[500050],cc[500050];
void dfs(int num,int have)
{
	if(have<=num)
	{
		c[have]='L';
		b[have]=aa[have];
		aa[al]=0;
		al++;
		dfs(num,have+1);
		al--;
		aa[al]=a[al];
/*-----------------------------------------------------------------------------------------------------------*/
		c[have]='R';
		b[have]=aa[have];
		aa[ar]=0;
		ar--;
		dfs(num,have+1);
		ar++;
		aa[ar]=a[ar];
	}
	else
	{
		int dfsflag=1;
		for(int i=1;i<=num;i++)
		{
			if(b[i]!=b[num-i+1])
			{
				dfsflag=0;
				break;
			}
		}
		if(dfsflag==1)
		{
			flag=1;
			dfsflag=0;
			for(int i=1;i<=num;i++)
			{
				if(dfsflag==1||(cc[i]=='R'&&c[i]=='L'))
				{
					dfsflag=1;
					cc[i]=c[i];
				}
			}
		}
	}
}
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int lll=1;lll<=t;lll++)
	{
		memset(a,0,sizeof(a));
		memset(aa,0,sizeof(aa));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cc[i]='R';
		}
		flag=0;
		al=1;
		bl=1;
		ar=n;
		dfs(n,1);
		if(flag==0)
		{
			cout<<-1<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cout<<cc[i];
			}
			cout<<endl;
		}
	}
	return 0;
}

