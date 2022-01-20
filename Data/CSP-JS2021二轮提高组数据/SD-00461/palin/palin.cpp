#include<bits/stdc++.h>
using namespace std;
namespace _mzf
{
	#define ll long long
	const ll N=5e5+100;
	ll tt,n,a[N],b[N],t,h;
	ll read()
	{
		ll flag=1,sum=0;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-') flag=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			sum=sum*10+ch-'0';
			ch=getchar();
		}
		return flag*sum;
	}
	int  s[N],c[N];
	bool check()
	{
		bool flag=0;
	/*for(int i=0;i<=2*n-1;i++)
		cout<<b[i]<<" ";
		cout<<endl;*/
		for(int i=0;i<=n;i++)
		if(b[i]!=b[n*2-i-1])
		{
			flag=1;
			break;
		}
		if(flag) return 0;
		else return 1;
	}
	void dfs(int x)
	{
		if(x==2*n)
		{
			int flag=0;
			if(check())
			{
				if(!s[0])
				{
					//cout<<s[0]<<"???"<<endl;
					for(int i=0;i<=2*n-1;i++)
					s[i]=c[i];
				/*	for(int i=0;i<=2*n-1;i++)
					cout<<(char)(s[i]+'A')<<" ";
					cout<<endl;*/
					return;
				}
				else 
				{
					for(int i=0;i<=2*n-1;i++)
					{
						if(c[i]<s[i]) 
						{
							flag=1;
							break;
						}
						if(c[i]>s[i]) break;
					}
					if(flag)
					for(int i=0;i<=2*n-1;i++)
					s[i]=c[i];
					return;
				}
			}
			else return;
		}
		for(int i=1;i<=2;i++)
		{
			if(i==1)
			{
				b[x]=a[h++];
				c[x]='L'-'A';
				dfs(x+1);
				c[x]=0;
				b[x]=0;
				h--;
			}
			else 
			{
				b[x]=a[--t];
				c[x]='R'-'A';
				if((s[x]!=0)&&(s[x]<c[x])) return;
				dfs(x+1);
				c[x]=0;
				b[x]=0;
				t++;
			}
		}
	}
	void work1()
	{
		dfs(0);
	}
	void mzfmain()
	{
		tt=read();
		int d=tt;
		while(tt--)
		{
			n=read();
			for(int i=0;i<=2*n-1;i++)
			b[i]=s[i]=c[i]=0;
			for(int i=0;i<=2*n-1;i++)
			a[i]=read();
			h=0;
			t=2*n;
			work1();
			if(s[0]!=0) 
			{
				for(int i=0;i<=2*n-1;i++)cout<<(char)(s[i]+'A');	
				cout<<endl;			
			}
			else cout<<-1<<endl;
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	_mzf::mzfmain();
	return 0;
}
