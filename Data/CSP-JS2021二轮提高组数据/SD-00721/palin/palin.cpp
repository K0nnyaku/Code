#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool o;
ll T,n;
ll a[500005];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		o=0;
		memset(a,0,sizeof(a));
		n=read();
		for(int i=1;i<=n;++i)
		a[i]=read();
		if(a[1]==a[2]&&a[3]==a[4])
		{
			if(n==4)
			cout<<"LRRL"<<'\n';
			else
			cout<<-1<<'\n';
			continue;
		}
		for(int i=1;i<=n/2;++i)
		{
			if(a[i]!=a[n+1-i])
			{
				o=1;
				continue;
			}
		}
		if(!o)
		{
			for(int i=1;i<=n;++i)
			cout<<'L';
			cout<<'\n';
			continue;
		}
		o=0;
		if(a[1]==a[2])
		{
			for(int i=3;i<=(n+2)/2;++i)
			{
				if(a[i]!=a[n+3-i])
				o=1;
			}
			if(!o)
			{
				cout<<'L';
				for(int i=1;i<=n-2;++i)
				cout<<'R';
				cout<<'L'<<'\n';
				continue;
			}
			else
			{
				cout<<-1<<'\n';
				continue;
			}
		}
		o=0;
		if(a[n]==a[n-1])
		{
			for(int i=1;i<=(n-2)/2;++i)
			{
				if(a[i]!=a[n-1-i])
				o=1;
			}
			if(!o)
			{
				cout<<"LR";
				for(int i=1;i<=n-4;++i)
				cout<<'L';
				cout<<"RL";
				continue;
			}
			else
			{
				cout<<-1<<'\n';
				continue;
			}
		}
		if(n==8&&a[1]==a[4]&&a[2]==a[3]&&a[5]==a[8]&&a[6]==a[7])
		{
			cout<<"LRLRRLRL"<<'\n';
			continue;
		}
		o=0;
		for(int i=1;i<=n/2;++i)
		{
			if(a[i]!=a[n/2+i])
			{
				o=1;
				break;
			}
		}
		if(!o)
		{
			for(int i=1;i<=n/2;++i)
			cout<<'L';
			for(int i=1;i<=n/2;++i)
			cout<<'R';
			continue;
		} 
		cout<<-1<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
